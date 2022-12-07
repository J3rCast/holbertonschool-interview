#!/usr/bin/python3
"""This module contains a function that checks if lockboxes can
be opened by the keys inside them"""


def set_false(li):
    """set all keys to false"""
    keys = {}
    for key in range(li):
        keys.update({key: False})

    keys[0] = True
    return keys


def check_open(keys):
    """check if all keys exists"""

    for key in keys:
        if keys[key] == False:
            return False
    return True


def canUnlockAll(boxes):
    """Checks if all boxes can be unlocked"""
    keys = set_false(len(boxes))

    for key in keys:
        for key in keys:
            if keys[key] == True:
                for k in boxes[key]:
                    if k < len(boxes):
                        keys[k] = True

    return check_open(keys)
