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
