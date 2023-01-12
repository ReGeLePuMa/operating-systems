#!/usr/bin/env python3

<<<<<<< HEAD
# SPDX-License-Identifier: BSD-3-Clause

"""
Demonstrate impact of string (re)allocation at assignment.
"""
=======
import time
>>>>>>> noul3

s = "A" * 10000
input("Press to start: ")

for i in range(0, 10):
    s = s + s
    input("Press for next step: ")
