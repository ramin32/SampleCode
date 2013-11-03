##################################################################################
# combinations.py
#
# Description: Python implementation of the combinationtion algorithm using 
#              bitwise manipulation. Iterates through all bits up to 2^len(list), 
#              selecting elements with matching indeces to bits.
#
# Order complexity: O(n*2^n)
# 
# Usage:
#    $ python2 combinations.py abc
#
#    a
#    b
#    ab
#    c
#    ac
#    bc
#    abc
#
# Author:
# Ramin Rakhamimov
# http://raminrakhaimov.com
# ramin32 AT gmail DOT com
##################################################################################

import sys

def extract_elements(iterable, on_bits):
    return (v for i, v in enumerate(iterable) if 2**i & on_bits)

def combinations(iterable):
    bits = len(iterable) 
    for on_bits in xrange(2**bits):
        yield extract_elements(iterable, on_bits)
        
if __name__ == '__main__':
    for combination in combinations(sys.argv[1]):
        print ''.join(combination)
