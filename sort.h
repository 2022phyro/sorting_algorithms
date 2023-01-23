#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <string.h>
#define bool int
#define true 1
#define false 0
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
/* GENERAL UTILITIES*/
void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
/* SOLUTIONS TO EACH TASK*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);

/* MERGE SORT UTILITIES*/
void top_down_merge_sort(int *A, int *B, int size);
void copy_array(int *A, int start, int end, int *B);
void top_down_merge(int *A, int start, int mid, int end, int *B);
void top_down_split_merge(int *B, int start, int end, int *A);

/* HEAP SORT UTILITY*/
void heapify(int *array, int size);
void sift_down(int *array, int start, int end, int size);
int left(int n);
int parent(int n);

/*RADIX SORT UTILITY*/
int sig_digit(int n, int base);


#endif /*SORT_H*/