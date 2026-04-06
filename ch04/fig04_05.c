// Fig. 4.5: fig04_05.c  
// Summation with for
#include <stdio.h>

int main(void)
{
   unsigned int sum = 0; // initialize sum

   for (unsigned int number = 2; number <= 100; number += 2) {
      sum += number; // add number to sum          
   }

   printf("Sum is %u\n", sum); 
}
