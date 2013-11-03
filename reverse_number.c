/*****************************************************************
 * reverse_number.c
 *
 * Reverses a number given from the command line using 
 * only numerical operations.
 * 
 * OUTPUT:
 *      [ramin@home c_programs]$ ./a.out 723895238
 *      832598327
 *
 *
 * Author:
 * Ramin Rakhamimov
 * ramin32 at gmail dot com
 * http://raminrakhamimov.com
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>

long long power_of_ten(int n){
    long power = 1;
    while(n/=10)
        power *= 10;
    return power;
}

int reverse_number(int num){
    int reversed_number = 0;
    do{
        reversed_number += num%10*power_of_ten(num);
    }while(num/=10);
    return reversed_number;
}
int main(int argc,char **argv){
    if(argc != 2){
        fprintf(stderr,"Usage: %s <number>\n",argv[0]);
        exit(1);
    }

    printf("%d\n",reverse_number(atoi(argv[1])));
    
}

