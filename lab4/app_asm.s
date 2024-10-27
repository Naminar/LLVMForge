entry:
    callSrem simRand, 1024, %2
    callSrem simRand, 512,  %4
    tcall simRand %5
    callSrem simRand, 1024,  %7
    callSrem simRand, 4056,  %9
    callSrem simRand, 4056,  %11
    cmpSgt %2, 0, %12
    jumpIfNot %12, XR_COLOR
PREPARE:
    sremAdd %5, 1024, 16, %15
XL:
    mov %2-22, %19
    mullAddVal %19, %15, 65535, %21
    ctcall simFlush, simPutPixel, %19, %4, %21
    addCmpUgtContinues %19, -1, 1, %22, %23
    jumpIf %23, XL
XR_COLOR:
    add %7, 16, %17
XR:
    mov %2-%30, %27
    mullAddVal %27, %17, 65535, %29
    ctcall simFlush, simPutPixel, %27, %4, %29
    add %27, 1, %30
#    addCmpEq %27, 1, 1024, %31
#    jumpIf %31, YUP_COLOR, XR
    addCmpEqjumpIfNot %27, 1, 1024, XR
YUP_COLOR:
    add %9, 16, %25
YUP:
    mov %4-%40, %37
    mullAddVal %37, %25, 65535, %39
    ctcall simFlush, simPutPixel, %2, %37, %39
    add %37, 1, %40
#    addCmpEq %37, 1, 512, %41
#    jumpIf %41, YUP_EXIT, YUP
    addCmpEqjumpIfnot %37, 1, 512, YUP
YUP_EXIT:
    cmpSgt %4, 0, %33
    jumpIfNot %33, EXIT
YD_COLOR:
    add %11, 16, %35
YD:
    mov %4-47, %44
    mullAddVal %44, %35, 65535
    ctcall simFlush, simPutPixel, %2, %44, %46
    addCmpUgtContinues %44, -1, 1, %47, %48
    jumpIf %48, YD
EXIT:
    exit