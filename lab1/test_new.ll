; ModuleID = 'new_app.c'
source_filename = "new_app.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nounwind uwtable
define dso_local void @app() local_unnamed_addr #0 {
  %1 = tail call i32 (...) @simRand() #2
  %2 = srem i32 %1, 1024
  %3 = tail call i32 (...) @simRand() #2
  %4 = srem i32 %3, 512
  %5 = tail call i32 (...) @simRand() #2
  %6 = tail call i32 (...) @simRand() #2
  %7 = srem i32 %6, 1024
  %8 = tail call i32 (...) @simRand() #2
  %9 = srem i32 %8, 4056
  %10 = tail call i32 (...) @simRand() #2
  %11 = srem i32 %10, 4056
  %12 = icmp sgt i32 %2, 0
  br i1 %12, label %13, label %16

13:                                               ; preds = %0
  %14 = srem i32 %5, 1024
  %15 = add nsw i32 %14, 16
  br label %18

16:                                               ; preds = %18, %0
  %17 = add nsw i32 %7, 16
  br label %26

18:                                               ; preds = %13, %18
  %19 = phi i32 [ %2, %13 ], [ %22, %18 ]
  %20 = mul nsw i32 %19, %15
  %21 = add nsw i32 %20, 65535
  tail call void @simPutPixel(i32 noundef %19, i32 noundef %4, i32 noundef %21) #2
  tail call void (...) @simFlush() #2
  %22 = add nsw i32 %19, -1
  %23 = icmp ugt i32 %19, 1
  br i1 %23, label %18, label %16, !llvm.loop !5

24:                                               ; preds = %26
  %25 = add nsw i32 %9, 16
  br label %36

26:                                               ; preds = %16, %26
  %27 = phi i32 [ %2, %16 ], [ %30, %26 ]
  %28 = mul nsw i32 %27, %17
  %29 = add nsw i32 %28, 65535
  tail call void @simPutPixel(i32 noundef %27, i32 noundef %4, i32 noundef %29) #2
  tail call void (...) @simFlush() #2
  %30 = add nsw i32 %27, 1
  %31 = icmp eq i32 %30, 1024
  br i1 %31, label %24, label %26, !llvm.loop !7

32:                                               ; preds = %36
  %33 = icmp sgt i32 %4, 0
  br i1 %33, label %34, label %42

34:                                               ; preds = %32
  %35 = add nsw i32 %11, 16
  br label %43

36:                                               ; preds = %24, %36
  %37 = phi i32 [ %4, %24 ], [ %40, %36 ]
  %38 = mul nsw i32 %37, %25
  %39 = add nsw i32 %38, 65535
  tail call void @simPutPixel(i32 noundef %2, i32 noundef %37, i32 noundef %39) #2
  tail call void (...) @simFlush() #2
  %40 = add nsw i32 %37, 1
  %41 = icmp eq i32 %40, 512
  br i1 %41, label %32, label %36, !llvm.loop !8

42:                                               ; preds = %43, %32
  ret void

43:                                               ; preds = %34, %43
  %44 = phi i32 [ %4, %34 ], [ %47, %43 ]
  %45 = mul nsw i32 %44, %35
  %46 = add nsw i32 %45, 65535
  tail call void @simPutPixel(i32 noundef %2, i32 noundef %44, i32 noundef %46) #2
  tail call void (...) @simFlush() #2
  %47 = add nsw i32 %44, -1
  %48 = icmp ugt i32 %44, 1
  br i1 %48, label %43, label %42, !llvm.loop !9
}

declare i32 @simRand(...) local_unnamed_addr #1

declare void @simPutPixel(i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #1

declare void @simFlush(...) local_unnamed_addr #1

attributes #0 = { nounwind uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!5 = distinct !{!5, !6}
!6 = !{!"llvm.loop.mustprogress"}
!7 = distinct !{!7, !6}
!8 = distinct !{!8, !6}
!9 = distinct !{!9, !6}
