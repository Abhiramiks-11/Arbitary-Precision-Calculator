#include "apc.h"
int addition(Dlist *tail1, Dlist *tail2, Dlist **head_res, Dlist **tail_res)
{
    int carry = 0;
    while (tail1 != NULL || tail2 != NULL)
    {
        int n1 = 0, n2 = 0;
        if (tail1 != NULL)
        {
            n1 = tail1-> data;
            tail1 = tail1-> prev;
        }
        if (tail2 != NULL)
        {
            n2 = tail2-> data;
            tail2 = tail2-> prev;
        }
        int res = n1 + n2 + carry;
        carry = res / 10;
        res = res % 10;
        //new node allocation
        if (insert_first(head_res, tail_res, res) == FAILURE)
        {
            printf("Error: Failed to allocate node\n");
            return FAILURE;
        }
    }
    //if carry
    if (carry)
    {
        if (insert_first(head_res, tail_res, carry) == FAILURE)
        {
            printf("Error: Memory allocation failed in addition\n");
            return FAILURE;
        }
    }
    remove_unwanted_zeros(head_res, tail_res);
    return SUCCESS;
}