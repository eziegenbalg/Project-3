/* This file contains the functions to implement the red-black tree
 * All code is used directly from the main wikipedia page on Red/Black trees 
 */

#include "tree.h"


struct node *insert(struct node *root, struct node *n) 
{
 if(root == NULL) {
  root = n;
  return root;
 }

 if(root->address < n->address)
   root->right = insert(root->right, n);
 if(root->address > n->address)
   root->left = insert(root->left, n);

 return root; 

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

 return n;
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
      printf("=== Node @ %p ===\nAddress: %p\nSize: %i\n"
             "Location: %s\nTimestamp: %0.0f\n"
             "===========================\n",
             root,  root->address, (int)root->length,
             root->location, root->timestamp);
   }
   print_tree(root->right);

   /* Free address and node */
   if(!root->free) {
      free(root->address);
   }

   free(root);
}
