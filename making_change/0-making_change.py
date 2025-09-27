#!/usr/bin/python3
"""
adaaddsds
"""

def makeChange(coins, total):
    """
    sadasds
    """
    if total <= 0:
        return 0

    lista = [total + 1] * (total + 1)
    lista[0] = 0

    for cant in range(1, total + 1):
        for coin in coins:
            if coin <= cant:
                lista[cant] = min(lista[cant], lista[cant - coin] + 1)

    return lista[total] if lista[total] <= total else -1
