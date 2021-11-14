
// TODO : Need to use the standard way to implement the algorithm , will do it later

#include <iostream>

using namespace std;

void QuickSort(int *inputArray, int low, int high);
int Partition(int *inputArry, int low, int high);

int main()
{
    const int maxElement = 100;
    int inputArray[maxElement];

    // generate the random number and fill
    for (int i = 0; i < maxElement; i++)
    {
        inputArray[i] = (rand() % 100) - 50;
    }

    cout << "The list before sorting" << endl;
    for (int i = 0; i < maxElement; i++)
    {
        cout << inputArray[i] << " ";
    }

    QuickSort(inputArray, 0, maxElement-1);

    cout << endl
         << "The list after sorting" << endl;
    for (int i = 0; i < maxElement; i++)
    {
        cout << inputArray[i] << " ";
    }

    return 0;
}

void QuickSort(int *inputArray, int low, int high)
{
    if (low < high)
    {
        int partionIndex = Partition(inputArray, low, high);

        QuickSort(inputArray, low, partionIndex - 1);
        QuickSort(inputArray, partionIndex + 1, high);
    }
}

int Partition(int *inputArray, int low, int high)
{
    int pivotElement = inputArray[high];
    int backIndex = low - 1;

    for (int frontIndex = low; frontIndex <=high - 1; frontIndex++)
    {
        if (inputArray[frontIndex] <= pivotElement)
        {
            backIndex += 1;

            int temp = inputArray[frontIndex];
            inputArray[frontIndex] = inputArray[backIndex];
            inputArray[backIndex] = temp;
        }
    }

    int temp = inputArray[high];
    inputArray[high] = inputArray[backIndex+1];
    inputArray[backIndex+1] = temp;

    return backIndex+1;
}