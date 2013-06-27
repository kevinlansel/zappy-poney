# -*- coding: utf-8 -*-

import  sfml as sf
import  time
import  sys

class           Map:
    def __init__(self, MapX, MapY):
        self._x = 50
        self._y = 50
        self._MapX = int(MapX) - 1
        self._MapY = int(MapY) - 1
        self._pos = 0
        self.save_map2 = []

    def __len__(self):
        return 0

    def getsavemap(self):
        return self.save_map2

    def drawMap(self):
        tab = []
        startX = 0
        startY = 0
        i = 0
        while (startY <= (self._y * self._MapY)):
            save_map1 = []
            startX = 0
            while (startX <= (self._x * self._MapX)):
                rectangle = sf.RectangleShape()
                rectangle.size = sf.Vector2(self._x, self._y)
                rectangle.outline_thickness = 1
                rectangle.fill_color = sf.Color.GREEN
                rectangle.outline_color = sf.Color.RED
                pos = sf.Vector2(startX, startY)
                rectangle.move(pos)
                save_map1.append(pos)
                save_map1.append(rectangle)
                tab.append(rectangle)
                startX += self._x
                i += 1
            startY += self._y
            self.save_map2.append(save_map1)
        return tab
