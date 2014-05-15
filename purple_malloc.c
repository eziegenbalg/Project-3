/* Main */

#include "tree.h"
#include "purple_malloc.h"

void main()
{
 void *tmp;
 struct node *root = create_node(tmp, 1023, tmp, 10);
 
 insert(root, create_node(tmp, 1022, tmp, 11));
 insert(root, create_node(tmp, 1021, tmp, 12));
 insert(root, create_node(tmp, 1024, tmp, 13));
 insert(root, create_node(tmp, 1025, tmp, 14));
 insert(root, create_node(tmp, 1032, tmp, 15));
 insert(root, create_node(tmp, 1026, tmp, 16));

 slug_memstat(root);
}

void slug_malloc(void) {

}
void slug_free();

void slug_memstat(struct node *root) 
{
 if(root == NULL) return;

 slug_memstat(root->left);
 printf("=== Node @ %p Color: %i ===\nAddress: %p\nLength: %i\n"
        "Location: %p\nTimestamp: %lld\n"
        "===========================\n", 
        root, root->color, root->address, root->length, root->location, (long long) root->timestamp); 
 slug_memstat(root->right);
}

