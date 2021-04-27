#include "ft_printf.h"
#include <limits.h>


int main (void)
{
    // int i = 0;
    // int j = 0;
    // char *str = "je suis un test";
    // char *pointer = "little";

    //  i = ft_printf("je suis un test  : %*c", -2, '0');
    //  printf("\nret = %d\n", i);

     ft_printf(" %p %p \n", -2147483648, LONG_MAX);
     
    

        //    int number    =  5;
      

      printf(" %p %p \n", LONG_MIN, LONG_MAX);

      ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
      printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);

      ft_printf(" %p \n", -2147483647);
    printf(" %p \n", 16);


    return 0;
}