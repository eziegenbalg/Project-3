/* Header file */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define BLACK 0
#define RED   1

/* Red Black functions */
struct node *insert();
struct node *create_node(void *address, size_t length, char *location, long timestamp);

struct node {
  /* data */
  void *address;
  size_t length;
  char *location;
  long timestamp;
 
  /* used for tree */
  int color;
  struct node *left,
              *right,
              *parent;
};
