/******************************************************************************
 * count_sort.c
 *
 * A C implementation of counting sort found in CLR (section 8.2, 2nd edition)
 * Note: Array sizes are stored in first index.
 *
 *      OUTPUT:
 *	ramin@desktop:~$ gcc count_sort.c && ./a.out 
 *	original array:
 *	9 2 3 4 3 2 2 4 5 1 3 4 
 *	c: 
 *	0 0 0 0 0 0 0 0 0 
 *	c with counts:
 *	1 3 3 3 1 0 0 0 1 
 *	c after processing:
 *	1 4 7 10 11 11 11 11 12 
 *	b sorted:
 *	1 2 2 2 3 3 3 4 4 4 5 9 
 *	
 * Author:
 * Ramin Rakhamimov
 * ramin32 at gmail dot com
 * http://raminrakhamimov.com
 *****************************************************************************/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int find_max(int *);
void print_array(char *, int *);
int* create_hash_table(int *);

int main(int argc, char** argv)
{
    int a[] = {-1111,9,2,3,4,3,2,2,4,5,1,3,4};
    a[0] = sizeof(a) / sizeof(int); 
    print_array("original array:", a);
    int *c = create_hash_table(a);
    print_array("c: ", c);
    int i;

    for(i = 1; i < size(a); i++)
        c[a[i]]++;
    print_array("c with counts:", c);
    for(i = 2; i < size(c); i++)
        c[i] = c[i] + c[i - 1];
    print_array("c after processing:", c);

    int *b = create_hash_table(c);

    for(i = 1; i < size(a); i++)
    {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }
    print_array("b sorted:", b);

}

int size(int *a)
{
    return a[0];
}

void print_array(char *str, int a[])
{
    int i;
    puts(str);
    for(i = 1; i < size(a); i++)
        printf("%d ",a[i]);
    printf("\n");
}

int find_max(int a[])
{
    int max = a[1];
    int i;
    for(i = 2; i < size(a); i++)
        if(max < a[i])
            max = a[i];
    return max;
}

int *create_hash_table(int *a)
{
    int size = find_max(a) + 1; 
    int *result = malloc(sizeof(int) * size);
    result[0] = size;
    int i;
    for(i = 1; i < size; i++)
        result[i] = 0;
    return result;
}
