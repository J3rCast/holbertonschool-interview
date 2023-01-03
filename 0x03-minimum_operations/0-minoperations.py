#!/usr/bin/python3
"""This module contains methods"""
import math


def is_prime(num):
    """Check if number is prime."""
    for n in range(2, num):
        if num % n == 0:
            return n
    return 0


def minOperations(n):
    """Find the minimum operations."""
    if math.isinf(n):
        return 0

    my_num = 1
    adition = 1

    if is_prime(n) == 0:
        return n

    num_operations = 1
    for index in range(n):
        if (my_num == n):
            return num_operations
        if (my_num != 1 and n % my_num == 0):
            num_operations += 1
            adition = my_num
        num_operations += 1
        my_num += adition
    return num_operations
