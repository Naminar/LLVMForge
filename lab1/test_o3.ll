; ModuleID = 'app.c'
source_filename = "app.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nounwind uwtable
define dso_local void @delta(i32 noundef %0, i32 noundef %1) local_unnamed_addr #0 {
  %3 = icmp sgt i32 %0, 0
  br i1 %3, label %4, label %8

4:                                                ; preds = %2
  %5 = add nsw i32 %0, -2
  br label %10

6:                                                ; preds = %10
  %7 = icmp slt i32 %0, 1024
  br i1 %7, label %8, label %16

8:                                                ; preds = %2, %6
  %9 = add nsw i32 %0, 2
  br label %20

10:                                               ; preds = %4, %10
  %11 = phi i32 [ %12, %10 ], [ %0, %4 ]
  tail call void @simPutPixel(i32 noundef %11, i32 noundef %1, i32 noundef -16711936) #4
  %12 = add nsw i32 %11, -1
  %13 = icmp ugt i32 %11, 1
  %14 = icmp sgt i32 %11, %5
  %15 = select i1 %13, i1 %14, i1 false
  br i1 %15, label %10, label %6, !llvm.loop !5

16:                                               ; preds = %20, %6
  %17 = icmp slt i32 %1, 512
  br i1 %17, label %18, label %28

18:                                               ; preds = %16
  %19 = add nsw i32 %1, 2
  br label %30

20:                                               ; preds = %8, %20
  %21 = phi i32 [ %22, %20 ], [ %0, %8 ]
  tail call void @simPutPixel(i32 noundef %21, i32 noundef %1, i32 noundef -16711936) #4
  %22 = add nsw i32 %21, 1
  %23 = icmp slt i32 %21, 1023
  %24 = icmp slt i32 %21, %9
  %25 = select i1 %23, i1 %24, i1 false
  br i1 %25, label %20, label %16, !llvm.loop !7

26:                                               ; preds = %30
  %27 = icmp sgt i32 %1, 0
  br i1 %27, label %28, label %36

28:                                               ; preds = %16, %26
  %29 = add nsw i32 %1, -2
  br label %37

30:                                               ; preds = %18, %30
  %31 = phi i32 [ %32, %30 ], [ %1, %18 ]
  tail call void @simPutPixel(i32 noundef %0, i32 noundef %31, i32 noundef -16711936) #4
  %32 = add nsw i32 %31, 1
  %33 = icmp slt i32 %31, 511
  %34 = icmp slt i32 %31, %19
  %35 = select i1 %33, i1 %34, i1 false
  br i1 %35, label %30, label %26, !llvm.loop !8

36:                                               ; preds = %37, %26
  ret void

37:                                               ; preds = %28, %37
  %38 = phi i32 [ %39, %37 ], [ %1, %28 ]
  tail call void @simPutPixel(i32 noundef %0, i32 noundef %38, i32 noundef -16711936) #4
  %39 = add nsw i32 %38, -1
  %40 = icmp ugt i32 %38, 1
  %41 = icmp sgt i32 %38, %29
  %42 = select i1 %40, i1 %41, i1 false
  br i1 %42, label %37, label %36, !llvm.loop !9
}

; Function Attrs: argmemonly mustprogress nofree nosync nounwind willreturn
declare void @llvm.lifetime.start.p0i8(i64 immarg, i8* nocapture) #1

declare void @simPutPixel(i32 noundef, i32 noundef, i32 noundef) local_unnamed_addr #2

; Function Attrs: argmemonly mustprogress nofree nosync nounwind willreturn
declare void @llvm.lifetime.end.p0i8(i64 immarg, i8* nocapture) #1

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
  store i32 %8, i32* %9, align 4, !tbaa !10
  %10 = tail call i32 (...) @simRand() #4
  %11 = srem i32 %10, 512
  %12 = getelementptr inbounds [50 x i32], [50 x i32]* %2, i64 0, i64 %6
  store i32 %11, i32* %12, align 4, !tbaa !10
  %13 = add nuw nsw i64 %6, 1
  %14 = icmp eq i64 %13, 50
  br i1 %14, label %15, label %5, !llvm.loop !14

