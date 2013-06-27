#-*- coding: utf-8 -*-

import sfml as sf
import time
import sys
from map import *
from mouse import *
from evoly import *
from givrali import *
from mentali import *
from noctali import *
from phyllali import *
from pyroli import *
from voltaly import *
from aqualy import *
from oeuf import *

class   Windows:
    def         __init__(self, tailleX, tailleY):
	self.window = sf.RenderWindow(sf.VideoMode(800, 600), "Client Zappy")
        self.tailleX = tailleX
        self.tailleY = tailleY
        #self.themap = Map(self.tailleX, self.tailleY)
        self.bool_mouse = 0

    def         DisplayWindow(self):
	self.window.display()

    # def         OnlyDraw(self):
    #     # taille& de la map
    #     test = []
    #     test = self.themap.drawMap()
    #     i = 0
    #     while (i < len(test)):
    #         self.window.draw(test[i])
    #         i += 1

    def         drawPokemon(self, _lvl):
        tab = []
        if _lvl == 1:
            pokemon = Evoli("Evoli", 1)
            tab.append(pokemon.loadEvoli(self))
            return tab
        elif _lvl == 2:
            pokemon = Givrali("Givrali", 2)
            tab.append(pokemon.loadEvoli(self))
            return tab
        elif _lvl == 3:
            pokemon = Mentali("Mentali", 2)
            tab.append(pokemon.loadMentali(self))
            return tab
        elif _lvl == 4:
            pokemon = Noctali("Noctali", 2)
            tab.append(pokemon.loadNoctali(self))
            return tab
        elif _lvl == 5:
            pokemon = Phyllali("Phyllali", 2)
            tab.append(pokemon.loadPhyllali(self))
            return tab
        elif _lvl == 6:
            pokemon = Pyroli("Pyroli", 2)
            tab.append(pokemon.loadPyroli(self))
            return tab
        elif _lvl == 7:
            pokemon = Voltali("Voltali", 2)
            tab.append(pokemon.loadVoltali(self))
            return tab
        elif _lvl == 8:
            pokemon = Aquali("Aquali", 2)
            tab.append(pokemon.loadAquali(self))
            return tab
        elif _lvl == 9:
            pokemon = Oeuf("Oeuf", 2)
            tab.append(pokemon.loadOeuf(self))
            return tab
        else:
            print "Unknow level"

    def         drawEvoli(self, window):
        evoli = Evoli("Evoli", 1)
        tab = evoli.loadEvoli(window)
        return tab

    def         drawGivrali(self, window):
        print "Draw Givrali"
        givrali = Givrali("Givrali", 2)
        print "load Givrali"
        tab = givrali.loadGivrali(window)
        return tab

    def         CheckMouse(self, window):
        mouse = Mouse()
        position = mouse.gereMouse(window)
        return position

    def         drawText(self, msg, size, pos_x, pos_y):
        font = sf.Font.from_file("ressources/Sansation_Bold.ttf")
        instructions = sf.Text(msg, font, size)
        instructions.position = (pos_x, pos_y)
        instructions.color = sf.Color(80, 80, 80)
        return instructions

    def         displayRessource(self, tab):
        message = "Case position X : " +tab[0]+ "position Y :" +tab[1]+ "\n Linemate = " +tab[2]+ "\n Deraumere = " +tab[3]+ "\n Sibur = " +tab[4]+ "\n Mendiane" +tab[5]+ "\n Phiras = " +tab[6]+ "\n Thystame = " +tab[7]
        self.window.draw(drawText(message, 20, 480, 100))

    def         CheckClose(self, net):
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
                tab_ressource = recup_caseContent(net, mouse.x, mouse.y)
                displayRessource(tab_ressource)
                self.bool_mouse = 2
            if (sf.Mouse.is_button_pressed(sf.Mouse.LEFT) == False and self.bool_mouse == 2):
                self.bool_mouse = 0
            elif (sf.Mouse.is_button_pressed(sf.Mouse.LEFT) == True and self.bool_mouse == 0):
                self.bool_mouse = 1
            else:
                self.bool_mouse = 2
            # Draw Pokemon
            # self.OnlyDraw()
            # pos = sf.Vector2(100, 100)
            # #tab = self.drawEvoli(self.window)
            # tab = self.drawPokemon(6)
            # tab[0].move(pos)
            # s = sf.Vector2(0.3, 0.3)
            # tab[0].scale(s)
            self.window.draw(tab[0])
            self.DisplayWindow()
            self.window.clear()
