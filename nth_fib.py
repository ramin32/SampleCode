#####################################
# nth_fib.py
# Returns the nth fibannaci number
#
# Author:
# Ramin Rakhamimov
# ramin32@gmail.com
# http://raminrakhamimov.com
#####################################
import sys

fibs = [0,1]
def fib(n):
    global fibs
    if n > len(fibs) - 1:
        fibs.append(fibs[-1] + fibs[-2])
        return fib(n)
    return fibs[n]

print fib(int(sys.argv[1])-1)