15:                                               ; preds = %5, %62
  %16 = phi i64 [ %63, %62 ], [ 0, %5 ]
  %17 = getelementptr inbounds [50 x i32], [50 x i32]* %1, i64 0, i64 %16
  %18 = load i32, i32* %17, align 4, !tbaa !10
  %19 = icmp sgt i32 %18, 0
  br i1 %19, label %20, label %31

20:                                               ; preds = %15
  %21 = getelementptr inbounds [50 x i32], [50 x i32]* %2, i64 0, i64 %16
  %22 = load i32, i32* %21, align 4, !tbaa !10
  %23 = trunc i64 %16 to i32
  %24 = mul i32 %23, 25
  %25 = add i32 %24, -65536
  br label %37

26:                                               ; preds = %37
  %27 = icmp slt i32 %18, 1024
  br i1 %27, label %31, label %28

28:                                               ; preds = %26
  %29 = getelementptr inbounds [50 x i32], [50 x i32]* %2, i64 0, i64 %16
  %30 = load i32, i32* %29, align 4, !tbaa !10
  br label %41

31:                                               ; preds = %15, %26
  %32 = getelementptr inbounds [50 x i32], [50 x i32]* %2, i64 0, i64 %16
  %33 = load i32, i32* %32, align 4, !tbaa !10
  %34 = trunc i64 %16 to i32
  %35 = mul i32 %34, 25
  %36 = add i32 %35, -65536
  br label %48

37:                                               ; preds = %20, %37
  %38 = phi i32 [ %18, %20 ], [ %39, %37 ]
  tail call void @simPutPixel(i32 noundef %38, i32 noundef %22, i32 noundef %25) #4
  %39 = add nsw i32 %38, -1
  %40 = icmp ugt i32 %38, 1
  br i1 %40, label %37, label %26, !llvm.loop !15

41:                                               ; preds = %48, %28
  %42 = phi i32 [ %30, %28 ], [ %33, %48 ]
  %43 = icmp slt i32 %42, 512
  br i1 %43, label %44, label %54

44:                                               ; preds = %41
  %45 = trunc i64 %16 to i32
  %46 = mul i32 %45, 25
  %47 = add i32 %46, -65536
  br label %58

48:                                               ; preds = %31, %48
  %49 = phi i32 [ %18, %31 ], [ %50, %48 ]
  tail call void @simPutPixel(i32 noundef %49, i32 noundef %33, i32 noundef %36) #4
  %50 = add i32 %49, 1
  %51 = icmp eq i32 %50, 1024
  br i1 %51, label %41, label %48, !llvm.loop !16

52:                                               ; preds = %58
  %53 = icmp sgt i32 %42, 0
  br i1 %53, label %54, label %62

54:                                               ; preds = %41, %52
  %55 = trunc i64 %16 to i32
  %56 = mul i32 %55, 25
  %57 = add i32 %56, -65536
  br label %65

58:                                               ; preds = %44, %58
  %59 = phi i32 [ %42, %44 ], [ %60, %58 ]
  tail call void @simPutPixel(i32 noundef %18, i32 noundef %59, i32 noundef %47) #4
  %60 = add i32 %59, 1
  %61 = icmp eq i32 %60, 512
  br i1 %61, label %52, label %58, !llvm.loop !17

62:                                               ; preds = %65, %52
  tail call void (...) @simFlush() #4
  %63 = add nuw nsw i64 %16, 1
  %64 = icmp eq i64 %63, 50
  br i1 %64, label %70, label %15, !llvm.loop !18

65:                                               ; preds = %54, %65
  %66 = phi i32 [ %42, %54 ], [ %67, %65 ]
  tail call void @simPutPixel(i32 noundef %18, i32 noundef %66, i32 noundef %57) #4
  %67 = add nsw i32 %66, -1
  %68 = icmp ugt i32 %66, 1
  br i1 %68, label %65, label %62, !llvm.loop !19

69:                                               ; preds = %88
  call void @llvm.lifetime.end.p0i8(i64 200, i8* nonnull %4) #4
  call void @llvm.lifetime.end.p0i8(i64 200, i8* nonnull %3) #4
  ret void

