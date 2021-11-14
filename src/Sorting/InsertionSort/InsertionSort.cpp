#include <iostream>
#include "InsertionSort.h"

using namespace std;
using namespace Algorithm;
int main()
{
    const int maxElement = 100;
    int inputArray[maxElement];

    //generate the random number and fill
    for (int i = 0; i < maxElement; i++)
    {
        inputArray[i] = rand() % 100;
    }

    cout<<"The list before sorting"<<endl;
    for(int i=0; i< maxElement;i++)
    {
        cout<<inputArray[i]<<" ";
    }

    Algorithm ::InsertionSort<int>(&inputArray[0],maxElement);

    cout<<endl<<"The list after sorting"<<endl;
    for(int i=0; i< maxElement;i++)
    {
        cout<<inputArray[i]<<" ";
    }

    return 0;
}
