#!/usr/bin/python3
"""This module contains some methods for computing metrics"""
import sys
import ipaddress
from time import sleep
from dateutil.parser import parse


try:
    data = sys.stdin
    correct_method = "\"GET /projects/260 HTTP/1.1\""
    correct_status = [200, 301, 400, 401, 403, 404, 405, 500]
    final_size = 0
    status_dict = {}

    for idx, i in enumerate(data):
        splited = i.split(" ")

        ip = splited[0]
        date = splited[2].replace("[", "") + " " + splited[3].replace("]", "")
        method = splited[4] + " " + splited[5] + " " + splited[6]
        status = int(splited[7])
        size = int(splited[8])

        try:
            ipaddress.IPv4Address(ip)
            parse(date)
            if (method != correct_method or type(size) is not int):
                break
            if (status in correct_status):
                if (status in status_dict):
                    status_dict[status] += 1
                else:
                    status_dict[status] = 1
            else:
                break

            final_size += size

            if ((idx + 1) % 10 == 0 and idx != 0):
                print("File size: {}".format(final_size))
                for i in correct_status:
                    if (i in status_dict):
                        print("{}: {}".format(i, status_dict[i]))
        except Exception:
            break
except KeyboardInterrupt:
    print("File size: {}".format(final_size))
    for i in correct_status:
        if (i in status_dict):
            print("{}: {}".format(i, status_dict[i]))
