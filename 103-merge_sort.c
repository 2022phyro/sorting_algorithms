#include "sort.h"
/**
 * top_down_split_merge - this splits the array and merges them later 
 *
 * @B: the working array
 * @start: the start point
 * @end: the end point
 * @A: the array to be sorted
 * Return: nothing it is void
 */
void top_down_split_merge(int *B, int start, int end, int *A)
{
    int mid;

    if (end - start <= 1)
        return;
    mid = ((end + start) / 2);
    top_down_split_merge(A, start, mid, B);
    top_down_split_merge(A, mid, end, B);
    top_down_merge(B, start, mid, end, A);
    printf("[Done]: ");
    print_array(&A[start], end - start);
}
/**
 * top_down_merge - this merges the array that was split before 
 *
 * @B: the working array
 * @start: the start point
 * @end: the end point
 * @mid: the middle;
 * @A: the array to be sorted
 * Return: nothing it is void
 */
void top_down_merge(int *A, int start, int mid, int end, int *B)
{
    int i, j, k;

    i = start;
    j = mid;
    printf("Merging...\n");
    printf("[left]: ");
    print_array(&A[start], mid - start);
    printf("[right]: ");
    print_array(&A[mid], end - mid);
    for (k = start; k < end; k++)
    {
        if (i < mid  && (j >= end || A[i] <= A[j]))
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
    }
}
/**
 * copy_array - this copies the contents of one array to another
 *
 * @B: the working array
 * @start: the start point
 * @end: the end point
 * @A: the array to be copied from
 * Return: nothing it is void
 */
void copy_array(int *A, int start, int end, int *B)
{
    int k;

    for (k = start; k < end; k++)
        B[k] = A[k];
}
/**
 * top_down_merge_sort - this sorts using top down method 
 *
 * @B: the working array
 * @size: the array size
 * @A: the array to be sorted
 * Return: nothing it is void
 */
void top_down_merge_sort(int *A, int *B, int size)
{
    copy_array(A, 0, size, B);
    top_down_split_merge(B, 0, size, A);
}
/**
 * merge_sort - this sorts using merge sort algorithm
 * 
 * @array: the array to be sorted
 * @size: the array lenght
 * Return: nothing it is void
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    temp = malloc(sizeof(int) * size);
    if (temp == NULL)
        exit(1);
    top_down_merge_sort(array, temp, (int)size);
    free(temp);
}