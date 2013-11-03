########################################################################
# all_subsets.py
#
# Description: Prints out all possible subsets of an arrayay. Uses a binary 
#	       counter to extract combinations from the original arrayay by 
#	       using bitwise AND between the index and each on bit.
#
# Usage:       $ python all_subsets.py
#	       [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3], [4],
# 	       [1, 4], [2, 4], [1, 2, 4], [3, 4], [1, 3, 4], [2, 3, 4], 
#	       [1, 2, 3, 4]]
#
# Author:
# Ramin Rakhamimov
# ramin32 AT gmail DOT com
# http://raminrakhamimov.com
#######################################################################

def extract_subset_by_bits(array, on_bits):
	return [array[i] for i in xrange(len(array)) if (2**i) & on_bits]

def all_subets(array):
	bits_for_array = 2**len(array)
	return [extract_subset_by_bits(array, i) for i in xrange(bits_for_array)]

if __name__ == '__main__':
	print all_subets([1,2,3,4])

