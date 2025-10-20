#!/usr/bin/python3
"""
asdasdassd
asdasdsadsa
sa
"""

import sys

codes = ['200', '301', '400', '401', '403', '404', '405', '500']
stats = {code: 0 for code in codes}
totalsize = 0
lines = 0

def print_stats():
    """
    asdsadsasad
    das
    """
    print(f"File size: {totalsize}")
    for code in sorted(stats.keys()):
        if stats[code] > 0:
            print(f"{code}: {stats[code]}")

try:
    for line in sys.stdin:
        parts = line.split()

        if len(parts) < 9:
            continue

        statcode = parts[-2]
        filesize = parts[-1]

        try:
            totalsize += int(filesize)
        except ValueError:
            continue

        if statcode in statcode:
            statcode[statcode] += 1

        lines += 1
        if lines % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    print_stats()
    raise

print_stats()
