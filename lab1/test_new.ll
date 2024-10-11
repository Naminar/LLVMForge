; ModuleID = 'new_app.c'
source_filename = "new_app.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nounwind uwtable
define dso_local void @app() local_unnamed_addr #0 {
  %1 = alloca [50 x i32], align 16
  %2 = alloca [50 x i32], align 16
  %3 = bitcast [50 x i32]* %1 to i8*
  call void @llvm.lifetime.start.p0i8(i64 200, i8* nonnull %3) #4
  call void @llvm.memset.p0i8.i64(i8* noundef nonnull align 16 dereferenceable(200) %3, i8 0, i64 200, i1 false)
  %4 = bitcast [50 x i32]* %2 to i8*
  call void @llvm.lifetime.start.p0i8(i64 200, i8* nonnull %4) #4
  call void @llvm.memset.p0i8.i64(i8* noundef nonnull align 16 dereferenceable(200) %4, i8 0, i64 200, i1 false)
  br label %5

5:                                                ; preds = %0, %5
  %6 = phi i64 [ 0, %0 ], [ %13, %5 ]
  %7 = tail call i32 (...) @simRand() #4
  %8 = srem i32 %7, 1024
  %9 = getelementptr inbounds [50 x i32], [50 x i32]* %1, i64 0, i64 %6
  store i32 %8, i32* %9, align 4, !tbaa !5
  %10 = tail call i32 (...) @simRand() #4
  %11 = srem i32 %10, 512
  %12 = getelementptr inbounds [50 x i32], [50 x i32]* %2, i64 0, i64 %6
  store i32 %11, i32* %12, align 4, !tbaa !5
  %13 = add nuw nsw i64 %6, 1
  %14 = icmp eq i64 %13, 50
  br i1 %14, label %16, label %5, !llvm.loop !9

15:                                               ; preds = %63
  call void @llvm.lifetime.end.p0i8(i64 200, i8* nonnull %4) #4
  call void @llvm.lifetime.end.p0i8(i64 200, i8* nonnull %3) #4
  ret void

16:                                               ; preds = %5, %63
  %17 = phi i64 [ %64, %63 ], [ 0, %5 ]
  %18 = getelementptr inbounds [50 x i32], [50 x i32]* %1, i64 0, i64 %17
  %19 = load i32, i32* %18, align 4, !tbaa !5
  %20 = icmp sgt i32 %19, 0
  br i1 %20, label %21, label %32

21:                                               ; preds = %16
  %22 = getelementptr inbounds [50 x i32], [50 x i32]* %2, i64 0, i64 %17
  %23 = load i32, i32* %22, align 4, !tbaa !5
  %24 = trunc i64 %17 to i32
  %25 = mul i32 %24, 25
  %26 = add i32 %25, -65536
  br label %38

27:                                               ; preds = %38
  %28 = icmp slt i32 %19, 1024
  br i1 %28, label %32, label %29

29:                                               ; preds = %27
  %30 = getelementptr inbounds [50 x i32], [50 x i32]* %2, i64 0, i64 %17
  %31 = load i32, i32* %30, align 4, !tbaa !5
  br label %42

32:                                               ; preds = %16, %27
  %33 = getelementptr inbounds [50 x i32], [50 x i32]* %2, i64 0, i64 %17
  %34 = load i32, i32* %33, align 4, !tbaa !5
  %35 = trunc i64 %17 to i32
  %36 = mul i32 %35, 25
  %37 = add i32 %36, -65536
  br label %49

38:                                               ; preds = %21, %38
  %39 = phi i32 [ %19, %21 ], [ %40, %38 ]
  tail call void @simPutPixel(i32 noundef %39, i32 noundef %23, i32 noundef %26) #4
  %40 = add nsw i32 %39, -1
  %41 = icmp ugt i32 %39, 1
  br i1 %41, label %38, label %27, !llvm.loop !11

42:                                               ; preds = %49, %29
  %43 = phi i32 [ %31, %29 ], [ %34, %49 ]
  %44 = icmp slt i32 %43, 512
  br i1 %44, label %45, label %55

45:                                               ; preds = %42
  %46 = trunc i64 %17 to i32
  %47 = mul i32 %46, 25
  %48 = add i32 %47, -65536
  br label %59

49:                                               ; preds = %32, %49
  %50 = phi i32 [ %19, %32 ], [ %51, %49 ]
  tail call void @simPutPixel(i32 noundef %50, i32 noundef %34, i32 noundef %37) #4
  %51 = add i32 %50, 1
  %52 = icmp eq i32 %51, 1024
  br i1 %52, label %42, label %49, !llvm.loop !12

53:                                               ; preds = %59
  %54 = icmp sgt i32 %43, 0
  br i1 %54, label %55, label %63

55:                                               ; preds = %42, %53
  %56 = trunc i64 %17 to i32
  %57 = mul i32 %56, 25
  %58 = add i32 %57, -65536
  br label %66

59:                                               ; preds = %45, %59
  %60 = phi i32 [ %43, %45 ], [ %61, %59 ]
  tail call void @simPutPixel(i32 noundef %19, i32 noundef %60, i32 noundef %48) #4
  %61 = add i32 %60, 1
  %62 = icmp eq i32 %61, 512
  br i1 %62, label %53, label %59, !llvm.loop !13

63:                                               ; preds = %66, %53
  tail call void (...) @simFlush() #4
  %64 = add nuw nsw i64 %17, 1
  %65 = icmp eq i64 %64, 50
  br i1 %65, label %15, label %16, !llvm.loop !14

66:                                               ; preds = %55, %66
  %67 = phi i32 [ %43, %55 ], [ %68, %66 ]
  tail call void @simPutPixel(i32 noundef %19, i32 noundef %67, i32 noundef %58) #4
  %68 = add nsw i32 %67, -1
  %69 = icmp ugt i32 %67, 1
  br i1 %69, label %66, label %63, !llvm.loop !15
}

; Function Attrs: argmemonly mustprogress nofree nosync nounwind willreturn
declare void @llvm.lifetime.start.p0i8(i64 immarg, i8* nocapture) #1

; Function Attrs: argmemonly mustprogress nofree nounwind willreturn writeonly
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #2

declare i32 @simRand(...) local_unnamed_addr #3

; Function Attrs: argmemonly mustprogress nofree nosync nounwind willreturn
declare void @llvm.lifetime.end.p0i8(i64 immarg, i8* nocapture) #1

declare void @simPutPixel(i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #3

declare void @simFlush(...) local_unnamed_addr #3

attributes #0 = { nounwind uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { argmemonly mustprogress nofree nosync nounwind willreturn }
attributes #2 = { argmemonly mustprogress nofree nounwind willreturn writeonly }
attributes #3 = { "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!5 = !{!6, !6, i64 0}
!6 = !{!"int", !7, i64 0}
!7 = !{!"omnipotent char", !8, i64 0}
!8 = !{!"Simple C/C++ TBAA"}
!9 = distinct !{!9, !10}
!10 = !{!"llvm.loop.mustprogress"}
!11 = distinct !{!11, !10}
!12 = distinct !{!12, !10}
!13 = distinct !{!13, !10}
!14 = distinct !{!14, !10}
!15 = distinct !{!15, !10}
