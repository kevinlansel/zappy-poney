# -*- coding: utf-8 -*-

import  sfml as sf
import  time
import  sys

class           Map:
    def __init__(self, MapX, MapY):
        self._x = 30
        self._y = 30
        self._MapX = int(MapX) - 1
        self._MapY = int(MapY) - 1
        self._pos = 0

    def __len__(self):
        return 0

    def drawMap(self):
        tab = []
        startX = 0
        startY = 0
        while (startY <= (self._y * self._MapY)):
               startX = 0
               while (startX <= (self._x * self._MapX)):
                   rectangle = sf.RectangleShape()
                   rectangle.size = sf.Vector2(self._x, self._y)
                   rectangle.outline_thickness = 1
                   rectangle.fill_color = sf.Color.GREEN
                   rectangle.outline_color = sf.Color.RED
                   pos = sf.Vector2(startX, startY)
                   rectangle.move(pos)
                   tab.append(rectangle)
                   startX += self._x
               startY += self._y
        return tab
