#include <iostream>
#include <cstdlib>
#include <chrono>
#include "Sorting.h"

using namespace std;

class Timer
{
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTheTimer;

public:

    Timer()
    {
        startTheTimer = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        Stop();
    }

    void Stop()
    {
        auto stopTheTimer = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(startTheTimer).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(stopTheTimer).time_since_epoch().count();
        auto duration = end - start;
        double milliseconds = duration * 0.001;
        std::cout << "Duration in microseconds is  " << duration  <<" us " << endl;
        std::cout << "Duration in milliseconds is  " << milliseconds  <<" ms " << endl;

    }
};

void PrintArray(int* inputArray, int arraySize)
{
    for(int i = 0; i < arraySize; i++)
    {
        cout << "[" << i << "]" << " is " << inputArray[i] << endl;
    }
}

int * StartSorting(Sorting algo, int selectedAlgorithm, int* inputArray, int size)
{
    int *returnedArray;

    switch (selectedAlgorithm) {
        case 1:
        {
            cout << "I am running the Bubble sort algo " << endl;
            Timer timer;
            //execute
            returnedArray = algo.BubbleSorting();
            break;
        }
        case 2:
        {
            cout << "I am running the Selection sort algo " << endl;
            Timer timer;
            //execute
            returnedArray = algo.SelectionSorting();
            break;
        }
        case 3:
        {
            cout << "I am running the Insertion sort algo " << endl;
            Timer timer;
            returnedArray = algo.InsertionSorting();
            break;
        }
        case 4:
        {
            cout << "I am running the Merge sort algo " << endl;
            Timer timer;
            returnedArray = algo.MergeSorting(inputArray, 0, size - 1);
            break;
        }
        case 5:
        {
            cout << "I am running the Quick sort algo " << endl;
            Timer timer;
            returnedArray = algo.QuickSorting(inputArray, 0, size - 1);
            break;
        }
        case 6:
        {
            cout << "I am running the Counting sort algo " << endl;
            Timer timer;
            returnedArray = algo.CountingSorting();
            break;
        }
        case -1:
        default:
            break;
    }

    return returnedArray;
}

int main(int argc, char** argv) {

    // variables
    int rnd = 0;
    int ctn = 0;
    int * returnedArray;
    int sel;

    cout << "Enter the number of random integer: " << endl;
    cin >> rnd;

    // check if random is a positive number
    if(rnd <= 0)
    {
        throw invalid_argument("The value of the random integer should be greater then 0");
    }

    try {

        //get the array with the size with need
        int inputArray[rnd];

        //fill the array
        while (rnd--) {
            inputArray[ctn] = rand() % INT16_MAX + 1;
            ctn++;
        }

        //load complete
        cout << "Load of the random array is complete" << endl;

        //get the size of the array
        int size = *(&inputArray + 1) - inputArray;

        cout << "Before the sorting" << endl;
        PrintArray(inputArray, size);

        Sorting algo = Sorting(inputArray, size);

        cout << "" << endl;
        cout << "select the algorithm" << endl;
        cout << "" << endl;
        cout << "Press 1 for bubble sort" << endl;
        cout << "Press 2 for selection sort " << endl;
        cout << "Press 3 for insertion sort " << endl;
        cout << "Press 4 for merge sort " << endl;
        cout << "Press 5 for quick sort " << endl;
        cout << "Press 6 for continuing sort " << endl;
        cout << " " << endl;
        cout << "Press 7 for benchmark " << endl;
        cout << " " << endl;
        //-1 to exit the program
        cout << "Press -1 to exit" << endl;
        cin >> sel;

        //run single algo
        if((sel != -1) && (sel != 7))
        {
            returnedArray = StartSorting(algo, sel, inputArray, size);
            //print the array
            PrintArray(returnedArray, size);

        }

        //run the benchmark
        if(sel == 7)
        {
            for(int i = 1; i <= 6; ++i)
            {
                //copy the same unsorted array
                int * temp = inputArray;
                //create the algo obj each time
                Sorting sorting = Sorting(temp, size);
                //timer start each time inside this function so no worries
                returnedArray = StartSorting(sorting, i, temp, size);
                cout << "\t===\t===\t===" << endl;
            }

        }

    }
    catch(const std::exception& e)
    {
        cout << "Main throws exception " << e.what() << endl;
    }

    return 0;
}