70:                                               ; preds = %62, %88
  %71 = phi i64 [ %73, %88 ], [ 0, %62 ]
  %72 = phi i64 [ %89, %88 ], [ 1, %62 ]
  %73 = add nuw nsw i64 %71, 1
  %74 = icmp ult i64 %71, 49
  br i1 %74, label %75, label %88

75:                                               ; preds = %70
  %76 = getelementptr inbounds [50 x i32], [50 x i32]* %2, i64 0, i64 %71
  %77 = load i32, i32* %76, align 4, !tbaa !10
  %78 = getelementptr inbounds [50 x i32], [50 x i32]* %1, i64 0, i64 %71
  %79 = load i32, i32* %78, align 4, !tbaa !10
  %80 = icmp slt i32 %77, 512
  %81 = add nsw i32 %77, 2
  %82 = icmp sgt i32 %77, 0
  %83 = add nsw i32 %77, -2
  %84 = icmp sgt i32 %79, 0
  %85 = add nsw i32 %79, -2
  %86 = icmp slt i32 %79, 1024
  %87 = add nsw i32 %79, 2
  br label %91

88:                                               ; preds = %166, %70
  tail call void (...) @simFlush() #4
  %89 = add nuw nsw i64 %72, 1
  %90 = icmp eq i64 %73, 50
  br i1 %90, label %69, label %70, !llvm.loop !20

91:                                               ; preds = %75, %166
  %92 = phi i64 [ %72, %75 ], [ %167, %166 ]
  %93 = getelementptr inbounds [50 x i32], [50 x i32]* %1, i64 0, i64 %92
  %94 = load i32, i32* %93, align 4, !tbaa !10
  %95 = getelementptr inbounds [50 x i32], [50 x i32]* %2, i64 0, i64 %92
  %96 = load i32, i32* %95, align 4, !tbaa !10
  %97 = icmp sgt i32 %94, 0
  br i1 %97, label %98, label %102

98:                                               ; preds = %91
  %99 = add nsw i32 %94, -2
  br label %104

100:                                              ; preds = %104
  %101 = icmp slt i32 %94, 1024
  br i1 %101, label %102, label %110

102:                                              ; preds = %100, %91
  %103 = add nsw i32 %94, 2
  br label %112

104:                                              ; preds = %104, %98
  %105 = phi i32 [ %106, %104 ], [ %94, %98 ]
  tail call void @simPutPixel(i32 noundef %105, i32 noundef %77, i32 noundef -16711936) #4
  %106 = add nsw i32 %105, -1
  %107 = icmp ugt i32 %105, 1
  %108 = icmp sgt i32 %105, %99
  %109 = select i1 %107, i1 %108, i1 false
  br i1 %109, label %104, label %100, !llvm.loop !5

110:                                              ; preds = %112, %100
  br i1 %80, label %119, label %111

111:                                              ; preds = %118, %110
  br label %125

112:                                              ; preds = %112, %102
  %113 = phi i32 [ %114, %112 ], [ %94, %102 ]
  tail call void @simPutPixel(i32 noundef %113, i32 noundef %77, i32 noundef -16711936) #4
  %114 = add nsw i32 %113, 1
  %115 = icmp slt i32 %113, 1023
  %116 = icmp slt i32 %113, %103
  %117 = select i1 %115, i1 %116, i1 false
  br i1 %117, label %112, label %110, !llvm.loop !7

118:                                              ; preds = %119
  br i1 %82, label %111, label %131

119:                                              ; preds = %110, %119
  %120 = phi i32 [ %121, %119 ], [ %77, %110 ]
  tail call void @simPutPixel(i32 noundef %94, i32 noundef %120, i32 noundef -16711936) #4
  %121 = add nsw i32 %120, 1
  %122 = icmp slt i32 %120, 511
  %123 = icmp slt i32 %120, %81
  %124 = select i1 %122, i1 %123, i1 false
  br i1 %124, label %119, label %118, !llvm.loop !8

