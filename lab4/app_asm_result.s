entry:
    callSrem simRand, 1024, reg1
    callSrem simRand, 512,  reg2
    tcall simRand reg3
    callSrem simRand, 1024,  reg4
    callSrem simRand, 4056,  reg5
    callSrem simRand, 4056,  reg6
    cmpSgt reg1, 0, reg7
    jumpIfNot reg7, XR_COLOR
PREPARE:
    sremAdd reg3, 1024, 16, reg8
XL:
    mullAddVal reg1, reg8, 65535, reg9
    ctcall simFlush, simPutPixel, reg1, reg2, reg9
    addCmpUgtContinues reg1, -1, 1, reg1, reg10
    jumpIf reg10, XL
XR_COLOR:
    add reg4, 16, reg11
XR:
    mullAddVal reg1, reg11, 65535, reg12
    ctcall simFlush, simPutPixel, reg1, reg2, reg12
    add reg1, 1, reg1
    addCmpEqjumpIfNot reg1, 1, 1024, XR
YUP_COLOR:
    add reg5, 16, reg13
YUP:
    mullAddVal reg2, reg13, 65535, reg14
    ctcall simFlush, simPutPixel, reg1, reg2, reg14
    add reg2, 1, reg2
    addCmpEqjumpIfNot reg2, 1, 512, YUP
YUP_EXIT:
    cmpSgt reg2, 0, reg15
    jumpIfNot reg15, EXIT
YD_COLOR:
    add reg6, 16, reg16
YD:
    mullAddVal reg2, reg16, 65535, reg17
    ctcall simFlush, simPutPixel, reg1, reg2, reg17
    addCmpUgtContinues reg2, -1, 1, reg2, reg18
    jumpIf reg18, YD
EXIT:
    exit