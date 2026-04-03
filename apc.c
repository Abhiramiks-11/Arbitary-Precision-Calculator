#include "apc.h"
//argument validation 
int arg_validation(int argc, char* argv[])
{
    if(argc != 4)
    {
        printf("Error: Wrong arguments are passed \n use: %s operand1 operator operand 2\n",argv[0]);
        return FAILURE;
    }
    //check only digits in argument 1 & 3
    if(check_number(argv[1]) == FAILURE)
    {
        printf("Error: Invalid operand is passed in second argument\n");
        return FAILURE;
    }
    if(check_number(argv[3]) == FAILURE)
    {
        printf("Error: Invalid operand is passed in third argument\n");
        return FAILURE;
    }
    //operator is there in argument 2
    if(check_operator(argv[2][0]) == FAILURE)
    {
     printf("Error: Invalid\n");
     return FAILURE;
    }
return SUCCESS;
}
//check operator
int check_operator(char ch)
{
  char operators[] = "+-*/";
  for(int i = 0; operators[i] != '\0'; i++)
  {
      if(operators[i] == ch)
      {
        return SUCCESS;
      }
  }
  return FAILURE;
}
//check number
int check_number(char *str)
{
    int i = 0;
    //check sign
    if(str[i] == '+' || str[i] == '-')
    {
        i++;
        //for multiple sign
        if(str[i] == '+' || str[i] == '-')
        {
            printf("Error: Multiple signs are present.\n");
            return FAILURE;
        }
    }
    //check one number is present or not
    if(str[i] == '\0')
    {
     return FAILURE;
    }
    //check balance are only numbers 
    while(str[i] != '\0')
    {
        if(!isdigit(str[i]))
        {
            printf("Error: Only digits should be present\n");
            return FAILURE;
        }
        i++;
    }
    return SUCCESS;
}
//length of list 
int list_length(Dlist *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head-> next;
    }
    return count;
}
//compare list size
int compare_list (Dlist *head1, Dlist *head2)
{
    int len1 = list_length(head1);
    int len2 = list_length(head2);
    //check with length
    if (len1 > len2)
        return 1;
    if (len1 < len2)
        return -1;
    //same length compare digit by digit
    while (head1 && head2)
    {
        if (head1-> data > head2-> data)
            return 1;
        if (head1-> data < head2-> data)
            return -1;
        head1 = head1-> next;
        head2 = head2-> next;
    }
    return 0;
}
//convert str to list
int str_tolist(char *str, Dlist **head, Dlist **tail)
{
    int i = 0;
    if(str[i] == '+' || str[i] == '-')
    {
        i++;
    }
    //one digit is needed for operation
      if (str[i] == '\0')
    {
        printf("Error: No digits\n");
        return FAILURE;
    }
    //is digit only 
    while(str[i] != '\0')
    {
      if(!isdigit(str[i]))
      {
            printf("Error: Invalid number\n");
            return FAILURE;
      }
     
      Dlist *new = malloc(sizeof(Dlist));//allocate memory
      if(new == NULL)
      {
        printf("Error: Memory allocation failed");
        return FAILURE;
      }
      new-> data = str[i] - '0';//or use -48 to convert string to integer
      new-> prev = NULL;
      new-> next = NULL;
      if(*head == NULL)
        *head = *tail = new;
      else
      {
        new-> prev = *tail;
        (*tail)-> next = new;
        *tail = new;
      }
      i++;
    }
    return SUCCESS;
}
// to remove unwanted zeros 
void remove_unwanted_zeros(Dlist **head, Dlist **tail)
{
    while (*head && (*head)-> data == 0 && (*head)-> next != NULL)
    {
        Dlist *temp = *head;
        *head = (*head)-> next;
        (*head)-> prev = NULL;
        free(temp);
    }
    // fix tail if list became single node
    if (*head == NULL)
        *tail = NULL;
    else
    {
        Dlist *temp = *head;
        while (temp-> next)
            temp = temp-> next;
        *tail = temp;
    }
}
// Insert a node at beginning of dll
int insert_first(Dlist **head, Dlist **tail,int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
        return FAILURE;
    new-> data = data;
    new-> prev = NULL;
    new-> next = *head;
    if(*head != NULL)    
        (*head)-> prev = new;
    else
        *tail = new;  
    *head = new;
    return SUCCESS;
}
// Insert a node at end of the dll
int insert_last(Dlist **head,Dlist **tail,int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
        return FAILURE;
    new-> data = data;
    new-> prev = *tail;
    new-> next = NULL;
    if(*tail != NULL) 
        (*tail)-> next = new;
    else
        *head = new;  
    *tail = new;
    return SUCCESS;
}
//delete list
void delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp = *head;
    while (temp != NULL)
    {
        Dlist *next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
    *tail = NULL;
}