#include "apc.h"

Status addition(Dlist **head1, Dlist **head2, Dlist **tail1, Dlist **tail2)
{
    Dlist *headR = NULL;
    Dlist *tailR = NULL;

    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    int data, dataR;
    int carry = 0;

    while(temp1 != NULL || temp2 != NULL)
    {
        data = carry;

        if(temp1 != NULL)
        {
            data = data + temp1->data;
            temp1 = temp1->prev;
        }

        if(temp2 != NULL)
        {
            data = data + temp2->data;
            temp2 = temp2->prev;
        }

        dataR = data % 10;
        carry = data / 10;

        insert_first(&headR, &tailR, dataR);
    }

    if(carry)
    {
        insert_first(&headR, &tailR, carry);
    }

    print_list(headR);

    return e_success;
}

Status insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *newNode = malloc(sizeof(Dlist));
    if(newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return e_failure;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if(*head == NULL)
    {
        *head= newNode;
        *tail= newNode;
        return e_success;
    }

    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
    return e_success;

}