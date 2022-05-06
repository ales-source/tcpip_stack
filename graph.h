#ifndef __GRAPH__
#define __GRAPH__

#include "gthread/glthread.h"

#define IF_NAME_SIZE    10
#define NODE_NAME_SIZE  10
#define MAX_IF_PER_NODE  4

/********************************************************/
/*                                                      */
/*  node_t                                              */
/*     ------  eth0/0      eth0/1 ------                */
/*     | R0 | ------------------  | R1 |                */
/*     ------        link_t       ------                */
/*  interface_t                     |                   */
/*        | eth0/4                  | eth0/2            */
/*        |                         |                   */
/*        |                         |                   */
/*        |    eth0/5       eth0/3  |                   */
/*        |         ------          |                   */
/*         -------- | R2 |  --------                    */
/*                  ------                              */
/*                                                      */
/********************************************************/

/* Foward declarations */
typedef struct node_t node;
typedef struct interface_t interface;
typedef struct link_t link;
typedef struct graph_t graph;

typedef struct graph_t
{
    char topology_name[32];
    glthread_t node_list; 
};

typedef struct node_t
{
    char name[NODE_NAME_SIZE];
    interface * interfaces[MAX_IF_PER_NODE];
    glthread_t grapg_glue;
};

typedef struct link_t
{
    interface if_1;
    interface if_2;
    unsigned int cost;
};

typedef struct interface_t
{
    char name[IF_NAME_SIZE];
    node *owning_node;
    link *link;    
};

#endif // __GRAPH__