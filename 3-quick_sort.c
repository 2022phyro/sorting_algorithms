#include "sort.h"
/**
 * quick_sort - sorts an array of integers using quicksort algorithm
 * 
 * @array: The array to be sorted
 * @size: The array size
 */
void q_sort(int *array, int low,  int high, int count)
{
    int pivot, temp, i, j;

    if (low >= high || low < 0)
        return;
    pivot = array[high];
    i = low - 1;
    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
    i++;
    temp = array[i];
    array[i] = array[high];
    array[high] = temp;
    q_sort(array, low, i - 1, count);
    q_sort(array, i + 1, high, count);
}
void quick_sort(int *array, size_t size)
{
    q_sort(array, 0, (int)(size -1), size);
}