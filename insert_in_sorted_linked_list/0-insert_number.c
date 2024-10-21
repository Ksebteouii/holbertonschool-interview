#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/*
 */

listint_t *insert_node(listint_t **head, int number) 
{
    listint_t *current;
    listint_t *new;
    listint_t *prev;

    prev = NULL;
    current = *head;
    new = malloc(sizeof(listint_t));
    if (new == NULL) {
        return (NULL);
    }
    if (current == NULL) {;
        new->n = number;
        new->next = NULL;
        *head = new;
        return (new);
    }
    
    while (current != NULL)
    {   
        if (current->n < number) {
            prev = current;
            current = current->next;
        }
        else if (current->n >= number) {
            
            if (prev == NULL) {
                new->next = current;
                new->n = number;
                *head = new;
                return (new);
            }
            else {
                prev->next = new;
                new->next = current;
                new->n = number;
                return (new);
            }
        }
        if (current->next == NULL) {
            current->next = new;
            new->n = number;
            return (new);
        }
    }
return (NULL);
}