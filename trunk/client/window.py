#-*- coding: utf-8 -*-

import sfml as sf
import time
import sys
from map import *

class   Windows:
    def __init__(self):
	self.window = sf.RenderWindow(sf.VideoMode(800, 600), "Client Zappy")

    def DisplayWindow(self):
	self.window.display()

    def OnlyDraw(self):
        # taille& de la map
        _mapX = 1
        _mapY = 1
        themap = Map(_mapY, _mapX)
        test = []
        test = themap.drawMap()
        i = 0
        while (i < len(test)):
            self.window.draw(test[i])
            i += 1

    def CheckClose(self):
	while self.window.is_open:
	    for event in self.window.events:
		if type(event) is sf.CloseEvent:
		    self.window.close()
                    exit(1)
		if type(event) is sf.KeyEvent and event.code is sf.Keyboard.ESCAPE:
		    self.window.close()
                    exit(1)
            self.OnlyDraw()
            self.DisplayWindow()
	    self.window.clear()