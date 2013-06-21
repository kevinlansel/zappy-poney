# -*- coding: utf-8 -*-

import sfml as sf
from perso import *
import Image

class           Evoli(Personnage):
    def __init__(self, name, level):
        Personnage.__init__(self, name, level)

    def __str__(self):
        return "{0} {1}".format(self.name, self.level)

    def loadEvoli(self, window):
        try:
            image = sf.Texture.create(10, 10)
            image = sf.Texture.from_file("ressources/pictures/heart.png")
            # texture = sf.Texture.from_file("ressources/pictures/heart.png")
            image = sf.Sprite(image)
            # image.position = -texture.size // 2
            window.draw(image)
        except IOError, e:
            print str(e)
