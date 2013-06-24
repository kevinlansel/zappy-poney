#-*- coding: utf-8 -*-

import sfml as sf
import time
import sys
from map import *
from mouse import *
from evoly import *

class   Windows:
    def __init__(self, tailleX, tailleY):
	self.window = sf.RenderWindow(sf.VideoMode(1400, 920), "Client Zappy")
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

    def drawEvoli(self, window):
        evoli = Evoli("Evoli", 1)
        tab = evoli.loadEvoli(window)
        return tab

    def CheckMouse(self, window):
        mouse = Mouse()
        mouse.gereMouse(window)

    def CheckClose(self):
        tab = []
	while self.window.is_open:
	    for event in self.window.events:
		if type(event) is sf.CloseEvent:
		    self.window.close()
                    exit(1)
		if type(event) is sf.KeyEvent and event.code is sf.Keyboard.ESCAPE:
		    self.window.close()
                    exit(1)
            #self.CheckMouse(self.window)
            self.OnlyDraw()
            pos = sf.Vector2(100, 100)
            tab = self.drawEvoli(self.window)
            # print tab
            # i = 0
            tab[0].move(pos)
            s = sf.Vector2(0.3, 0.3)
            tab[0].scale(s)
            self.window.draw(tab[0])
        # while (i < len(tab)):
            #     self.window.draw(tab[i])
            #     i += 1
            self.DisplayWindow()
            self.window.clear()
