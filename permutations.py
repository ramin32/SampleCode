###################################################
# permutations.py
#
# Desc: Prints permutations of each line in a file.
#
# Input: 
#   abc
#   123
#   bc
# Output:
#   abc,bac,bca,acb,cab,cba
#   123,213,231,132,312,321
#   bc,cb
#
# Author:
# Ramin Rakhamimov
# http://raminrakhamimov.com
# ramin32 AT gmail DOT com
###################################################
import sys

def insert_everwhere(iterable, item):
    for i in xrange(len(iterable)+1):
        new_list = list(iterable)
        new_list.insert(i, item)
        yield new_list

 
def permutations(iterable):
    if len(iterable) <= 1:
        yield iterable
        raise StopIteration

    sub_permutations = permutations(iterable[1:])
    first = iterable[0]

    for sub_permutation in sub_permutations:
        for perm in insert_everwhere(sub_permutation, first):
            yield ''.join(perm)
        
if __name__ == '__main__':
    with open(sys.argv[1], 'rb') as source:
        for line in source:
            print ','.join(permutations(line.strip()))
        

