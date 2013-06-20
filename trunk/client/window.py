#-*- coding: utf-8 -*-

import sfml as sf
import time
import sys
from map import *
from mouse import *

class   Windows:
    def __init__(self, tailleX, tailleY):
	self.window = sf.RenderWindow(sf.VideoMode(800, 600), "Client Zappy")
        self.tailleX = tailleX
        self.tailleY = tailleY
        self.themap = Map(self.tailleX, self.tailleY)

    def DisplayWindow(self):
	self.window.display()

    def OnlyDraw(self):
        # taille& de la map
        test = []
        test = self.themap.drawMap()
        i = 0
        while (i < len(test)):
            self.window.draw(test[i])
            i += 1

    def CheckMouse(self, window):
        mouse = Mouse()
        mouse.gereMouse(window)

    def CheckClose(self):
	while self.window.is_open:
	    for event in self.window.events:
		if type(event) is sf.CloseEvent:
		    self.window.close()
                    exit(1)
		if type(event) is sf.KeyEvent and event.code is sf.Keyboard.ESCAPE:
		    self.window.close()
                    exit(1)
            self.CheckMouse(self.window)
            self.OnlyDraw()
            self.DisplayWindow()
	    self.window.clear()
