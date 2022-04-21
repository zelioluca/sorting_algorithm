# Sorting algorithms
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

## Installation with make (linux and mac)
run make from this folder to install 
run make clean to uninstall 

## Run the program
Run the program with ./Sorting 

### Step 1:
Enter the number of random integer:  how much big you want your random array

### Step 2:
Press 1 for bubble sort \
Press 2 for selection sort \
Press 3 for insertion sort \
Press 4 for merge sort \
Press 5 for quick sort \
Press 6 for continuing sort \
Press 7 for benchmark \
Press -1 to exit 

Enjoy the results

