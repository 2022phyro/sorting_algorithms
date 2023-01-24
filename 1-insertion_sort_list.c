#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort
 *
 * @list: The list to be sorted
 * Return: nothing, it is void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *head, *mark, *cross;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (true)
	{
		for (head = (*list); head->next; head = head->next)
		{
			temp = head->next;
			if (temp->prev->n > temp->n)
			{
				while (temp->prev->n > temp->n)
				{
					mark = temp->prev;
					cross = temp;
					mark->next = cross->next;
					if (cross->next)
						cross->next->prev = mark;
					cross->prev = mark->prev;
					if (mark->prev)
						mark->prev->next = cross;
					else
					{
						*list = cross;
						cross->next = mark;
						mark->prev = cross;
						print_list(*list);
						temp = cross;
						break;
					}
					cross->next = mark;
					mark->prev = cross;
					print_list(*list);
					temp = cross;
				}
				break;
			}
			if (temp->next == NULL)
				return;
		}
	}
}
