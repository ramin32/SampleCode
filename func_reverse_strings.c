/*****************************************************************
 * func_reverse_string.c
 * 
 * Reverses the order of the command line arguments
 * using an in-place reverse algorithm
 *
 * OUTPUT:
 *    $ func_reverse_string hello world, is it a nice day?
 *    day? nice a it is world, hello
 *
 * Author:
 * Ramin Rakhamimov
 * ramin32 at gmail dot com
 * http://raminrakhamimov.com
 ****************************************************************/
#include <stdio.h>
#include <stdlib.h>

void swap(char **str1,char **str2){
    char *temp = *str1;
    *str1 = *str2;
    *str2  = temp;
}

void reverse_strings(char **strings,int num){
    int i;
    for(i=1;i<num/2+1;i++)
        swap(strings+i,strings+num-i);
    
}

print_all(char **strings,int num){
    int i;
    for(i=1;i<num;i++)
        printf("%s ",strings[i]);
    puts("");
}

int main(int argc,char **argv){
    if(argc <= 1 ){
        printf("Not enough arguments!\n");
        exit(1);
    }

    reverse_strings(argv,argc);

    print_all(argv,argc);
}

