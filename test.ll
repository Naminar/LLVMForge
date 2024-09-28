; ModuleID = 'app.c'
source_filename = "app.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @delta(i32 noundef %0, i32 noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  store i32 %1, i32* %4, align 4
  store i32 -16711936, i32* %5, align 4
  store i32 3, i32* %6, align 4
  %11 = load i32, i32* %3, align 4
  store i32 %11, i32* %7, align 4
  br label %12

12:                                               ; preds = %27, %2
  %13 = load i32, i32* %7, align 4
  %14 = icmp sgt i32 %13, 0
  br i1 %14, label %15, label %21

15:                                               ; preds = %12
  %16 = load i32, i32* %7, align 4
  %17 = load i32, i32* %3, align 4
  %18 = load i32, i32* %6, align 4
  %19 = sub nsw i32 %17, %18
  %20 = icmp sgt i32 %16, %19
  br label %21

21:                                               ; preds = %15, %12
  %22 = phi i1 [ false, %12 ], [ %20, %15 ]
  br i1 %22, label %23, label %30

23:                                               ; preds = %21
  %24 = load i32, i32* %7, align 4
  %25 = load i32, i32* %4, align 4
  %26 = load i32, i32* %5, align 4
  call void @simPutPixel(i32 noundef %24, i32 noundef %25, i32 noundef %26)
  br label %27

27:                                               ; preds = %23
  %28 = load i32, i32* %7, align 4
  %29 = add nsw i32 %28, -1
  store i32 %29, i32* %7, align 4
  br label %12, !llvm.loop !6

30:                                               ; preds = %21
  %31 = load i32, i32* %3, align 4
  store i32 %31, i32* %8, align 4
  br label %32

32:                                               ; preds = %47, %30
  %33 = load i32, i32* %8, align 4
  %34 = icmp slt i32 %33, 1024
  br i1 %34, label %35, label %41

35:                                               ; preds = %32
  %36 = load i32, i32* %8, align 4
  %37 = load i32, i32* %3, align 4
  %38 = load i32, i32* %6, align 4
  %39 = add nsw i32 %37, %38
  %40 = icmp slt i32 %36, %39
  br label %41

41:                                               ; preds = %35, %32
  %42 = phi i1 [ false, %32 ], [ %40, %35 ]
  br i1 %42, label %43, label %50

43:                                               ; preds = %41
  %44 = load i32, i32* %8, align 4
  %45 = load i32, i32* %4, align 4
  %46 = load i32, i32* %5, align 4
  call void @simPutPixel(i32 noundef %44, i32 noundef %45, i32 noundef %46)
  br label %47

47:                                               ; preds = %43
  %48 = load i32, i32* %8, align 4
  %49 = add nsw i32 %48, 1
  store i32 %49, i32* %8, align 4
  br label %32, !llvm.loop !8

50:                                               ; preds = %41
  %51 = load i32, i32* %4, align 4
  store i32 %51, i32* %9, align 4
  br label %52

52:                                               ; preds = %67, %50
  %53 = load i32, i32* %9, align 4
  %54 = icmp slt i32 %53, 512
  br i1 %54, label %55, label %61

55:                                               ; preds = %52
  %56 = load i32, i32* %9, align 4
  %57 = load i32, i32* %4, align 4
  %58 = load i32, i32* %6, align 4
  %59 = add nsw i32 %57, %58
  %60 = icmp slt i32 %56, %59
  br label %61

61:                                               ; preds = %55, %52
  %62 = phi i1 [ false, %52 ], [ %60, %55 ]
  br i1 %62, label %63, label %70

63:                                               ; preds = %61
  %64 = load i32, i32* %3, align 4
  %65 = load i32, i32* %9, align 4
  %66 = load i32, i32* %5, align 4
  call void @simPutPixel(i32 noundef %64, i32 noundef %65, i32 noundef %66)
  br label %67

67:                                               ; preds = %63
  %68 = load i32, i32* %9, align 4
  %69 = add nsw i32 %68, 1
  store i32 %69, i32* %9, align 4
  br label %52, !llvm.loop !9

