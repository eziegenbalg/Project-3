#include <stdlib.h>
#include <stdio.h>
#include "purple_malloc.h"
//#include "tree.h"

#define FUNCTIONIZE(a,b)   a(b)
#define STRINGIZE(a)       #a
#define INT2STRING(i)      FUNCTIONIZE(STRINGIZE, i)
#define FILE_POS           __FILE__ ":" INT2STRING(__LINE__)



int main(int argc, char **argv) {
   void *tmp = slug_malloc(5 * sizeof(char), FILE_POS);
   void *tmp1 = slug_malloc(10 *sizeof(int), FILE_POS);
  // void *tmp2 = slug_malloc(1 * sizeof(struct node*), FILE_POS);
   slug_free(tmp,FILE_POS);
   slug_free(tmp1,FILE_POS);
//   slug_free(tmp2,FILE_POS);
   return 0;
}

