#include <stdlib.h>
#include <stdio.h>
#include "purple_malloc.h"

/*
#define malloc(x)          slug_malloc(x, FILE_POS)
#define free(x)            slug_free(x,FILE_POS)
*/

int main(int argc, char **argv) {
   void *tmp,*tmp1,*tmp2,*tmp3,*tmp4,*tmp5,*tmp6,*tmp7,*tmp8;
   tmp  = malloc(1 * sizeof(int));
   tmp1 = slug_malloc(1 * sizeof(char), FILE_POS);
   tmp2 = slug_malloc(2 *sizeof(char), FILE_POS);
   tmp3 = slug_malloc(3 * sizeof(char), FILE_POS);
   tmp4 = slug_malloc(4 * sizeof(char), FILE_POS);
   tmp5 = slug_malloc(5 * sizeof(char), FILE_POS);
   tmp6 = slug_malloc(6 * sizeof(char), FILE_POS);
   tmp7 = slug_malloc(7 * sizeof(char), FILE_POS);
   tmp8 = slug_malloc(8 * sizeof(char), FILE_POS);
   
   slug_free(tmp,FILE_POS);
   free(tmp);   
   slug_free(tmp1,FILE_POS);
   slug_free(tmp2,FILE_POS);
   slug_free(tmp3,FILE_POS);
   slug_free(tmp4,FILE_POS);
   slug_free(tmp5,FILE_POS);
   slug_free(tmp6,FILE_POS);
   slug_free(tmp7,FILE_POS);
   slug_free(tmp8,FILE_POS);
   return 0;
}

