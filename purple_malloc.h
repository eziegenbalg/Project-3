#ifndef __PURPLE_MALLOC__
#define __PURPLE_MALLOC__

void *slug_malloc(size_t size, char *WHERE);
void slug_free(void *addr, char *WHERE);
void slug_memstat(struct node *root);

#endif
