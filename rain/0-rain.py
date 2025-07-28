#!/usr/bin/python3
"""
0_main
"""


def rain(walls):
    """
    sadsadsadsa
    """
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)
    left = [0] * n
    right = [0] * n

    left[0] = walls[0]
    for i in range(1, n):
        left[i] = max(left[i - 1], walls[i])

    right[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right[i] = max(right[i + 1], walls[i])

    total = 0
    for i in range(1, n - 1):
        water = min(left[i], right[i]) - walls[i]
        if water > 0:
            total += water

    return total
