# -*- coding utf-8 -*-

import sfml as sf
import sys
from map import *

class           Mouse:
    def __init__(self):
        self._position = sf.Mouse.get_position()

    def drawText(self, msg, size, pos_x, pos_y):
        font = sf.Font.from_file("ressources/Sansation_Bold.ttf")
        instructions = sf.Text(msg, font, size)
        instructions.position = (pos_x, pos_y)
        instructions.color = sf.Color(80, 80, 80)
        return instructions

    def gereMouse(self, window):
        posi = sf.Mouse.get_position()
        return posi
