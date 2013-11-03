/****************************************
 * fib.c
 *
 * Optimized version of recursive fib.
 * Runs in O(n) time.
 *
 * Author:
 * Ramin Rakhamimov
 * ramin32 at gmail dot com
 * http://raminrakhamimov.com
 ****************************************/

#include <stdio.h>

int fib(int);
int fib_helper(int, int, int);

int main(int argc, char** argv)
{
    printf("%d\n", fib(atoi(argv[1])));
}

int fib(int n)
{
    int prev1 = 0;
    int prev2 = 1;
    return fib_helper(n, prev1, prev2);
}

int fib_helper(int n, int prev1, int prev2)
{
    if(n <= 0)
        return prev2;

    return fib_helper(n-1, prev2, prev1 + prev2);
}

