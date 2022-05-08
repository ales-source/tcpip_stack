#ifndef __LINKED_LIST__
#define __LINKED_LIST__

/********************************************************************************************/
/*                                                                                          */
/*                                                                                          */
/*              400                           600                           800             */
/*      -------------------           -------------------           -------------------     */
/*      |     |     |     |           |     |     |     |           |     |     |     |     */
/*  |-- |  0  |  1  | 600 | ------->  | 400 |  5  | 800 | ------->  | 600 |  7  |  0  | --| */
/*  --  |     |     |     |           |     |     |     |           |     |     |     |  -- */
/*  -   -------------------           -------------------           -------------------   - */
/*       prev         next             prev         next             prev         next      */
/*               |                                                                          */
/*         ------|                                                                          */
/*         |                                                                                */
/*      -------                                                                             */
/*      |     |  head                                                                       */
/*      | 400 |                                                                             */
/*      |     |                                                                             */                                                                                   
/*      -------                                                                             */
/*                                                                                          */
/********************************************************************************************/

/********************************************************/
/* Initializing head:                                   */  
/*   struct node *head = malloc(sizeof(struct node));   */
/*   head->prev = null;                                 */
/*   head->next = null;                                 */
/*   head->data = data value                            */
/********************************************************/

/* Foward Declarations */

typedef struct element element_t;
typedef struct element * element_ptr_t;

void linked_list_init();

void linked_list_add_before(int data);

void linked_list_add_next(int data);

element_ptr_t linked_list_find_element(int data);

void linked_list_remove_element(int data);

void linked_list_clear();

int get_list_count();

/*************************/

static element_ptr_t head;
static element_ptr_t tail;

struct element
{
    int data;
    element_t *prev;  //Pointer to the previous node in Linked List
    element_t *next;  //Pointer to the next node in Linked List
};



/******/
#if 0
void
glthread_add_next(glthread_t *base_glthread, glthread_t *new_glthread);

void
glthread_add_before(glthread_t *base_glthread, glthread_t *new_glthread);

void
remove_glthread(glthread_t *glthread);

void
init_glthread(glthread_t *glthread);

void
glthread_add_last(glthread_t *base_glthread, glthread_t *new_glthread);
void
delete_glthread_list(glthread_t *base_glthread);

unsigned int 
get_glthread_list_count(glthread_t *base_glthread);
#endif
/********/

#endif