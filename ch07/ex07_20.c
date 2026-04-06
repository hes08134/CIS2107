// ex07_20.c
// what does this program do?
#include <stdio.h>
#define SIZE 80

size_t mystery2(const char *s); // prototype

int main(void)
{
   char string[SIZE]; // create char array

   puts("Enter a string: ");
   scanf("%79s", string); 
   printf("%d\n", mystery2(string));
} 

// What does this function do?
size_t mystery2(const char *s) 
{
   size_t x; // counter

   // loop through string
   for (x = 0; *s != '\0'; ++s) {
      ++x;
   } 

   return x;
}