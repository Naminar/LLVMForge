java -jar ../lab5/antlr-4.13.0-complete.jar -Dlanguage=Cpp NodeLang.g4 -visitor

clang++ *.cpp -I/home/namin/LLVMForge/lab5/vcpkg/installed/x64-linux/include/antlr4-runtime/  -lantlr4-runtime  $(llvm-config --cppflags --ldflags --libs) sim.c -lSDL2