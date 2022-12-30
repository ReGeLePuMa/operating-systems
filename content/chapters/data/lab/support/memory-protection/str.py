#!/usr/bin/env python3

<<<<<<< HEAD
# SPDX-License-Identifier: BSD-3-Clause

"""
Demonstrate string immutability in Python.
"""

s = "anaaremere"
print("{:s}, {:d}, {:c}".format(s[1], ord(s[1]), ord(s[1])))
s[1] = 'z'
=======
str = "anaaremere"
print("{:s}, {:d}, {:c}".format(str[1], ord(str[1]), ord(str[1])))
str[1] = 'z'
>>>>>>> noul3
