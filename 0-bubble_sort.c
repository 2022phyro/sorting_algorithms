#include "sort.h"
/**
 * bubble_sort - sorts an array using bubble sort algorithm
 *
 * @array: THe array to be sorted
 * @size: the array size/lenght
 * Return: nothing, it is void
 */
void bubble_sort(int *array, size_t size)
{
	int current, next, temp;
	size_t i;
	bool flag, loop;

	if (size < 2)
		return;
	loop = true;
	while (loop)
	{
		flag = false;
		for (i = 0; i < size - 1; i++)
		{
			current = i;
			next = i + 1;
			if (array[current] > array[next])
			{
				flag = true;
				temp = array[current];
				array[current] = array[next];
				array[next] = temp;
				print_array(array, size);
			}
		}
		if (flag == false)
			break;
	}
}
