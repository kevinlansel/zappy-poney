# -*- coding: utf-8 -*-

import sfml as sf
from perso import *

class           Pyroli(Personnage):
    def         __init__(self, name, level):
        self.pyroli = sf.Texture.from_file("ressources/pictures/pyroli.png")
        Personnage.__init__(self, name, level)

    def         __str__(self):
        return "{0} {1}" .format(self.name, self.level)

    def         loadPyroli(self, window):
        try:
            self.pyroli = sf.Sprite(self.pyroli)
            return self.pyroli
        except IOError, e:
            print str(e)

