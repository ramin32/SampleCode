/********************************************************************
 * play_with_stack.c
 *
 * Modifies a variable of the previous calling functon without
 * passing any arguments by referencing the address of a local variable
 * and moving up the stack to the exact address of the other variable.
 *
 *      OUTPUT
 *      [ramin@home ~]$ gcc play_with_stack.c && ./a.out 
 *      0xbfd55e44
 *      x in bar: 5, before call.
 *      0xbfd55e44
 *      x in bar: 599999, after call.
 *
 * Author:
 * Ramin Rakhamimov
 * ramin32 at gmail dot com
 * http://raminrakhamimov.com
 * ******************************************************************/
#include <stdio.h>
#define DIFFERENCE 8

void foo(){
    int y;
    printf("%p\n",(void *)(&y+DIFFERENCE));
    *(&y+DIFFERENCE) = 599999;
}

void bar(){
    int x = 5;
    printf("%p\n",(void *)(&x));
    printf("x in bar: %d, before call.\n",x);
    foo();
    printf("x in bar: %d, after call.\n",x);

}

int main(){
    bar();
    return 0;
}
