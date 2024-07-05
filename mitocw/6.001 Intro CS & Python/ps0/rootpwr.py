#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Jun 24 20:53:22 2024

Computes a root, power pair for the given integer

@author: totero
"""

integer = int(input("Enter an integer: "))
pwr = 2

while pwr < 6:
    
    root = 0
    
    while root**pwr < abs(integer):
        root += 1
    
    if root**pwr == abs(integer):
        if integer >= 0:
            print(str(root) + ", " + str(pwr))
        else:
            print(str(-1*root) + ", " + str(pwr))
        break
    
    pwr += 1
    
    if pwr == 6:    
        print("No power less than 6")