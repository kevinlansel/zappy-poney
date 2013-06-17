# -*- coding utf-8 -*-

import sfml as sf
import sys

class           Mouse:
    def __init__(self):
        self._position = sf.Mouse.get_position()

    def gereMouse(self):
        if sf.Mouse.is_button_pressed(sf.Mouse.LEFT):
            print self._position
