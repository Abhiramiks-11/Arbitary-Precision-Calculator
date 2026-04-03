#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY 2

typedef struct list
{
 int data;
 struct list *prev;
 struct list *next;
}Dlist;

//functions used
int arg_validation(int argc, char* argv[]);
int str_tolist(char *str, Dlist **head, Dlist **tail);
int insert_first(Dlist **head, Dlist **tail, int data);
int insert_last(Dlist **head, Dlist **tail, int data);
int addition(Dlist *tail1, Dlist *tail2, Dlist **head_res, Dlist **tail_res);
int subtraction(Dlist *tail1, Dlist *tail2, Dlist **head_res, Dlist **tail_res);
int multiplication(Dlist *tail1, Dlist *tail2, Dlist **head_res, Dlist **tail_res);
int division(Dlist *head1, Dlist *head2,Dlist *tail1, Dlist *tail2, Dlist **head_res,Dlist **tail_res);
int compare_list(Dlist *head1, Dlist *head2);
int print(Dlist *head);
int check_operator(char ch);
int check_number(char *str);
int list_length(Dlist *head);
void remove_unwanted_zeros(Dlist **head, Dlist **tail);
void delete_list(Dlist **head, Dlist **tail);

#endif