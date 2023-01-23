#include "sort.h"
void bitonic_sort(int *array, size_t size)
{
    int k, j, l, i, temp;

    printf("Merging [16/16] (UP):\n");
    print_array(array, size);
    for (k = 2; k <= (int)size; k *= 2)
    {
        for (j = k/ 2; j > 0; j /= 2)
        {
            for (i = 0; i < (int)size; i++)
            {
                l = i ^ j;
                if (l > i)
                {
                    if (((i & k) == 0 && array[i] > array[l]) ||
                        ((i & k) != 0 && array[i] < array[l]))
                    {
                        temp = array[i];
                        array[i] = array[l];
                        array[l] = temp;
                        print_array(&array[j], 1);
                    }
                }
            }
            
        }
            
    }
    printf("Merging [16/16] (DOWN):\n");
    print_array(array, size);
}