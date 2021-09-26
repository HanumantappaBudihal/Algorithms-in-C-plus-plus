#ifndef ALGORITHM_INSERTIONSORT_H__

#define ALGORITHM_INSERTIONSORT_H__

//This is generic algorithm to apply the insertion sort
namespace Algorithm
{
    /**********************************************************************************
     * Generic Insertion Sort 
     * Time complexity : O(n^2) : Worst case -> reverse order array as input
     *                 : O(n)   : Best case -> already sorted array as input
     * 
     * Space complexity: O(1) 
     *********************************************************************************/

    template <typename T>
    static void InsertionSort(T *inputArray, int numberOfElements)
    {
        for (int i = 1; i < numberOfElements; i++)
        {
            T keyElement = inputArray[i];
            int j = i - 1;

            while (j >= 0 && inputArray[j] > keyElement)
            {
                inputArray[j + 1] = inputArray[j];
                j = j - 1;
            }

            inputArray[j + 1] = keyElement;
        }
    }
} // namespace Algorithm

#endif //