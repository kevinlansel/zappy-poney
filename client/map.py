# -*- coding: utf-8 -*-

import  sfml as sf
import  time
import  sys

class           Map:
    def __init__(self, MapX, MapY):
        self._x = 30
        self._y = 30
        self._MapX = MapX
        self._MapY = MapY

    def drawMap(self):
        tab = []
        startX = 0
        startY = 0
        while (startY <= (self._y * self._MapY)):
               startX = 0
               while (startX <= (self._x * self._MapX)):
                      tab.append(drawRectangle(sf.Vector2(startX, startY), self))
                      startX += self._x
               startY += self._y
        return tab

    def drawRectangle(liste, self):
        i = 0
        paddle_size = sf.Vector2(self.x, self.y)
        rectangle = sf.RectangleShape()
        rectangle.size = paddle_size
        rectangle.outline_thickness = 1
        while (i < len(liste)):
            if (liste[i][0].getbool() == True):
                rectangle.fill.color = sf.Color.BLUE
            else:
                rectangle.fill.color = sf.Color.GREEN
        rectangle.outline_color = sf.Color.RED
        rectangle.move(pos)
        return rectangle