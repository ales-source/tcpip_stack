#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "linked_list.h"

#define ALLOC_NEW_ELEMENT(elem) ((elem) = malloc(sizeof(element_t)), assert(elem))
#define FREE_ELEMENT(elem) (free(elem))


void linked_list_init()
{
    head = NULL;
    tail = NULL;
}

void linked_list_add_before(int data)
{
    element_ptr_t elem;
    ALLOC_NEW_ELEMENT(elem);

    elem->data = data;
    elem->next = head;
    elem->prev = NULL;
    
    if (head == NULL)
    {
        tail = elem;
    }
    else
    {
        head->prev = elem;
    }
    
    head = elem;
}

void linked_list_add_next(int data)
{
    element_ptr_t elem;
    ALLOC_NEW_ELEMENT(elem);

    elem->data = data;

    if (head == NULL)
    {
        head = elem;
    }
    else 
    {
        elem->prev = tail;
        elem->next = NULL;
        tail->next = elem;
    }
    
    tail = elem;
}

element_ptr_t linked_list_find_element(int data)
{
    element_ptr_t curr = head;

    while (curr != NULL)
    {
        if (curr->data == data)
        {
            return curr;
        }

        curr = curr->next;
    }

    return NULL;
}

void linked_list_remove_element(int data)
{
    element_ptr_t curr = linked_list_find_element(data);

    if (curr == head)
    {
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else 
        {
            head = head->next;
            head->prev = NULL;
            head->next = head->next;
        }
    }
    else if (curr == tail)
    {
        tail = tail->prev;
        tail->prev = tail->prev;
        tail->next = NULL; 
    }
    else 
    {
        element_ptr_t left = curr->prev;
        element_ptr_t right = curr->next;
        
        left->next = right;
        right->prev = left;
    }

    FREE_ELEMENT(curr);
}

int get_list_count()
{
    int count = 0;
    element_ptr_t curr;
    curr = head;

    while(curr != NULL)
    {
        count++;
        curr = curr->next;
    }

    return count;
}

void print_from_head_to_tail()
{
    element_ptr_t curr;
    curr = head;

    do
    {
        printf("%d\n", curr->data);
        curr = curr->next;

    } while(curr != NULL);

}
