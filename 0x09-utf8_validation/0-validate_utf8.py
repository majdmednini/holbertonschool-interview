#!/usr/bin/python3
"""UTF-8 encoding"""


def validUTF8(data):
    """Validation"""
    i = 0
    for num in data:
        bin_rep = format(num, '#010b')[-8:]
        if i == 0:
            for bit in bin_rep:
                if bit == '0':
                    break
                i += 1
            if i == 0:
                continue
            if i == 1 or i > 4:
                return False
        else:
            if not (bin_rep[0] == '1' and bin_rep[1] == '0'):
                return False
        i -= 1
    return i == 0