#include "sort.h"
/**
 * quick_sort - sorts an array of integers using quicksort algorithm
 * 
 * @array: The array to be sorted
 * @size: The array size
 */
int part(int *array, int low, int high, int count)
{
    int pivot, temp, i, j;

    pivot = array[high];
    i = low - 1;
    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
    i++;
    temp = array[high];
    array[high] = array[i];
    array[i] = temp;
    print_array(array, count);
    return i;
}
void q_sort(int *array, int low,  int high, int count)
{
    int i;

    if (low >= high || low < 0)
        return;
    i = part(array, low, high, count);
    q_sort(array, low, i - 1, count);
    q_sort(array, i + 1, high, count);
}
void quick_sort(int *array, size_t size)
{
    q_sort(array, 0, (int)(size -1), size);
}