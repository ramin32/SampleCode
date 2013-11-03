/**********************************************************************************
 * find_longest_palindrome.c
 *
 * Finds the longest palindrome from a string given
 * as the second argument on the command line.
 *
 *   OUTPUT:
 *   [ramin@home c_programs]$ ./a.out kldsfsedudejdfmooooomlkjsmomsakmomdgksahdf
 *   mooooom
 *
 * Author:
 * Ramin Rakhamimov
 * ramin32 at gmail dot com
 * http://raminrakhamimov.com
 * ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_max(int *arr,int num){
    int index=0;
    int i;
    for(i=1;i<num;i++)
        if(arr[index] < arr[i])
            index = i;
    return index;
}

int main(int argc,char **argv){
    if(argc != 2){
        fprintf(stderr,"Usage: %s <string>\n",argv[0]);
        exit(1);
    }
    int i,count;

    int size = strlen(argv[1]);
    int *index_array = malloc(sizeof(int)*size);

    for(i=0;i<size;i++){
        count=0;
        while( (i-count) >= 0 && (i+count) < size){
            if(argv[1][i-count] != argv[1][i+count]){
                break;
            }
            index_array[i] = count;
            count++;
        }
    }

    int max_index = find_max(index_array,size);

    for(i = max_index - index_array[max_index];i<=max_index+index_array[max_index];i++)
        putchar(argv[1][i]);
    puts("");
}
