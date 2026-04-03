#include "apc.h"
int multiplication(Dlist *tail1, Dlist *tail2, Dlist **head_res, Dlist **tail_res)
{
//used to give zero to the list first since list is empty
  Dlist *res_head = NULL;
  Dlist *res_tail = NULL;
  if(insert_first(&res_head, &res_tail, 0) == FAILURE)
    return FAILURE;
  int Shiftcount = 0;// to get count of number of shifts needed
  while ((tail2 != NULL))
  {
    Dlist *temp_head = NULL;
    Dlist *temp_tail = NULL;
    Dlist *t1 = tail1;
    int carry = 0;
    //Multiply each digit of first number with current second number
    while(t1 != NULL)
    {
      int pdt;
      pdt = t1-> data * tail2-> data + carry;
      if(insert_first(&temp_head, &temp_tail, pdt % 10) == FAILURE)
        return FAILURE;//to store only one digit 
      carry = pdt / 10;//carry stored 
      t1 = t1-> prev;//move to prev dig
    }
    //carry is present last
    if(carry)
    {
      if(insert_first(&temp_head, &temp_tail, carry) == FAILURE)
        return FAILURE;
    }
    //loop to add zeros at the end according to size of number 
    for(int i = 0; i < Shiftcount; i++)
    {
      if(insert_last(&temp_head, &temp_tail, 0) == FAILURE)
        return FAILURE;
    }
    //store the result data after addition
    Dlist *new_head = NULL;
    Dlist *new_tail = NULL;
    if(addition(res_tail, temp_tail, &new_head, &new_tail) == FAILURE)
      return FAILURE;
    delete_list(&res_head, &res_tail);
    delete_list(&temp_head, &temp_tail);
    //update res list
    res_head = new_head;
    res_tail = new_tail;
    Shiftcount++;
    tail2 = tail2-> prev;
  }
  //final result
  remove_unwanted_zeros(&res_head, &res_tail);
  *head_res = res_head;
  *tail_res = res_tail;
  return SUCCESS;
}