/***************************************************************
 * bit_counter.c
 *
 * Counts the number of bits that are on in a integer given
 * on the command line.
 *
 *   OUTPUT:
 *   ramin@debian:~/c_programs$ ./bit_counter 5
 *   5 has 2 bits turned on.
 *   ramin@debian:~/c_programs$ ./bit_counter 6
 *   6 has 2 bits turned on.
 *   ramin@debian:~/c_programs$ ./bit_counter 10
 *   10 has 2 bits turned on.
 *   ramin@debian:~/c_programs$ ./bit_counter 16
 *   16 has 1 bits turned on.
 *   ramin@debian:~/c_programs$ ./bit_counter 15
 *   15 has 4 bits turned on.
 *   ramin@debian:~/c_programs$ ./bit_counter 3
 *   3 has 2 bits turned on.
 * 
 * Author:
 * Ramin Rakhamimov
 * ramin32 at gmail dot com
 * http://raminrakhamimov.com
 * ************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    int numb = atoi(argv[1]);
    int orig = numb;
    int count = 0;
    int bit_value = 1;

    if(argc != 2){
        fprintf(stderr,"Usage: %s <numb>\n",argv[0]);
        exit(1);
    }

    while(numb > 0){
        if(numb & 1)
            count++;
        numb >>= 1;
    }

    printf("%d has %d bits turned on.\n",orig,count);
}