70:                                               ; preds = %61
  %71 = load i32, i32* %4, align 4
  store i32 %71, i32* %10, align 4
  br label %72

72:                                               ; preds = %87, %70
  %73 = load i32, i32* %10, align 4
  %74 = icmp sgt i32 %73, 0
  br i1 %74, label %75, label %81

75:                                               ; preds = %72
  %76 = load i32, i32* %10, align 4
  %77 = load i32, i32* %4, align 4
  %78 = load i32, i32* %6, align 4
  %79 = sub nsw i32 %77, %78
  %80 = icmp sgt i32 %76, %79
  br label %81

81:                                               ; preds = %75, %72
  %82 = phi i1 [ false, %72 ], [ %80, %75 ]
  br i1 %82, label %83, label %90

83:                                               ; preds = %81
  %84 = load i32, i32* %3, align 4
  %85 = load i32, i32* %10, align 4
  %86 = load i32, i32* %5, align 4
  call void @simPutPixel(i32 noundef %84, i32 noundef %85, i32 noundef %86)
  br label %87

87:                                               ; preds = %83
  %88 = load i32, i32* %10, align 4
  %89 = add nsw i32 %88, -1
  store i32 %89, i32* %10, align 4
  br label %72, !llvm.loop !10

90:                                               ; preds = %81
  ret void
}

declare void @simPutPixel(i32 noundef, i32 noundef, i32 noundef) #1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @app() #0 {
  %1 = alloca [20 x i32], align 16
  %2 = alloca [20 x i32], align 16
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  %13 = alloca i32, align 4
  %14 = alloca i32, align 4
  %15 = alloca i32, align 4
  %16 = bitcast [20 x i32]* %1 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %16, i8 0, i64 80, i1 false)
  %17 = bitcast [20 x i32]* %2 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 16 %17, i8 0, i64 80, i1 false)
  store i32 0, i32* %3, align 4
  store i32 0, i32* %8, align 4
  br label %18

18:                                               ; preds = %32, %0
  %19 = load i32, i32* %8, align 4
  %20 = icmp slt i32 %19, 20
  br i1 %20, label %21, label %35

21:                                               ; preds = %18
  %22 = call i32 (...) @simRand()
  %23 = srem i32 %22, 1024
  %24 = load i32, i32* %8, align 4
  %25 = sext i32 %24 to i64
  %26 = getelementptr inbounds [20 x i32], [20 x i32]* %1, i64 0, i64 %25
  store i32 %23, i32* %26, align 4
  %27 = call i32 (...) @simRand()
  %28 = srem i32 %27, 512
  %29 = load i32, i32* %8, align 4
  %30 = sext i32 %29 to i64
  %31 = getelementptr inbounds [20 x i32], [20 x i32]* %2, i64 0, i64 %30
  store i32 %28, i32* %31, align 4
  br label %32

32:                                               ; preds = %21
  %33 = load i32, i32* %8, align 4
  %34 = add nsw i32 %33, 1
  store i32 %34, i32* %8, align 4
  br label %18, !llvm.loop !11

35:                                               ; preds = %18
  store i32 0, i32* %9, align 4
  br label %36

36:                                               ; preds = %120, %35
  %37 = load i32, i32* %9, align 4
  %38 = icmp slt i32 %37, 20
  br i1 %38, label %39, label %123

39:                                               ; preds = %36
  %40 = load i32, i32* %9, align 4
  %41 = sext i32 %40 to i64
  %42 = getelementptr inbounds [20 x i32], [20 x i32]* %1, i64 0, i64 %41
  %43 = load i32, i32* %42, align 4
  store i32 %43, i32* %10, align 4
  br label %44

44:                                               ; preds = %56, %39
  %45 = load i32, i32* %10, align 4
  %46 = icmp sgt i32 %45, 0
  br i1 %46, label %47, label %59

