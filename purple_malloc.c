#include <sys/time.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

#define MAX_SIZE 100000

struct timeval tv;
struct node *root;

void *slug_malloc(size_t size, char *WHERE) {
   
   void *tmp;
   long timestamp = 0;
   
   if(size > MAX_SIZE) { 
      printf("Cannot allocate more than 128MiB\n");
      exit(1);
   }

   if(size == 0) {
      printf("Malloced size of 0\n");
   }

   if(!gettimeofday(&tv, NULL)) {
      timestamp = (long)(tv.tv_sec * 1e6 + tv.tv_usec);
   }
   tmp = malloc(size);
   if(root == NULL){
      root = create_node(tmp,size,0,timestamp);
   }
   else{
      insert(root, create_node(tmp, size, 0, timestamp)); 
   }
   slug_memstat();
   printf("\n\n");
   return tmp;
}
void slug_free(void *addr, char *WHERE) {
   if(isInTree(root,addr) == 1){
       /* removeFromTree(addr)*/
     }   
   free(addr);
   
}

void slug_memstat(void) 
{
   /*if(root == NULL) return;
   slug_memstat(root->left);
   printf("=== Node @ %p Color: %i ===\nAddress: %p\nLength: %i\n"
          "Location: %s\nTimestamp: %ld\n"
          "===========================\n", 
          root, root->color, root->address, root->length,
          root->location, (long) root->timestamp); 

   slug_memstat(root->right);*/
   print_tree(root);
}

