#include "sort.h"
/**
 * counting_sort -  sorts an array using counting sort
 * 
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: nothing, it is null
 */
void counting_sort(int *array, size_t size)
{
    int *count, max,*output;
    size_t i, j;

    if (size < 2)
        return;
    
    max = array[0];
    for (i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    max ++;
    output = (malloc(sizeof(int) * size));
    if (output == NULL)
        exit(1);
    count = malloc(sizeof(int) * max);
    if (count == NULL)
    {
        free(output);
        exit(1);
    }
    for (i = 0; i < (size_t)max; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < size; i++)
    {
        count[array[i]] += 1;
    }
    print_array(count, max);
    for (i = 1; (int)i < max; i++)
    {
        count[i] += count[i - 1];
    }
    print_array(count, max);
    for ( i = 0; i < size; i++)
    {
        j = array[i];
        count[j] = count[j] - 1;
        output[count[j]] = j;
    }
    for (i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
    free(output);
    free(count);
}