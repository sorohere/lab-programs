clang++ -fprofile-instr-generate -fcoverage-mapping main.cpp -L/usr/lib/gcc/x86_64-linux-gnu/11 -lstdc++ -o a.out

LLVM_PROFILE_FILE="main.profraw" ./a.out
llvm-profdata merge -sparse main.profraw -o main.profdata
llvm-cov show ./a.out -instr-profile=main.profdata
llvm-cov report ./a.out -instr-profile=main.profdata

# 1. Compilation with Coverage Instrumentation
# -fprofile-instr-generate: Adds instrumentation to count how often each line or branch is executed.
# -fcoverage-mapping: Generates mapping info that ties the execution counts to lines in the source code.
# -L... -lstdc++: Manually specifies the C++ standard library path since Clang can’t find it automatically on your system.
# -o a.out: Output executable named a.out


#  2. Running the Instrumented Program
# Runs your program (./a.out)
# Environment variable LLVM_PROFILE_FILE=main.profraw tells Clang to write raw coverage data into main.profraw

#  3. Convert Raw Profile to Structured Format
# Takes the raw .profraw file and creates a compact .profdata file that llvm-cov can understand
# -sparse is an optimization that reduces size and memory usage

# 4. View Annotated Source Code with Coverage
# Shows your original source code, line-by-line, with execution counts
# Highlights which lines were executed and which were missed

# 5. 
# Shows a summary: % coverage, total lines hit/missed, functions executed, etc.
