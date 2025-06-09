#!/usr/bin/python3
"""
asdsadsadasdsa
"""


def validUTF8(data):
    """
    sadsadasdsa
    """
    cantidad = 0

    for byte in data:
        byte = byte & 0xFF

        if cantidad == 0:
            if (byte >> 5) == 0b110:
                cantidad = 1
            elif (byte >> 4) == 0b1110:
                cantidad = 2
            elif (byte >> 3) == 0b11110:
                cantidad = 3
            elif (byte >> 7) == 0b0:
                cantidad = 0
            else:
                return False
        else:
            if (byte >> 6) != 0b10:
                return False
            cantidad -= 1

    return cantidad == 0
