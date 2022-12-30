<<<<<<< HEAD
#!/usr/bin/env python3

# SPDX-License-Identifier: BSD-3-Clause

"""
Demonstrate implicit memory allocation in Python.
"""


class AttackOnTitanCharacter:
    """Sample class to demonstrate memory allocation / free"""

    def __init__(self, idx, name):
        """Class constructor"""
        self.idx = idx
        self.name = name

    def __repr__(self):
        """toString equivalent"""
        return "[idx: " + str(self.idx) + ", name: " + self.name + "]"

    def __del__(self):
        """Class destructor"""
        print("destroying " + self.name)


characters = []
characters.append(AttackOnTitanCharacter(1, "Eren"))
characters.append(AttackOnTitanCharacter(2, "Zeke"))
characters.append(AttackOnTitanCharacter(3, "Kenny"))
characters.append(AttackOnTitanCharacter(4, "Reiner"))
characters.append(AttackOnTitanCharacter(5, "Armin"))
characters.append(AttackOnTitanCharacter(6, "Hange"))
characters.append(AttackOnTitanCharacter(7, "Levi"))
characters.append(AttackOnTitanCharacter(8, "Mikasa"))
characters.append(AttackOnTitanCharacter(9, "Sasha"))
characters.append(AttackOnTitanCharacter(10, "Erwin"))

print(characters)
=======
class AttackOnTitanCharacter:
    # constructor
    def __init__(self, id, name):
        self.id = id
        self.name = name

    # toString equivalent
    def __repr__(self):
        return "[id: " + str(self.id) + ", name: " + self.name + "]"

    # destructor
    def __del__(self):
        print("destroying " + self.name)

list = []
list.append(AttackOnTitanCharacter(1, "Eren"))
list.append(AttackOnTitanCharacter(2, "Zeke"))
list.append(AttackOnTitanCharacter(3, "Kenny"))
list.append(AttackOnTitanCharacter(4, "Reiner"))
list.append(AttackOnTitanCharacter(5, "Armin"))
list.append(AttackOnTitanCharacter(6, "Hange"))
list.append(AttackOnTitanCharacter(7, "Levi"))
list.append(AttackOnTitanCharacter(8, "Mikasa"))
list.append(AttackOnTitanCharacter(9, "Sasha"))
list.append(AttackOnTitanCharacter(10, "Erwin"))

print(list)
>>>>>>> noul3
