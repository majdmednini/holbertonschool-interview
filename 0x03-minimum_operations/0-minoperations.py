#!/usr/bin/python3
"""
this calculates the fewest number of operations needed
"""


def minOperations(n):
    """sum of their prime factors of each number"""

    num = 0
    operation = 2
    int1 = n
    int2 = n

    if type(n) != int or n < 1:
        return 0

    while (True):
        int1 = int2 / operation

        if int2 == 1:
            break

        if not int1.is_integer():
            operation += 1
        elif int1.is_integer():
            num += operation
            operation = 2
            int2 = int1
        elif int2 == operation:
            num += operation
            break

    return num
