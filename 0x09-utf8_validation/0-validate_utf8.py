#!/usr/bin/python3
"""
Defines a method that determines if a given data set
represents valid UTF-8 encoding
"""


def validUTF8(data):
    for i in data:
        if len(chr(i).encode('utf-8')) != 1:
            return False
    return True
