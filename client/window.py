#-*- coding: utf-8 -*-

import sfml as sf
import time
import sys
from map import *
from mouse import *
from evoly import *
from givrali import *

class   Windows:
    def __init__(self, tailleX, tailleY):
	self.window = sf.RenderWindow(sf.VideoMode(800, 600), "Client Zappy")
        self.tailleX = tailleX
        self.tailleY = tailleY
        self.themap = Map(self.tailleX, self.tailleY)
        self.bool_mouse = 0
        #self.str_serveur = ""

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

    def drawPokemon(self, _lvl):
        if _lvl == 1:
            self.window.clear()
            pokemon = Evoli("Evoli", 1)
            self.OnlyDraw()
            return pokemon.loadEvoli(self)
        elif _lvl == 2:
            self.window.clear()
            pokemon = Givrali("Givrali", 2)
            self.OnlyDraw()
            return pokemon.loadGivrali(self)
        elif _lvl == 3:
            pokemon = Mentali("Mentali", 3)
            return pokemon.loadMentali(self)
        elif _lvl == 4:
            pokemon = Noctali("Noctali", 4)
            return pokemon.loadNoctali(self)
        elif _lvl == 5:
            pokemon = Phyllali("Phyllali", 5)
            return pokemon.loadPhyllali(self)
        elif _lvl == 6:
            pokemon = Pyrolli("Pyrolli", 6)
            return pokemon.loadPyrolli(self)
        elif _lvl == 7:
            pokemon = Voltali("Voltali", 7)
            return pokemon.loadVoltali(self)
        elif _lvl == 8:
            pokemon = Aquali("Aquali", 8)
            return pokemon.loadAquali(self)
        else:
            print "Unknow level"

    def drawEvoli(self, window):
        evoli = Evoli("Evoli", 1)
        tab = evoli.loadEvoli(window)
        return tab

    def drawGivrali(self, window):
        print "Draw Givrali"
        givrali = Givrali("Givrali", 2)
        print "load Givrali"
        tab = givrali.loadGivrali(window)
        return tab

    def CheckMouse(self, window):
        mouse = Mouse()
        position = mouse.gereMouse(window)
        return position

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
            if (self.bool_mouse == 1):
                mouse = self.CheckMouse(self.window)
                #envoyer mouse a sauvage !
                #recup de la chaine de caractere a stocker dans self.str_ser
                print mouse
                self.bool_mouse = 2
            if (sf.Mouse.is_button_pressed(sf.Mouse.LEFT) == False and self.bool_mouse == 2):
                self.bool_mouse = 0
            elif (sf.Mouse.is_button_pressed(sf.Mouse.LEFT) == True and self.bool_mouse == 0):
                self.bool_mouse = 1
            else:
                self.bool_mouse = 2
# Draw Pokemon
            self.OnlyDraw()
            pos = sf.Vector2(100, 100)
            tab = self.drawEvoli(self.window)
            # print tab
            # i = 0
            tab[1].move(pos)
            s = sf.Vector2(0.3, 0.3)
            tab[1].scale(s)
            self.window.draw(tab[1])
        # while (i < len(tab)):
            #     self.window.draw(tab[i])
            #     i += 1
            self.DisplayWindow()
            self.window.clear()
