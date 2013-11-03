/*******************************************************
 * reverse_string.c
 *
 * Reverses the first string given on the command line.
 *
 * Author:
 * Ramin Rakhamimov
 * ramin32 at gmail dot com
 * http://raminrakhamimov.com
 ******************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a,char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

char *reverse(char *str) {
    char *start = str;
    char *end = str + strlen(str)-1;

    while(start < end)
        swap(start++,end--);
    return str;
	
}
int main(int argc,char **argv) {

    if(argc != 2){
        printf("Usage %s <string>\n",argv[0]);
        exit(1);
    }
	
    char *input = argv[1];
    puts(reverse(input));
}
    




    

