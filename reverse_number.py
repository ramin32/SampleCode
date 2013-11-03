####################################################
#!/usr/bin/env python
# Python implementation of reverse_number.c
# 
# Author:
# Ramin Rakhamimov
# ramin32 at gmail dot com
# http://raminrakhamimov.com
###################################################

import sys

def power_of_ten(n):
    power = 1;
    while(n):
        n = n/10
        power = power*10 
    return power/10

def reverse(n):
    reversed = 0
    while(n):
        reversed = reversed + ((n%10)* power_of_ten(n))
        n = n/10
    return reversed

print sys.argv[1]
print reverse(int(sys.argv[1]))

