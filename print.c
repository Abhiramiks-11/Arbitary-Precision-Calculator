#include "apc.h"
int print(Dlist *head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return LIST_EMPTY;
    }
    while(head != NULL)
    {
        printf("%d", head-> data);
        head = head-> next;
    }
    printf("\n");
    return SUCCESS;
} 