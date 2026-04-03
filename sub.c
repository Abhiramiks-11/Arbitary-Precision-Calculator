#include "apc.h"
int subtraction(Dlist *tail1, Dlist *tail2, Dlist **head_res, Dlist **tail_res)
{
    int borrow = 0;
    // Continue till both lists completely get
    while (tail1 != NULL || tail2 != NULL)
    {
        int n1 = 0, n2 = 0;
        if (tail1 != NULL)   // Get digit from first list if available
        {
          n1 = tail1-> data;
          tail1 = tail1-> prev;
        }
        if (tail2 != NULL)   // Get digit from second list if available
        {
          n2 = tail2-> data;
          tail2 = tail2-> prev;
        }
        n1 = n1 - borrow;   // Subtract previous borrow from num1
        if (n1 < n2)        // Apply borrow logic if needed
        {
          n1 = n1 + 10;
          borrow = 1;
        }
        else
          borrow = 0;
        int diff = n1 - n2;
        // Allocate memory for new result node
        if (insert_first(head_res, tail_res, diff) == FAILURE)
        {
            printf("Error: Memory allocation failed in subtraction\n");
            return FAILURE;
        }
    }
    remove_unwanted_zeros(head_res, tail_res);
    return SUCCESS;
}