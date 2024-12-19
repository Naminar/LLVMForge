# The language for grpaphics app from lab1 

### How to build
```bash
# antlr generates c++ files 
java -jar ../Expression/antlr-4.13.0-complete.jar -Dlanguage=Cpp Forge.g4 -visitor

# compile language
clang++ *.cpp -I/home/namin/LLVMForge/Expression/vcpkg/installed/x64-linux/include/antlr4-runtime/  -lantlr4-runtime  $(llvm-config --cppflags --ldflags --libs) ../lab1/sim.c -lSDL2

# run
./a.out example.fr
```

> [!NOTE]  
> In antlr-4.13.0 impossible to use `as<type>`. It's necessary to use `std::any_cast<type*>`

## Description
```py
// new function
app 
    // declare obligatory variable based color
    // impossible to use as bColor
    based color         is 1678         // bColor = 1678
    let star_x          is rand 1204    // star_x = rand() % 1204
    let star_y          is rand 512
    let x_l_gradient    is rand 1204
    let x_r_gradient    is rand 1204
    let y_up_gradient   is rand 1204
    let y_down_gradient is rand 1204
    
    // creating cycle
    // based color will be propagated
    // cycle iteration will be <-----*
    ascend [ 
        iterator is star_x              // what will be iterated
        gradient is x_l_gradient        // set gradient variable
        xpoint is star_x                // set printing 
        ypoint is star_y                // coordinates (x, y)
    ]

    // creating cycle
    // based color will be propagated
    // cycle iteration will be *----->
    descend [ 
        iterator is star_y
        gradient is x_r_gradient
        xpoint is star_x
        ypoint is star_y
    ]
```