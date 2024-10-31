#!/usr/bin/python3
"""Minimum Operations"""


def minOperations(n):
    """If n is impossible to achieve, return 0"""
    if n <= 1:
        return 0

    operations = 0
    divisor = 2

    """Factorize n by dividing it by its smallest factors"""
    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

    return operations