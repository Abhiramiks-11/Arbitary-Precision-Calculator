#include "apc.h"
 int division(Dlist *head1, Dlist *head2, Dlist *tail1, Dlist *tail2, Dlist **head_res, Dlist **tail_res)
 {
   //check weather the second number is zero
   if(head2-> data == 0 && head2-> next == NULL)
    {
        printf("\nError: Division by zero is invalid\n");
        return FAILURE;
    }
   //we copy the first data into a temporary list
   Dlist *temp_head = NULL;
   Dlist *temp_tail = NULL;
   Dlist *temp = head1;
   while (temp != NULL)
   {
    if(insert_last(&temp_head, &temp_tail, temp-> data) == FAILURE)
        return FAILURE;
    temp = temp-> next;
   }
   int count = 0;
   while (compare_list(temp_head, head2) >= 0)
   {
    Dlist *old_head = temp_head;
    Dlist *old_tail = temp_tail;

    Dlist *new_head = NULL;
    Dlist *new_tail = NULL;
    if(subtraction(temp_tail, tail2, &new_head, &new_tail) == FAILURE)
        return FAILURE;  //do subtraction
    //remove duplicate zeros in front 
    remove_unwanted_zeros(&new_head, &new_tail);
    //update head and tail
    temp_head = new_head;
    temp_tail = new_tail;
    delete_list(&old_head, &old_tail);
    count++;
   }
   //store result
   *head_res = NULL;
   *tail_res = NULL;
   if(count == 0)//if output is zero
        if(insert_first(head_res, tail_res, 0) == FAILURE)
            return FAILURE;
        while(count > 0)
        {
            if(insert_first(head_res, tail_res, count % 10) == FAILURE)
                return FAILURE;//insert values to left
            count = count / 10;
        }
   delete_list(&temp_head, &temp_tail);
   return SUCCESS;
 }