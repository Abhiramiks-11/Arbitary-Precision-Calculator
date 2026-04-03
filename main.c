#include "apc.h"
int main(int argc,char *argv[])
{
  printf("\n===============================================\n");
  printf("          ARBITRARY PRECISION CALCULATOR       ");
  printf("\n===============================================\n");
//argument validation
  if(arg_validation(argc, argv) == FAILURE)
  {
    printf("Error: Invalid argument provided\n");
    return FAILURE;
  }
//assigning NULL for operator1, operator2 and result operator in head and tail
Dlist *head1 = NULL, *tail1 = NULL;
Dlist *head2 = NULL, *tail2 = NULL;
Dlist *head_res = NULL, *tail_res = NULL;
//convert str to list for both numbers
if(str_tolist(argv[1], &head1, &tail1) == FAILURE)
{
  printf("Error: Failed to convert operand 1\n");
  return FAILURE;
}
if(str_tolist(argv[3], &head2, &tail2) == FAILURE)
{
  printf("Error: Failed to convert operand 2\n");
  return FAILURE;
}
char *op1 = argv[1], *op2 = argv[3];
printf("Operand 1 : %s\nOperand 2 : %s\n", op1, op2);
char operator = argv[2][0];
char sign1 = '+';
char sign2 = '+';
if (argv[1][0] == '-')
    sign1 = '-';
if (argv[3][0] == '-')
    sign2 = '-';
switch(operator)
{
    case '+':                                  //case 1 addition
    {
      printf("\nAddition\n");
      int negative = 0;
      //2 signs are +
      if(sign1 == '+' && sign2 == '+')
      {
        addition(tail1, tail2, &head_res, &tail_res);
      }
      //first sign + and second sign -
      else if (sign1 == '+' && sign2 == '-')
      {
        int cmp = compare_list(head1, head2);  //to check which one is big
          if(cmp < 0)                          //first is less than second
          {
           subtraction(tail2, tail1, &head_res, &tail_res);
           negative = 1;
          }
          else
            subtraction(tail1, tail2, &head_res, &tail_res);
       }
      //first sign - and second sign +
      else if (sign1 == '-' && sign2 == '+')
      {
        int cmp = compare_list(head2, head1);
          if(cmp < 0)
          {
            subtraction(tail1, tail2, &head_res, &tail_res); 
            negative = 1;
          }
          else
            subtraction(tail2, tail1, &head_res, &tail_res); 
      }
      else if (sign1 == '-' && sign2 == '-')
      {
        addition( tail1,tail2,&head_res,&tail_res);
        negative = 1;
      }
         //result
          printf("Result: ");
          if (negative)
            printf("-");
          print(head_res);
          printf("\nAddition Successful\n");
          break;
    }
    case '-':                                       //case 2 subtraction
    {
      printf("\nSubtraction\n");
      int negative = 0;
      //first is + and second is +
      if (sign1 == '+' && sign2 == '+')
      {  
        int cmp = compare_list(head1, head2);
        if (cmp < 0)   
        {
          negative = 1;
          subtraction(tail2, tail1, &head_res, &tail_res); 
        }
       else        
          subtraction(tail1, tail2, &head_res, &tail_res); 
      }  
        //first number + and second is -
      else if (sign1 == '+' && sign2 == '-')
      {
        addition(tail1, tail2, &head_res, &tail_res);
      }
        //first number is - and second is +
      else if (sign1 == '-' && sign2 == '+')
      {
        addition(tail1, tail2, &head_res, &tail_res);
        negative = 1;
      }
        //first is + and second is -
      else if (sign1 == '-' && sign2 == '-')
      {
        int cmp = compare_list(head2, head1);
        if (cmp < 0)  
        {
          subtraction(tail1, tail2, &head_res, &tail_res); 
          negative = 1;
        }
        else
         subtraction(tail2, tail1, &head_res, &tail_res); 
      }
        //result
        printf("Result: ");
        if (negative)
            printf("-");
        print(head_res);
        printf("\nSubtraction Successful\n");
        break;
    }
    case '*':                                     //case 3 multiplication
    {
       printf("\nMultiplication\n");
      int negative = 0;
        //both are +
      if(sign1 == '+' && sign2 == '+')
      {
        multiplication(tail1,tail2,&head_res,&tail_res);
      }
        //both are -
      else if (sign1 == '-' && sign2 == '-')
      {
        multiplication(tail1,tail2,&head_res,&tail_res);
      }
      else 
      {
        multiplication(tail1,tail2,&head_res,&tail_res);
        negative = 1;
      }
        //result
      printf("Result: ");
      if(negative)
          printf("-");
      print(head_res);
      printf("\nMultiplication Successful\n");
      break;
    }
    case '/':                                     //case 4 division 
    {
      printf("\nDivision\n");
      int negative = 0;
      if(division(head1,head2,tail1,tail2,&head_res,&tail_res)==FAILURE)
        return FAILURE;
       //one operation is -        
      if((sign1 == '-' && sign2 == '+') || (sign1 == '+' && sign2 == '-'))
      {
        negative = 1;
      }  
       //result
      printf("Result: ");
      if(negative)
        printf("-");
      print(head_res);
      printf("\nDivision Successful\n");
      break;  
    }
    default:
    {
      printf("Error: Invalid operator\n");
      return FAILURE;
    }
}
delete_list(&head1, &tail1);
delete_list(&head2, &tail2);
delete_list(&head_res, &tail_res);
return SUCCESS;
}