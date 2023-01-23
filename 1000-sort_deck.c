#include "deck.h"
/**
 * ato - mimicks atoi function
 * 
 * @c: the character to be converted to an integer
 * Return: the integral value
 */
int ato(const char *c)
{
    int i;

    for (i = 0; c[i] != '\0'; i++)
        ;
    if (i == 2)
        return (10);
    return (c[0] - 48);
}
/**
 * hash - gives us the integer key of the node
 * 
 * @val: the value
 * @req: the parameter being checked if it is the kid of card or value of card
 * Return: the key which can be used for comparison
 */
int hash(deck_node_t *val, bool req)
{
    if (req == false)
        return (val->card->kind);
    if (val->card->value[0] =='A')
        return (0);
    if (val->card->value[0] == 'J')
        return (11);
    if (val->card->value[0] == 'K')
        return (13);
    if (val->card->value[0] == 'Q')
        return (12);
    return (ato(val->card->value));
}
/**
 * mysort - sorts a deck of cards
 * 
 * @deck: the deck to be sorted
 * @req: the requirements true - sort according to kind
    - false - sort according to value
 * Return: nothing, it is void
 */
void mysort(deck_node_t **deck, bool req)
{
    deck_node_t *head, *curr, *nex_t;
    bool flag, loop;

    head = *deck;
    loop = true;
    while (loop)
    {
        flag = true;
        for (head = (*deck); head; head = head->next)
        {
            
            if (head->next)
                nex_t = head->next;
            if (hash(nex_t->prev, req) > hash(nex_t, req))
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
                    *deck = nex_t;
                nex_t->next = curr;
                curr->prev = nex_t;
            }
        }
        if (flag == true)
            return;
        
    }
}
/**
 * sort_deck - the framework for sorting a deck of cards 
 * 
 * @deck: the deck to be sorted
 * Return: nothing, it is void
 */
void sort_deck(deck_node_t **deck)
{
    mysort(deck, true);
    mysort(deck, false);
}