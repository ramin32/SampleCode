#!/usr/bin/env python2
###############################################################
# find_summing_numbers.py
#
# Description: 
# find 2 indeces within an array that sum up to a given number.
#
# Running Time:
# O(n)
#
# Usage:
#    $ python2 find_suming_numbers.py 
#    Random Array: [34, -35, 61, 19, -18, -43, 66, 77, -41, 84, -66, -70, -29, 
#    78, -85, -3, -40, 53, -31, -21, 84, -57, 33, 58, -99, 90, 73, 22, -9, 91, 
#    83, 70, 84, 46, 88, -45, -92, -11, 72, -95, 67, 100, -72, 36, 39, -58, -4, 
#    -41, 21, -23, -99, 7, -100, 51, -88, 63, 77, 60, 12, 42, 56, -28, 73, 73, 
#    -49, -51, -89, -95, 42, 37, 40, 5, -87, -4, 53, -9, -95, -96, -61, -73, 
#    -55, 48, 13, 65, -64, -18, 3, -56, 49, -17, -27, 14, 70, 12, -49, 97, 3, 
#    -45, 23, 22]
#    12 pairs have been found.
#    (2, 37): 61 + -11 = 50
#    (7, 90): 77 + -27 = 50
#    (8, 29): -41 + 91 = 50
#    (13, 61): 78 + -28 = 50
#    (15, 74): -3 + 53 = 50
#    (16, 25): -40 + 90 = 50
#    (26, 49): 73 + -23 = 50
#    (29, 47): 91 + -41 = 50
#    (40, 89): 67 + -17 = 50
#    (43, 91): 36 + 14 = 50
#    (49, 63): -23 + 73 = 50
#    (69, 82): 37 + 13 = 50
#    
#
# Author:
# Ramin Rakhamimov
# ramin32 at gmail dot com
# http://raminrakhamimov.com
#################################################################
import random

def find_summing_numbers(array, n):
    result = []
    index_map = { item: index for index, item in enumerate(array) }

    processed_indices = {}
    for index, item in enumerate(array):
        processed_indices[index] = True
        num_to_find = n - item
        if num_to_find != item and index_map.get(num_to_find, False) not in processed_indices:
            result.append( (index, index_map[num_to_find]) )
            processed_indices[index_map[num_to_find]] = True
    return result

def main():
    range = (-100, 100)
    array_size = 100
    array = [random.randint(*range) for i in xrange(array_size)]
    print 'Random Array: %s' % array

    sum = 50
    result = find_summing_numbers(array, sum)
    print '%s pairs have been found.' % len(result)
    for pair in result:
        print '%s: %s + %s = %s' % (pair, array[pair[0]], array[pair[1]], sum)

if __name__ == '__main__':
    main()
