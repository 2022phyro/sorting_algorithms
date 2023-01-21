#include "sort.h"
/**
 * selection_sort - This is a sorting algorithm using selection sort
 * 
 * @array: the array to be sorted
 * @size: the array size
 * Return: nothing, it is void
 */
void selection_sort(int *array, size_t size)
{
    int temp;
    size_t count, n_count, min;

    if (size < 2)
        return;
    for (n_count = 0; n_count < size - 1; n_count++)
    {
        min = n_count;
        temp = array[n_count];
        for (count = n_count + 1; count < size; count++)
        {
            if (array[count] < array[min])
                min = count;
        }
        if (min != n_count)
        {
            temp = array[min];
            array[min] = array[n_count];
            array[n_count] = temp;
            print_array(array, size);
        }
    }
}