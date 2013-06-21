# -*- coding: utf-8 -*-

import sfml as sf
from perso import *

class           Evoli(Personnage):
    def __init__(self, name, level):
        Personnage.__init__(self, name, level)

    def __str__(self):
        return "{0} {1}".format(self.name, self.level)

    def loadEvoli(self, window):
        try:
            texture = sf.Texture.from_file("ressources/pictures/heart.png")
            image = sf.Sprite(texture)
            window.draw(image)
        except IOError, e:
            print str(e)
