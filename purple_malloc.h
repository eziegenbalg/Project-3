#ifndef __PURPLE_MALLOC__
#define __PURPLE_MALLOC__

#define FUNCTIONIZE(a,b)   a(b)
#define STRINGIZE(a)       #a
#define INT2STRING(i)      FUNCTIONIZE(STRINGIZE, i)
#define FILE_POS           __FILE__ ":" INT2STRING(__LINE__)


#define MAX_ALLOCS 100
#define MAX_SIZE 134217728

typedef struct{
   int total_allocs;
   int active_allocs;
   double total_size;
   double active_size;
   int lens[MAX_ALLOCS];
   int index;
   int count;
}mem_info;

void *slug_malloc(size_t size, char *WHERE);
void slug_free(void *addr, char *WHERE);
void slug_memstat(void);

#endif
