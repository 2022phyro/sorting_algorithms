#include "sort.h"
void q_ssort(int *array, int low, int high, int count)
{
    int i;

    if (low >= 0 && high >= 0 && low < high)
    {
        i = part(array, low, high, count);
        q_ssort(array, low, i, count);
        q_ssort(array, i + 1, high, count);
    }
}
void quick_sort_hoare(int *array, size_t size)
{
    q_ssort(array, 0, size - 1, size);
}
int part(int *array, int low, int high, int count)
{
    int pivot, i, j, temp;

    pivot = array[high];
    i = low - 1;
    j = high + 1;
    while (true)
    {
        do
        {
            i++;
        } while (array[i] < pivot);
        do
        {
            j--;
        } while (array[j] > pivot);
        if (i > j)
            return (j);
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
        if (array[i] != array[j])
            print_array(array, count);
    }
}