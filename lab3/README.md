# LLVM Pass example
This is example of LLVM IR building.

## Usage
```bash
clang++ $(llvm-config --cppflags --ldflags --libs) ../lab1/sim.c IR.cpp -lSDL2
./a.out
```