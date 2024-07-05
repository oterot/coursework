#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jun 23 21:46:39 2024

@author: totero
"""

integers = 10
biggest = 0

while integers > 0:
    i = int(input("Enter an integer: "))
    if i % 2 != 0:
       biggest = max(biggest, i) 
    integers = integers - 1

if biggest == 0:
    print("There were no odd numbers")
else:
    print(biggest)

