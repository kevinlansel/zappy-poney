# -*- coding: utf-8 -*-

import sfml as sf

class           Personnage:
    def         __init__(self, name, level):
        self.name = name
        self.level = level

    def         __str__(self):
        return "{0} {1} ".format(self.name, self.level)
