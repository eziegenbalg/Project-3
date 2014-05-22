/* This file contains the functions to implement the red-black tree
 * All code is used directly from the main wikipedia page on Red/Black trees 
 */

#include "tree.h"

void insert_case1(struct node *n);
void insert_case2(struct node *n);
void insert_case3(struct node *n);
void insert_case4(struct node *n);
void insert_case5(struct node *n);

void rotate_right(struct node *n);
void rotate_left(struct node *n);

struct node *uncle(struct node *n);
struct node *grandparent(struct node *n);

struct node *insert(struct node *root, struct node *n) 
{
 if(root == NULL) {
  root = n;
  return root;
 }

 if(root->length < n->length)
   root->right = insert(root->right, n);
 if(root->length > n->length)
   root->left = insert(root->left, n);

 return root; 

}

/*Delete a node from the tree */

void delete_node(struct node *addr){
   /*Case 1: node is only leaf in the tree */
   if(addr->left == NULL/* && addr->right == NULL*/){
      free(addr);
   }

   /*Case 2: node has one child which needs to be connected to the nodes
        parent  */
   if(addr->left != NULL && addr->right == NULL){
      addr->left->parent = addr->parent;
      addr->parent->left = addr->left;
      addr->left = NULL;
      free(addr);
      addr = NULL;
   }
   if(addr->right != NULL && addr->left == NULL){
      addr->right->parent = addr->parent;
      addr->parent->right = addr->right;
      addr->right = NULL;
      addr = NULL;
      free(addr);
   }
   /*Case 3: node has 2 children */
   if(addr->left != NULL && addr->right!= NULL){
      addr->right->parent = addr->left->parent = addr->parent;
      addr->parent->left = addr->left;
      addr->parent->right = addr->right;
      addr->right = addr->left = NULL;
      addr = NULL;
      free(addr);
      }
}

struct node *create_node(void *address, size_t length, char *location, double timestamp)
{
 struct node *n = malloc(sizeof(struct node));
 if(n == NULL) return NULL;

 n->address = address;
 n->length = length;
 n->location = location;
 n->timestamp = timestamp;

 n->parent = NULL;
 n->left = NULL;
 n->right = NULL;
 n->color = RED;

 return n;
}

struct node *grandparent(struct node *n)
{
 if ((n != NULL) && (n->parent != NULL))
  return n->parent->parent;
 else
  return NULL;
}
 
struct node *uncle(struct node *n)
{
 struct node *g = grandparent(n);
 if (g == NULL)
  return NULL; 
 if (n->parent == g->left)
  return g->right;
 else
  return g->left;
}

void insert_case1(struct node *n)
{
 if (n->parent == NULL)
  n->color = BLACK;
 else
  insert_case2(n);
}

void insert_case2(struct node *n)
{
 if (n->parent->color == BLACK)
  return; /* Tree is still valid */
 else;
  insert_case3(n);
}

void insert_case3(struct node *n)
{
 struct node *u = uncle(n), *g;
 
 if ((u != NULL) && (u->color == RED)) {
  n->parent->color = BLACK;
  u->color = BLACK;
  g = grandparent(n);
  g->color = RED;
  insert_case1(g);
 } else {
  insert_case4(n);
 }
}

void insert_case4(struct node *n)
{
 struct node *g = grandparent(n);
 
 if ((n == n->parent->right) && (n->parent == g->left)) {
  rotate_left(n->parent);
 
 /*
 * rotate_left can be the below because of already having *g =  grandparent(n) 
 *
 * struct node *saved_p=g->left, *saved_left_n=n->left;
 * g->left=n; 
 * n->left=saved_p;
 * saved_p->right=saved_left_n;
 * 
 * and modify the parent's nodes properly
 */
 
  n = n->left; 
 
 } else if ((n == n->parent->left) && (n->parent == g->right)) {
  rotate_right(n->parent);
 
 /*
 * rotate_right can be the below to take advantage of already having *g =  grandparent(n) 
 *
 * struct node *saved_p=g->right, *saved_right_n=n->right;
 * g->right=n; 
 * n->right=saved_p;
 * saved_p->left=saved_right_n;
 * 
 */
 
  n = n->right; 
 }
 insert_case5(n);
}

void insert_case5(struct node *n)
{
 struct node *g = grandparent(n);
 
 n->parent->color = BLACK;
 g->color = RED;
 if (n == n->parent->left)
  rotate_right(g);
 else
  rotate_left(g);
}

void rotate_right(struct node *g)
{
 struct node *temp = g->left;

 g->left = temp->right;
 temp->right = g;
}

void rotate_left(struct node *g)
{
 struct node *temp = g->right;

 g->right = temp->left;
 temp->left = g;
}

 
struct node *isInTree(struct node *root,void *addr){
   if(root == NULL){
      return NULL;
   }
   
   if(addr == root->address){
      return root;
   } else {
      if(root->left != NULL)
         return isInTree(root->left,addr);
      if(root->right != NULL)
         return isInTree(root->right,addr);
   }
   return NULL;
}

void print_tree(struct node *root)
{
   if(root == NULL) return;
   print_tree(root->left);
   
   if(!root->free) {
      printf("=== Node @ %p Color: %i ===\nAddress: %p\nLength: %i\n"
             "Location: %s\nTimestamp: %0.0f\n"
             "===========================\n",
             root, root->color, root->address, (int)root->length,
             root->location, root->timestamp);
   }
   print_tree(root->right);

   /* Free address and node */
   if(!root->free) {
      free(root->address);
   }

   free(root);
}
