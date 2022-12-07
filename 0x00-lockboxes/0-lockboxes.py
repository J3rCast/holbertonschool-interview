#!/usr/bin/python3
"""This module contains a function that checks if lockboxes can
be opened by the keys inside them"""


def canUnlockAll(boxes):
    """Checks if all boxes can be unlocked"""
    keys = [0]

    for idx, box in enumerate(boxes):
        if not box:
            continue
        for key in box:
            if key not in keys and key != idx and key < len(boxes):
                keys.append(key)

    if len(keys) == len(boxes):
        return True

    return False