47:                                               ; preds = %44
  %48 = load i32, i32* %10, align 4
  %49 = load i32, i32* %9, align 4
  %50 = sext i32 %49 to i64
  %51 = getelementptr inbounds [20 x i32], [20 x i32]* %2, i64 0, i64 %50
  %52 = load i32, i32* %51, align 4
  %53 = load i32, i32* %9, align 4
  %54 = mul nsw i32 %53, 25
  %55 = add i32 -65536, %54
  call void @simPutPixel(i32 noundef %48, i32 noundef %52, i32 noundef %55)
  br label %56

56:                                               ; preds = %47
  %57 = load i32, i32* %10, align 4
  %58 = add nsw i32 %57, -1
  store i32 %58, i32* %10, align 4
  br label %44, !llvm.loop !12

59:                                               ; preds = %44
  %60 = load i32, i32* %9, align 4
  %61 = sext i32 %60 to i64
  %62 = getelementptr inbounds [20 x i32], [20 x i32]* %1, i64 0, i64 %61
  %63 = load i32, i32* %62, align 4
  store i32 %63, i32* %11, align 4
  br label %64

64:                                               ; preds = %76, %59
  %65 = load i32, i32* %11, align 4
  %66 = icmp slt i32 %65, 1024
  br i1 %66, label %67, label %79

67:                                               ; preds = %64
  %68 = load i32, i32* %11, align 4
  %69 = load i32, i32* %9, align 4
  %70 = sext i32 %69 to i64
  %71 = getelementptr inbounds [20 x i32], [20 x i32]* %2, i64 0, i64 %70
  %72 = load i32, i32* %71, align 4
  %73 = load i32, i32* %9, align 4
  %74 = mul nsw i32 %73, 25
  %75 = add i32 -65536, %74
  call void @simPutPixel(i32 noundef %68, i32 noundef %72, i32 noundef %75)
  br label %76

76:                                               ; preds = %67
  %77 = load i32, i32* %11, align 4
  %78 = add nsw i32 %77, 1
  store i32 %78, i32* %11, align 4
  br label %64, !llvm.loop !13

79:                                               ; preds = %64
  %80 = load i32, i32* %9, align 4
  %81 = sext i32 %80 to i64
  %82 = getelementptr inbounds [20 x i32], [20 x i32]* %2, i64 0, i64 %81
  %83 = load i32, i32* %82, align 4
  store i32 %83, i32* %12, align 4
  br label %84

84:                                               ; preds = %96, %79
  %85 = load i32, i32* %12, align 4
  %86 = icmp slt i32 %85, 512
  br i1 %86, label %87, label %99

87:                                               ; preds = %84
  %88 = load i32, i32* %9, align 4
  %89 = sext i32 %88 to i64
  %90 = getelementptr inbounds [20 x i32], [20 x i32]* %1, i64 0, i64 %89
  %91 = load i32, i32* %90, align 4
  %92 = load i32, i32* %12, align 4
  %93 = load i32, i32* %9, align 4
  %94 = mul nsw i32 %93, 25
  %95 = add i32 -65536, %94
  call void @simPutPixel(i32 noundef %91, i32 noundef %92, i32 noundef %95)
  br label %96

96:                                               ; preds = %87
  %97 = load i32, i32* %12, align 4
  %98 = add nsw i32 %97, 1
  store i32 %98, i32* %12, align 4
  br label %84, !llvm.loop !14

99:                                               ; preds = %84
  %100 = load i32, i32* %9, align 4
  %101 = sext i32 %100 to i64
  %102 = getelementptr inbounds [20 x i32], [20 x i32]* %2, i64 0, i64 %101
  %103 = load i32, i32* %102, align 4
  store i32 %103, i32* %13, align 4
  br label %104

104:                                              ; preds = %116, %99
  %105 = load i32, i32* %13, align 4
  %106 = icmp sgt i32 %105, 0
  br i1 %106, label %107, label %119

107:                                              ; preds = %104
  %108 = load i32, i32* %9, align 4
  %109 = sext i32 %108 to i64
  %110 = getelementptr inbounds [20 x i32], [20 x i32]* %1, i64 0, i64 %109
  %111 = load i32, i32* %110, align 4
  %112 = load i32, i32* %13, align 4
  %113 = load i32, i32* %9, align 4
  %114 = mul nsw i32 %113, 25
  %115 = add i32 -65536, %114
  call void @simPutPixel(i32 noundef %111, i32 noundef %112, i32 noundef %115)
  br label %116

