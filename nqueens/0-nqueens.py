#!/usr/bin/python3
"""
asdasdsadsa
"""

import sys


def is_safe(board, row, col):
    """adsdasdasdas"""
    for r, c in board:
        if c == col or abs(c - col) == abs(r - row):
            return False
    return True


def solve_nqueens(N, row=0, board=[]):
    """asdsadas"""
    if row == N:
        print(board)
        return

    for col in range(N):
        if is_safe(board, row, col):
            solve_nqueens(N, row + 1, board + [[row, col]])


def main():
    """asdasdas"""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    solve_nqueens(N)


if __name__ == "__main__":
    main()
