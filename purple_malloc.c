#include <sys/time.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tree.h"
#include "purple_malloc.h"


struct timeval tv;
struct node *root;

mem_info info;
int exit_handler = 0;


double mean()
{
   if(info.total_allocs > 0) return (double)(info.total_size/info.total_allocs);
   return 0.0;
}

double standard_dev()
{
   int tmp[MAX_ALLOCS] = {0};
   double tmp_mean = mean();
   double total = 0.0;
   int i;
   for(i = 0; i < info.index; ++i){
      tmp[i] = pow((double)(info.lens[i] - tmp_mean), 2.0);
   }

   for(i = 0; i < info.index; ++i){
      total += (double)tmp[i];
   }

   total = total / info.index;
   total = sqrt(total);

   return total;
}


void *slug_malloc(size_t size, char *WHERE) 
{   
   void *tmp;
   double timestamp = 0;

   /* Exit if allocating over 128MiB */
   if(size > MAX_SIZE) { 
      fprintf(stderr, "Cannot allocate more than 128MiB\n");
      exit(EXIT_FAILURE);
   }

   /*Print out error if allocating size of 0 */
   if(size == 0) {
      fprintf(stderr, "Malloced size of 0\n");
   }

   /* Install exit_handler if not installed*/
   if(exit_handler == 0) {
      atexit(slug_memstat);
      exit_handler = 1;
   }

   /* Get current time */
   if(!gettimeofday(&tv, NULL)) {
      timestamp = tv.tv_sec * 1e6 + tv.tv_usec;
   }

   /* allocated memory */
   tmp = malloc(size);
   
   /* insert data tree */
   if(root == NULL){
      root = create_node(tmp,size,WHERE,timestamp);
   }else{
      insert(root, create_node(tmp, size, WHERE, timestamp)); 
   }
   
   info.total_allocs++;
   info.active_allocs++;
   info.total_size += size;
   info.active_size += size;
   info.lens[info.index] = size;
   info.index++;
   return tmp;
}
void slug_free(void *addr, char *WHERE) 
{
   if(isInTree(root,addr) == 1){
       /* removeFromTree(addr)*/
     }   
   free(addr);
   info.active_allocs--;
}

void slug_memstat(void) 
{
   print_tree(root);
   /*if((info.count - 1) == info.index){ */
   printf("Total allocations: %d\n" , info.total_allocs);
   printf("Active allocations: %d\n\n" , info.active_allocs);

   printf("Total size allocated: %.0f\n" , info.total_size);
   printf("Active size allocated: %.0f\n\n" , info.active_size);

   printf("Mean of total allocs: %.2f\n", mean());
   printf("Standard Deviation: %0.2f\n", standard_dev());
   info.count = 0;
   /*}*/

}

