/* Header file */

#ifndef __TREE__
#define __TREE_


#include <stdlib.h>
#include <stdio.h>
#include <errno.h>


struct node {
   /* data */
   void *address;
   size_t length;
   char *location;
   double timestamp;

   int free;

   /* used for tree */
   struct node *left,
               *right,
               *parent;
};


/*Tree  functions */
struct node *insert(struct node *root, struct node *n);
struct node *create_node(void *address, size_t length, char *location, double timestamp);
struct node *isInTree(struct node *root, void *address);
void print_tree(struct node *root);
#endif
