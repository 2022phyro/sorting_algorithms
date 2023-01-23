#include "sort.h"
/**
 * heap_sort - sorts an array of integers using heap sort algorithm
 * 
 * @array: the array to be sorted
 * @size: the array size
 * Return: nothing it is void
 */
void heap_sort(int *array, size_t size)
{
    int n, temp;

    if (size < 2)
        return;
    heapify(array, size);
    n = size - 1;
    while (n > 0)
    {
        temp = array[n];
        array[n] = array[0];
        array[0] = temp;
        n--;
        print_array(array, size);
        sift_down(array, 0, n, size);
    }
}
/**
 * heapify - converts an array into a max heap
 * 
 * @array: the array being considered
 * @size: the array size/lenght
 * Return: nothing it is void
 */
void heapify(int *array, int size)
{
    int start;

    start = parent(size - 1);
    while (start >= 0)
    {
        sift_down(array, start, size - 1, size);
        start--;
    }
}

/**
 * parent - this finds the index of the parent node in the heap
 * 
 * @n: the index being considered 
 * Return: the index of the parent node
 */
int parent(int n)
{
    if (n % 2 == 0)
        return ((n -2 ) / 2);
    return ((n - 1) / 2);
}

/**
 * parent - this finds the index of the parent node in the heap
 * 
 * @n: the index being considered 
 * Return: the index of the left child
 */
int left(int n)
{
    return ((2 *n) + 1);
}
/**
 * sift_down - rearranges the heap to make sure the parent is 
    - larger or equal to the child nodes' value
 * 
 * @array: the array being considered
 * @start: the start point
 * @end:  the end point
 * @size: the size of the array (for printing)
 * Return: nothing, it is void
 */
void sift_down(int *array, int start, int end, int size)
{
    int root, child, swap, temp;

    root = start;
    while (left(root) <= end)
    {
        child = left(root);
        swap = root;
        if (array[swap] < array[child])
            swap = child;
        if ((child + 1 <= end) && (array[swap] < array[child + 1]))
            swap = child + 1;
        if (swap == root)
            return;
        temp = array[swap];
        array[swap] = array[root];
        array[root] = temp;
        root = swap;
        print_array(array, size);
    }
}