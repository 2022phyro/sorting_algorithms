#include "sort.h"
int sig_digit(int n, int base)
{
    return ((n / base) % 10);
}
void radix_sort(int *array, size_t size)
{
    int max, *output, *count, digit;
    size_t i, j;

    if (size < 2)
        return;
    max = array[0];
    for (i = 0; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    output = (malloc(sizeof(int) * size));
    if (output == NULL)
        exit(1);
    count = malloc(sizeof(int) * 10);
    if (count == NULL)
    {
        free(output);
        exit(1);
    }
    digit = 1;
    while (max / digit > 0)
    {
        for (i = 0; i < 10; i++)
            count[i] = 0;
        for (i = 0; i < size; i++)
            count[sig_digit(array[i], digit)] ++;
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (i = size - 1; (int)i >= 0; i--)
        {
            j = array[i];
            count[sig_digit(j, digit)] = count[sig_digit(j, digit)] - 1;
            output[count[sig_digit(j, digit)]] = j;
        }
        for (i = 0; i < size; i++)
            array[i] = output[i];
        print_array(array, size);
        digit *= 10;       
    }
    free(count);
    free(output);
}