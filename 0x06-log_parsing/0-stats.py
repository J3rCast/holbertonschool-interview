#!/usr/bin/python3
"""This module contains some methods for computing metrics"""
import sys
from time import sleep


data = sys.stdin
correct_method = "\"GET /projects/260 HTTP/1.1\""
correct_status = [200, 301, 400, 401, 403, 404, 405, 500]
final_size = 0
status_dict = {}


def print_metrics():
    print("File size: {}".format(final_size))
    for i in correct_status:
        if (i in status_dict):
            print("{}: {}".format(i, status_dict[i]))


if __name__ == "__main__":
    try:
        for idx, i in enumerate(data):
            i = i.replace("-", " ", 1)
            i = i.replace("  ", "")
            splited = i.split(" ")

            try:
                ip = splited[0]
                date = splited[1]\
                    .replace("[", "") + " " + splited[2].replace("]", "")
                method = splited[3] + " " + splited[4] + " " + splited[5]
                status = int(splited[6])
                size = int(splited[7])
                if (method != correct_method or type(size) is not int):
                    continue
                if (status in correct_status):
                    if (status in status_dict):
                        status_dict[status] += 1
                    else:
                        status_dict[status] = 1

                final_size += size

                if ((idx + 1) % 10 == 0 and idx != 0):
                    print_metrics()
            except Exception as e:
                print(e)
                pass
        print_metrics()
    except KeyboardInterrupt as err:
        print_metrics()
        raise
