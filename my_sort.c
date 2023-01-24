#include "sort.h"
/**
 * @my_sorts, is sorting algorithms i may ave discovered
 * 
 */
void my_insertion_sort(listint_t **list)
{
    listint_t *head, *curr, *nex_t;
    bool flag, loop;

    head = *list;
    loop = true;
    while (loop)
    {
        flag = true;
        for (head = (*list); head->next; head = head->next)
        {
            
            nex_t = head->next;
            if (nex_t->prev->n > nex_t->n)
            {
                flag = false;
                curr = nex_t->prev;
                flag = false;
                curr->next = nex_t->next;
                if (nex_t->next)
                    nex_t->next->prev = curr;
                nex_t->prev = curr->prev;
                if (curr->prev)
                    curr->prev->next = nex_t;
                else
                    *list = nex_t;
                nex_t->next = curr;
                curr->prev = nex_t;
                print_list(*list);
                break;
            }
        }
        if (flag == true)
            return;
    }

}
#include "sort.h"
/**
 * cocktail_sort_list - sorts a doubly linked list using cocktail shaker
 * 
 * @list: the list to be sorted
 * Return: nothing, it is void
 */
void my_strange_sort(listint_t **list)
{
    listint_t *head, *curr, *nex_t;
    bool flag, loop;

    head = *list;
    loop = true;
    while (loop)
    {
        flag = true;
        for (head = (*list); head; head = head->next)
        {
            
            if (head->next)
                nex_t = head->next;
            if (nex_t->prev->n > nex_t->n)
            {
                flag = false;
                curr = nex_t->prev;
                flag = false;
                curr->next = nex_t->next;
                if (nex_t->next)
                    nex_t->next->prev = curr;
                nex_t->prev = curr->prev;
                if (curr->prev)
                    curr->prev->next = nex_t;
                else
                    *list = nex_t;
                nex_t->next = curr;
                curr->prev = nex_t;
                print_list(*list);
            }
        }
        if (flag == true)
            return;
    }

}
/**
 * quick_sort - sorts an array of integers using quicksort algorithm
 * 
 * @array: The array to be sorted
 * @size: The array size
 */
void quick_sort(int *array, size_t size)
{
    if (size < 2)
        return;
    q_sort(array, 0, (int)(size -1), size);
}
/**
 * part_l - partitions an array as a subroutine in quicksort
 * 
 * @array: the array to be sorted
 * @low: the starting point
 * @high: the ending point
 * @count: the array size
 * Return: an integer, the pivot 
 */
int part_l(int *array, int low, int high, int count)
{
    int pivot, temp, i, j;

    pivot = array[high];
    i = low - 1;
    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            temp = array[j];
            array[j] = array[i];
            array[i] = temp;
            print_array(array, count);

        }
    }
    temp = array[high];
    array[high] = array[i + 1];
    array[i + 1] = temp;
    return (i + 1);
}
void q_sort(int *array, int low,  int high, int count)
{
    int i;

    if (low < high)
    {
        i = part_l(array, low, high, count);
        q_sort(array, low, i - 1, count);
        q_sort(array, i + 1, high, count);
    }
}
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