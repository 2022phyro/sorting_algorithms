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
    int min, temp, pointer;
    size_t count, n_count;

    pointer = 0;
    for (n_count = 0; n_count < size; n_count++)
    {
        min = array[n_count];
        temp = array[n_count];
        for (count = n_count; count < size; count++)
        {
            if (array[count] < min)
            {
                min = array[count];
                pointer = count;
            }
        }
        array[n_count] = min;
        array[pointer] = temp;
        if (min != temp)
            print_array(array, size);
        
    }
}