/* Header file */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#define BLACK 0
#define RED   1

/* Red Black functions */
struct node *insert();
struct node *create_node(int *address, int length, int *location, time_t timestamp);

struct node {
  /* data */
  int *address;
  int length;
  int *location;
  time_t timestamp;
 
  /* used for tree */
  int color;
  struct node *left,
              *right,
              *parent;
};
