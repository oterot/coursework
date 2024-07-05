#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jun 23 22:28:44 2024

@author: totero
"""

s = input("Enter a few decimal numbers: ")
n = ''
sum = 0

for c in s:
    if c == ',':
        sum += float(n)
        n = ''
    else:
        n += c

sum += float(n)
    
print(sum)