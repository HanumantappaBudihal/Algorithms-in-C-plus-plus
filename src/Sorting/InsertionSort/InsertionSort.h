#ifndef ALGORITHM_INSERTIONSORT_H__

#define ALGORITHM_INSERTIONSORT_H__
namespace Algorithm
{
    /**
 Insertion sort an array
 * */
    template <typename T>
    static void InsertionSort(T *inputArray, int numberOfElements)
    {
        for (int i = 1; i < numberOfElements; i++)
        {
            T keyElement = inputArray[i];
            int j = i - 1;

            while (j >=0 && inputArray[j] > keyElement)
            {
                inputArray[j + 1] = inputArray[j];
                j=j-1;
            }

            inputArray[j+1]=keyElement;
        }
    }
} // namespace Algorithm

#endif //