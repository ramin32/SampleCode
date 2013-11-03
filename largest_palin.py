##########################################################
# largest_palin.py 
#
# Finds the largest palindrome that is a product of 2 
# 3 digit numbers.
#
# Author:
# Ramin Rakhamimov
# ramin32 at gmail dot com
# http://raminrakhamimov.com
##########################################################

def is_palindrome(x):
    return str(x) == str(x)[::-1]

if __name__ == '__main__':
    digit_range = xrange(999,99,-1)  

    palindromes = [i*j for i in digit_range
                       for j in digit_range 
                       if is_palindrome(i*j)]

    print max(palindromes)
