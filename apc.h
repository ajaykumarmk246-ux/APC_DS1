#ifndef HEAD_H
#define HEAD_H

#include<stdio.h>
#include<stdlib.h>

typedef enum{
    e_success,
    e_failure
}Status;

typedef enum{
    e_addition,
    e_subtraction,
    e_multiplication,
    e_division,
    e_unsupported
}OperationType;


typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;


}Dlist;

OperationType check_operation_type(char opt);

Status insert_last(Dlist **head, Dlist **tail,int data);

Status insert_first(Dlist **head, Dlist **tail,int data);

void print_list(Dlist *head);

Status addition(Dlist **head1, Dlist **head2, Dlist **tail1,Dlist **tail2);


Status subtraction(Dlist **head1, Dlist **head2, Dlist **tail1,Dlist **tail2);

int list_compare(Dlist *head1,Dlist *head2);

int data_compare(Dlist *head1,Dlist *head2);

void swap_list(Dlist **head1,Dlist **head2,Dlist **list1,Dlist **list2);



#endif