116:                                              ; preds = %107
  %117 = load i32, i32* %13, align 4
  %118 = add nsw i32 %117, -1
  store i32 %118, i32* %13, align 4
  br label %104, !llvm.loop !15

119:                                              ; preds = %104
  br label %120

120:                                              ; preds = %119
  %121 = load i32, i32* %9, align 4
  %122 = add nsw i32 %121, 1
  store i32 %122, i32* %9, align 4
  br label %36, !llvm.loop !16

123:                                              ; preds = %36
  store i32 0, i32* %14, align 4
  br label %124

124:                                              ; preds = %158, %123
  %125 = load i32, i32* %14, align 4
  %126 = icmp slt i32 %125, 20
  br i1 %126, label %127, label %161

127:                                              ; preds = %124
  %128 = load i32, i32* %14, align 4
  %129 = add nsw i32 %128, 1
  store i32 %129, i32* %15, align 4
  br label %130

130:                                              ; preds = %154, %127
  %131 = load i32, i32* %15, align 4
  %132 = icmp slt i32 %131, 20
  br i1 %132, label %133, label %157

133:                                              ; preds = %130
  %134 = load i32, i32* %14, align 4
  %135 = sext i32 %134 to i64
  %136 = getelementptr inbounds [20 x i32], [20 x i32]* %2, i64 0, i64 %135
  %137 = load i32, i32* %136, align 4
  store i32 %137, i32* %5, align 4
  %138 = load i32, i32* %15, align 4
  %139 = sext i32 %138 to i64
  %140 = getelementptr inbounds [20 x i32], [20 x i32]* %1, i64 0, i64 %139
  %141 = load i32, i32* %140, align 4
  store i32 %141, i32* %4, align 4
  %142 = load i32, i32* %15, align 4
  %143 = sext i32 %142 to i64
  %144 = getelementptr inbounds [20 x i32], [20 x i32]* %2, i64 0, i64 %143
  %145 = load i32, i32* %144, align 4
  store i32 %145, i32* %7, align 4
  %146 = load i32, i32* %14, align 4
  %147 = sext i32 %146 to i64
  %148 = getelementptr inbounds [20 x i32], [20 x i32]* %1, i64 0, i64 %147
  %149 = load i32, i32* %148, align 4
  store i32 %149, i32* %6, align 4
  %150 = load i32, i32* %4, align 4
  %151 = load i32, i32* %5, align 4
  call void @delta(i32 noundef %150, i32 noundef %151)
  %152 = load i32, i32* %6, align 4
  %153 = load i32, i32* %7, align 4
  call void @delta(i32 noundef %152, i32 noundef %153)
  br label %154

154:                                              ; preds = %133
  %155 = load i32, i32* %15, align 4
  %156 = add nsw i32 %155, 1
  store i32 %156, i32* %15, align 4
  br label %130, !llvm.loop !17

157:                                              ; preds = %130
  call void (...) @simFlush()
  br label %158

158:                                              ; preds = %157
  %159 = load i32, i32* %14, align 4
  %160 = add nsw i32 %159, 1
  store i32 %160, i32* %14, align 4
  br label %124, !llvm.loop !18

161:                                              ; preds = %124
  ret void
}

; Function Attrs: argmemonly nofree nounwind willreturn writeonly
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #2

declare i32 @simRand(...) #1

declare void @simFlush(...) #1

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { argmemonly nofree nounwind willreturn writeonly }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"Ubuntu clang version 14.0.0-1ubuntu1.1"}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
!8 = distinct !{!8, !7}
!9 = distinct !{!9, !7}
!10 = distinct !{!10, !7}
!11 = distinct !{!11, !7}
!12 = distinct !{!12, !7}
!13 = distinct !{!13, !7}
!14 = distinct !{!14, !7}
!15 = distinct !{!15, !7}
!16 = distinct !{!16, !7}
!17 = distinct !{!17, !7}
!18 = distinct !{!18, !7}
