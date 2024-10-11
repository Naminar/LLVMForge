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
  %5 = icmp sgt i32 %2, 0
  br i1 %5, label %6, label %10

6:                                                ; preds = %0, %6
  %7 = phi i32 [ %8, %6 ], [ %2, %0 ]
  tail call void @simPutPixel(i32 noundef %7, i32 noundef %4, i32 noundef -65536) #2
  tail call void (...) @simFlush() #2
  %8 = add nsw i32 %7, -1
  %9 = icmp ugt i32 %7, 1
  br i1 %9, label %6, label %10, !llvm.loop !5

10:                                               ; preds = %6, %0
  br label %11

11:                                               ; preds = %10, %11
  %12 = phi i32 [ %13, %11 ], [ %2, %10 ]
  tail call void @simPutPixel(i32 noundef %12, i32 noundef %4, i32 noundef -65536) #2
  tail call void (...) @simFlush() #2
  %13 = add nsw i32 %12, 1
  %14 = icmp eq i32 %13, 1024
  br i1 %14, label %17, label %11, !llvm.loop !7

15:                                               ; preds = %17
  %16 = icmp sgt i32 %4, 0
  br i1 %16, label %22, label %21

17:                                               ; preds = %11, %17
  %18 = phi i32 [ %19, %17 ], [ %4, %11 ]
  tail call void @simPutPixel(i32 noundef %2, i32 noundef %18, i32 noundef -65536) #2
  tail call void (...) @simFlush() #2
  %19 = add nsw i32 %18, 1
  %20 = icmp eq i32 %19, 512
  br i1 %20, label %15, label %17, !llvm.loop !8

21:                                               ; preds = %22, %15
  ret void

22:                                               ; preds = %15, %22
  %23 = phi i32 [ %24, %22 ], [ %4, %15 ]
  tail call void @simPutPixel(i32 noundef %2, i32 noundef %23, i32 noundef -65536) #2
  tail call void (...) @simFlush() #2
  %24 = add nsw i32 %23, -1
  %25 = icmp ugt i32 %23, 1
  br i1 %25, label %22, label %21, !llvm.loop !9
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
