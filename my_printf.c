#include <stdio.h>
#include "string.h"
#include <stdlib.h>

// itoa function taken from assignment

/* Convert the integer D to a string and save the string in BUF. If
   BASE is equal to 'd', interpret that D is decimal, and if BASE is
   equal to 'x', interpret that D is hexadecimal. */
void itoa (char *buf, int base, int d)
{
  char *p = buf;
  char *p1, *p2;
  unsigned long ud = d;
  int divisor = 10;
     
  /* If %d is specified and D is minus, put `-' in the head. */
  if (base == 'd' && d < 0)
    {
      *p++ = '-';
      buf++;
      ud = -d;
    }
  else if (base == 'x')
    divisor = 16;
     
  /* Divide UD by DIVISOR until UD == 0. */
  do
    {
      int remainder = ud % divisor;
     
      *p++ = (remainder < 10) ? remainder + '0' : remainder + 'a' - 10;
    }
  while (ud /= divisor);
     
  /* Terminate BUF. */
  *p = 0;
     
  /* Reverse BUF. */
  p1 = buf;
  p2 = p - 1;
  while (p1 < p2)
    {
      char tmp = *p1;
      *p1 = *p2;
      *p2 = tmp;
      p1++;
      p2--;
    }
}



// my implementation of putchar
void my_putchar(char c) {

  extern long write(int, const char *, unsigned long);
  (void) write(1, &c, 1);

}


// my printf function
int my_printf(const char *format, ...) {

  // pointer to individual arguments
  char **arg = (char **) &format;
  int c;
  static char buf[20];
  int count = 0;

  // pointer to format string (%s, %d, etc.)
  void * beg = &format;
  beg += sizeof(char*);
  int i;

  for (i = 0; i < strlen(format); i++) {

    if (format[i] == '%') {

      i++;

      switch (format[i]) {

        // string
        case 's':
          // printf("inside case s\n");

          // increment arg so it points to next argument
          arg++;

          // create pointer to argument
          char * string_ptr = *((char**)arg);
          
          // print it out
          int s;
          for (s = 0; s < strlen(string_ptr); s++) {
            my_putchar(string_ptr[s]);
          }
          break;

        // character
        case 'c':
          // printf("inside case c\n");

          arg++;
          char * char_ptr = *((char**)arg);
          my_putchar(char_ptr[0]);
          break;

        // decimal
        case 'd':
          // printf("inside case d\n");

          arg++;
          itoa(buf, 'd', *((int*)arg));

          int d;
          for (d = 0; d < strlen(buf); d++) {
              my_putchar(buf[d]);
          }
          break;

        // unsigned hex
        case 'x':
          // printf("inside case x\n");

          arg++;
          itoa(buf, 'x', *((int*)arg));

          int x;
          for (x = 0; x < strlen(buf); x++) {
              my_putchar(buf[x]);
          }
          break;
      
        // unsigned integer
        case 'u':
          // printf("inside case u\n");

          arg++;
          unsigned int convert = *((unsigned int*)arg);
          itoa(buf, 'x', convert);


          /*
          // convert hex string to integer value
          // int number = strtol(buf, NULL, 16);

          // printf("strtol is %d\n", strtol("ffff342", NULL, 16));
          // printf("number is %d\n", number);
          */

          int u;
          for (u = 0; u < strlen(buf); u++) {
              // printf("strlen(buf) is %d\n", strlen(buf));
              my_putchar(buf[u]);
          }

          break;

      }

    } else {

      my_putchar(format[i]);
    }

  } // end for loop

my_putchar('\n');
return 0;

}


int main () {



	my_printf("test %s test1 %d%x", "STRING", 5610, 1000);


}






