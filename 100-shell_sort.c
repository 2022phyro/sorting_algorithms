#include "sort.h"
/**
 * shell_sort - sorts an array of integers using shell sort
 *
 * @array: the array to be sorted
 * @size: the array size
 */
void shell_sort(int *array, size_t size)
{
    size_t iter, out, i;
    int temp;

    if (size < 2)
        return;
    if (size == 2 && array[1] < array[0])
    {
        temp = array[1];
        array[1] = array[0];
        array[0] = temp;
        print_array(array, 2);
        return;
    }
    iter = 0;
    while (iter < size / 3)
        iter =  (iter * 3) + 1;
    
    while (iter > 0)
    {
        for (out = iter; out < size; out++)
        {
            temp = array[out];
            i = out;
            while (i > iter -1 && array[i - iter] >= temp)
            {
                array[i] = array[i - iter];
                i -= iter;
            }
            array[i] = temp;
        }
        iter = ((iter - 1) / 3);
        print_array(array, size);
    }
}