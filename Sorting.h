//
// Created by luca on 15.4.2022.
//

#ifndef SORTING_SORTING_H
#define SORTING_SORTING_H

#include<iostream>

class Sorting {
private:
    int arraySize;
    int *inputArray;
    void Merge(int* iA, int start, int middle, int end);
    int Partition(int* iA, int start, int end);
    int GetMaxValue();
    int GetMinValue();

public:
    Sorting(int *inputArray, int arraySize);

    int* BubbleSorting();
    int* SelectionSorting();
    int* InsertionSorting();
    int* CountingSorting();

    //recursive
    int* MergeSorting(int* iA, int start, int end);
    int* QuickSorting(int* iA, int start, int end);


};


#endif //SORTING_SORTING_H
