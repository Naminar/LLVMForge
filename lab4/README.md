![](../lab2/stat_dyn.jpeg)

```
clang++ $(llvm-config --cppflags --ldflags --libs) ../lab1/sim.c app_asm_ir_gen.cpp -lSDL2

./a.out app_asm_result.s
```