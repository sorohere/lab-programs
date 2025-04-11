sudo apt update

# Install C++ compiler and standard libs
sudo apt install clang g++ libstdc++-11-dev

# Install llvm tools for coverage
sudo apt install llvm llvm-tools

# Install basic tools (if not already there)
sudo apt install build-essential


clang++ --version
llvm-cov --version
llvm-profdata --version
