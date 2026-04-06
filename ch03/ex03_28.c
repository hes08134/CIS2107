#include <stdio.h>

// Using Conditional or Ternary Operator (?:) in C
// condition ? value_if_true : value_if_false

int main( void )
{
   unsigned int count = 1; // initialize count 

   while ( count <= 10 ) { // loop 10 times 

      // output line of text 
      puts( count % 2 ? "****" : "++++++++" );
      ++count; // increment count 
   } // end while 
} // end function main 


