#-*- coding: utf-8 -*-

from map import *
import sfml as sf
from window import *

class           Case:
    def         ___init___(self, tab):
        self.tab_ressource = tab[2:-1]
        self.rectangle = sf.RectangleShape()
        self.rectangle.size = sf.Vector2(50, 50)
        self.rectangle.outline_tickness = 1
        self.rectangle.fill_color = sf.Color.GREEN
        self.rectangle.outline = sf.color.RED
        pos = sf.Vector2((tab[0] * 50), (tab[1] * 50))
        self.rectangle.move(pos)

    def         draw(self, window):
        i = 0
        while (i < len(self.tab_ressource)):
            if self.tab_ressource[i] != 0:
                self.rectangle.fill_color = sf.Color.BLUE
            i += 1
        window.draw(self.rectangle)
