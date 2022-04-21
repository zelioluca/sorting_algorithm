//
// Created by luca on 15.4.2022.
//

#include "Sorting.h"
#include <chrono>

Sorting::Sorting(int *inputArray, int arraySize) : inputArray{inputArray}, arraySize{arraySize}
{

}

int* Sorting::BubbleSorting() {
    //flag is the element of the array is swapped or not
    bool flagIsSwapped = false;

    int elementToSort = arraySize;

    do
    {
        flagIsSwapped = false;
        // fix all the elements of the array
        for(int i = 0; i < elementToSort - 1; ++i)
        {
            // if they are in the wrong position swap it
            if(inputArray[i] > inputArray[i + 1])
            {
                std::swap(inputArray[i], inputArray[i + 1]);
                flagIsSwapped = true;
            }
        }
        //remove one from the element to sort
        --elementToSort;

    } while (flagIsSwapped);

    return inputArray;
}

int* Sorting::SelectionSorting() {
    int min;

    // iterate over the array
    for(int i = 0; i < arraySize - 1; ++i)
    {
        //get the min
        min = i;
        for(int j = i + 1; j < arraySize; ++j)
        {
            if(inputArray[j] < inputArray[min])
            {
                min = j;
            }

            std::swap(inputArray[i], inputArray[min]);
        }
    }

    return inputArray;
}

int* Sorting::InsertionSorting()
{
    //iterate over all the elements
    for(int i = 0; i < arraySize; ++i)
    {
        int actualValue = inputArray[i];
        int moving;

        for(moving = i - 1; moving>=0; --moving)
        {
            if(inputArray[moving] > actualValue)
            {
                inputArray[moving + 1] = inputArray[moving];
            }
            else
            {
                break;
            }
        }

        inputArray[moving + 1] = actualValue;
    }

    return inputArray;

}

void Sorting::Merge(int* iA, int start, int middle, int end)
{
    int totalElements = end - start + 1;
    int* tempArray = new int[totalElements];
    int left = start;
    int right = middle + 1;
    int done = 0;

    while(left <= middle && right <= end)
    {
        if(iA[left] <= iA[right])
        {
            tempArray[done] = iA[left];
            ++left;
        }
        else
        {
            tempArray[done] = iA[right];
            ++right;
        }

        ++done;
    }

    while(left <= middle)
    {
        tempArray[done] = iA[left];
        ++left;
        ++done;
    }

    while(right <= end)
    {
        tempArray[done] = iA[right];
        ++right;
        ++done;
    }

    for(int i = 0; i < totalElements; ++i)
    {
        iA[start + i] = tempArray[i];
    }

    delete[] tempArray;
    return;
}

int Sorting::Partition(int* iA, int start, int end)
{
    int pivot = iA[start];
    int middle = start;

    for(int i = start + 1; i <= end; ++i)
    {
        if(iA[i] < pivot)
        {
            ++middle;
            std::swap(iA[i], iA[middle]);
        }
    }

    std::swap(iA[start], iA[middle]);

    return middle;
}

int Sorting::GetMaxValue()
{
    int temp = inputArray[0];

    for(int i =0; i < arraySize; i++)
    {
        if(temp < inputArray[i])
        {
            temp = inputArray[i];
        }
    }

    return  temp;
}

int Sorting::GetMinValue()
{
    int temp = inputArray[0];

    for(int i =0; i < arraySize; i++)
    {
        if(temp > inputArray[i])
        {
            temp = inputArray[i];
        }
    }

    return  temp;
}

int* Sorting::MergeSorting(int* iA, int start, int end)
{
    if(start < end)
    {
        int middle = (start + end) / 2;
        Sorting::MergeSorting(iA, start, middle);
        Sorting::MergeSorting(iA, middle + 1, end);
        Sorting::Merge(iA, start, middle, end);
    }
    return iA;
}

int* Sorting::QuickSorting(int* iA, int start, int end)
{
    if(start < end)
    {
        int pivot = Sorting::Partition(iA, start, end);
        QuickSorting(iA, start, pivot - 1);
        QuickSorting(iA, pivot + 1, end);
    }

    return iA;
}

int* Sorting::CountingSorting()
{
    int max = Sorting::GetMaxValue();
    int min = Sorting::GetMinValue();
    int range = max - min + 1;

    int* count = new int[range];
    int* output = new int[arraySize];

    for(int i = 0; i < arraySize; i++)
    {
        count[inputArray[i] - min]++;
    }

    for(int i = 1; i < range; i++)
    {
        count[i] += count[i - 1];
    }

    for(int i = arraySize -1; i >=0; i--)
    {
        output[count[inputArray[i] - min] - 1] = inputArray[i];
        count[inputArray[i] - min]--;
    }

    for(int i = 0; i < arraySize; i++)
    {
        inputArray[i] = output[i];
    }

    return inputArray;
}