125:                                              ; preds = %111, %125
  %126 = phi i32 [ %127, %125 ], [ %77, %111 ]
  tail call void @simPutPixel(i32 noundef %94, i32 noundef %126, i32 noundef -16711936) #4
  %127 = add nsw i32 %126, -1
  %128 = icmp ugt i32 %126, 1
  %129 = icmp sgt i32 %126, %83
  %130 = select i1 %128, i1 %129, i1 false
  br i1 %130, label %125, label %131, !llvm.loop !9

131:                                              ; preds = %125, %118
  br i1 %84, label %134, label %132

132:                                              ; preds = %133, %131
  br label %144

133:                                              ; preds = %134
  br i1 %86, label %132, label %140

134:                                              ; preds = %131, %134
  %135 = phi i32 [ %136, %134 ], [ %79, %131 ]
  tail call void @simPutPixel(i32 noundef %135, i32 noundef %96, i32 noundef -16711936) #4
  %136 = add nsw i32 %135, -1
  %137 = icmp ugt i32 %135, 1
  %138 = icmp sgt i32 %135, %85
  %139 = select i1 %137, i1 %138, i1 false
  br i1 %139, label %134, label %133, !llvm.loop !5

140:                                              ; preds = %144, %133
  %141 = icmp slt i32 %96, 512
  br i1 %141, label %142, label %152

142:                                              ; preds = %140
  %143 = add nsw i32 %96, 2
  br label %154

144:                                              ; preds = %132, %144
  %145 = phi i32 [ %146, %144 ], [ %79, %132 ]
  tail call void @simPutPixel(i32 noundef %145, i32 noundef %96, i32 noundef -16711936) #4
  %146 = add nsw i32 %145, 1
  %147 = icmp slt i32 %145, 1023
  %148 = icmp slt i32 %145, %87
  %149 = select i1 %147, i1 %148, i1 false
  br i1 %149, label %144, label %140, !llvm.loop !7

150:                                              ; preds = %154
  %151 = icmp sgt i32 %96, 0
  br i1 %151, label %152, label %166

152:                                              ; preds = %150, %140
  %153 = add nsw i32 %96, -2
  br label %160

154:                                              ; preds = %154, %142
  %155 = phi i32 [ %156, %154 ], [ %96, %142 ]
  tail call void @simPutPixel(i32 noundef %79, i32 noundef %155, i32 noundef -16711936) #4
  %156 = add nsw i32 %155, 1
  %157 = icmp slt i32 %155, 511
  %158 = icmp slt i32 %155, %143
  %159 = select i1 %157, i1 %158, i1 false
  br i1 %159, label %154, label %150, !llvm.loop !8

160:                                              ; preds = %160, %152
  %161 = phi i32 [ %162, %160 ], [ %96, %152 ]
  tail call void @simPutPixel(i32 noundef %79, i32 noundef %161, i32 noundef -16711936) #4
  %162 = add nsw i32 %161, -1
  %163 = icmp ugt i32 %161, 1
  %164 = icmp sgt i32 %161, %153
  %165 = select i1 %163, i1 %164, i1 false
  br i1 %165, label %160, label %166, !llvm.loop !9

166:                                              ; preds = %160, %150
  %167 = add nuw nsw i64 %92, 1
  %168 = icmp eq i64 %167, 50
  br i1 %168, label %88, label %91, !llvm.loop !21
}

; Function Attrs: argmemonly mustprogress nofree nounwind willreturn writeonly
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #3

declare i32 @simRand(...) local_unnamed_addr #2

declare void @simFlush(...) local_unnamed_addr #2

attributes #0 = { nounwind uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { argmemonly mustprogress nofree nosync nounwind willreturn }
attributes #2 = { "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { argmemonly mustprogress nofree nounwind willreturn writeonly }
attributes #4 = { nounwind }

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
!10 = !{!11, !11, i64 0}
!11 = !{!"int", !12, i64 0}
!12 = !{!"omnipotent char", !13, i64 0}
!13 = !{!"Simple C/C++ TBAA"}
!14 = distinct !{!14, !6}
!15 = distinct !{!15, !6}
!16 = distinct !{!16, !6}
!17 = distinct !{!17, !6}
!18 = distinct !{!18, !6}
!19 = distinct !{!19, !6}
!20 = distinct !{!20, !6}
!21 = distinct !{!21, !6}
