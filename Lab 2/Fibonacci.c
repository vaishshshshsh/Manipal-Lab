#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
unsigned int opcount= 0;
unsigned int fibbonacci(unsigned int n) {

   if(n == 0){
      opcount++;
      return 0;

   } else if(n == 1) {
      opcount++;
      return 1;

   } else {
       opcount++;
      return (fibbonacci(n-1) + fibbonacci(n-2));

   }

}


int main() {
   unsigned int n = 70;
   int i;


   printf("Fibbonacci of %d: " , n);
	clock_t start, endl;
  double cpu_time;
    start = clock();
   for(i = 0;i<n;i++) {
      printf("%d ",fibbonacci(i));
   }
   endl = clock();
  cpu_time = (double)(endl-start)/CLOCKS_PER_SEC;
  printf("\n time taken: %e", cpu_time);
  printf("Number of operations : %d\n", opcount);

  return 0;
}