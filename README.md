# sorting_algorithm
This is my collection of sorting algorithm. The algorithms in my code are written in C++, you can use Cmake to build the project both windows or linux

## Installation with Cmake
Run
cmake -DCMAKE_BUILD_TYPE=Debug \
-DCMAKE_MAKE_PROGRAM=path_to_ninja/ninja \
-G Ninja  \
-S path_to_this_folder/Sorting \
-B path_to_build_folder

Just in case I left cmake-build-debug folder where you can find a compiled version of this software.

## Installation with g++
run in this folder g++ main.cpp -o Sorting

## Installation with make (linux)
run make from this folder to install 
run make clean to uninstall 


