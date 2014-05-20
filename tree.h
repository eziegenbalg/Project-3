/* Header file */

#ifndef __TREE__
#define __TREE_


#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define BLACK 0
#define RED   1

struct node {
  /* data */
  void *address;
  size_t length;
  char *location;
  double timestamp;
 
  /* used for tree */
  int color;
  struct node *left,
              *right,
              *parent;
};


/* Red Black functions */
struct node *insert(struct node* root, struct node *n);
struct node *create_node(void *address, size_t length, char *location, double timestamp);

#endif
