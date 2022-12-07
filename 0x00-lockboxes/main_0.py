#!/usr/bin/python3

canUnlockAll = __import__('0-lockboxes').canUnlockAll

boxes = [[1], [2], [3], [4], []]
print(canUnlockAll(boxes))

boxes = [[3, 4, 7], [5], [0, 4, 1], [1, 6, 2], [3], [4, 1], [6]]
print(canUnlockAll(boxes))

boxes = [[1, 4], [2], [0, 4, 1], [3], [], [4, 1], [5, 6]]
print(canUnlockAll(boxes))

boxes = [[7], [2], [3], [4], []]
print(canUnlockAll(boxes))

boxes = [[]]
print(canUnlockAll(boxes))

boxes = [[1], [0, 2], [3], [4], []]
print(canUnlockAll(boxes))

boxes = [[1], [1, 2], [3], [4], []]
print(canUnlockAll(boxes))

boxes = []
print(canUnlockAll(boxes))
