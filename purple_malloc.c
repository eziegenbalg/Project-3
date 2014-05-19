#include <sys/time.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

struct timeval tv;
extern struct node *root;

void *slug_malloc(size_t size, char *WHERE) {
   if(!gettimeofday(&tv, NULL)) {
      long timestamp = (long)(tv.tv_sec * 1e6 + tv.tv_usec);
      /*printf("Malloced size of %zu from %s at %ld\n", size, WHERE, timestamp); */
      void *tmp = malloc(size);
      insert(root, create_node(tmp, size, 0, timestamp)); 
      return tmp;
   }
   return NULL;
}
void slug_free(void *addr, char *WHERE) {
   /*if(isInTree(addr)){
        removeFromTree(addr)
     }*/   
   free(addr);
}

void slug_memstat(struct node *root) 
{
   if(root == NULL) return;
   slug_memstat(root->left);
   printf("=== Node @ %p Color: %i ===\nAddress: %p\nLength: %i\n"
          "Location: %p\nTimestamp: %lld\n"
          "===========================\n", 
          root, root->color, root->address, root->length,
          root->location, (long long) root->timestamp); 

   slug_memstat(root->right);
}

