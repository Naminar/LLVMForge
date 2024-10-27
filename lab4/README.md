# LLVM IR generator from assebler
## Usage
```
clang++ $(llvm-config --cppflags --ldflags --libs) ../lab1/sim.c app_asm_ir_gen.cpp -lSDL2

./a.out app_asm_result.s
```

## Statistic & ISA
![](../lab2/stat_dyn.jpeg)

![alt text](src/ISA.png)