#################################################################
# int_palin.py
# 
# Counts interesting palindromic subranges* for each range listed 
# in an input file.
#
# *An interesting palindromic subrange is a range of numbers where
# there are even amount of palindromic occurances, ie: (33,44). 
#
# Input:
#	1 2
#	1 7
#	87 88
#	
# Output:	
#	1
#	12
#	1
#
# Author:
# Ramin Rakhamimov
# ramin32 AT gmail DOT com
# http://raminrakhamimov.com
################################################################
import sys
from itertools import combinations, chain

def palindrome(s):
    return s == s[::-1]

def count_palindromes(start, end):
    return sum([palindrome(str(i)) for i in xrange(start, end + 1)])

def even_palindromes(start, end):
    return count_palindromes(start, end) % 2 == 0

def interesting_ranges(ranges):
    return sum(even_palindromes(*r) for r in ranges)

def main():
    with open(sys.argv[1], 'rb') as source_file:
        for line in source_file:
            start, end = line.split()
            numbers = xrange(int(start), int(end) + 1)
            ranges = chain(zip(numbers, numbers), combinations(numbers, 2))
            print interesting_ranges(ranges)

if __name__ == '__main__': main()
