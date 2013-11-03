##########################################################
# vector.py 
#
# Author:
# Ramin Rakhamimov
# ramin32 at gmail dot com
# http://raminrakhamimov.com
##########################################################

"""Basic Vector2d implementation"""
import math

class Vector2d():
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Vector2d(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vector2d(self.x - other.x, self.y - other.y)

    def __mul__(self, constant):
        return Vector2d(self.x * constant, self.y *constant)

    def normalize(self):
        magnitude = self.magnitude()
        self.x /= magnitude
        self.y /= magnitude

    def magnitude(self):
        return math.hypot(self.x, self.y)

    def __str__(self):
        return "<%s, %s>" % (self.x, self.y)

    def __repr__(self):
        return self.__str__()

    def __getitem__(self, i):
        if i == 0:
            return self.x
        elif i == 1:
            return self.y

        else:
            raise IndexError, "Only 0 and 1 are valid indices!"

    def get_list(self):
        return [self.x, self.y]

