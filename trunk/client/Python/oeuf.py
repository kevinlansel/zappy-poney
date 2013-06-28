# -*- coding: utf-8 -*-

import sfml as sf
from perso import *

class           Oeuf(Personnage):
    def         __init__(self, name, level):
        self.oeuf = sf.Texture.from_file("ressources/pictures/oeuf.png")
        Personnage.__init__(self, name, level)

    def         __str__(self):
        return "{0} {1}" .format(self.name, self.level)

    def         loadOeuf(self, window):
        try:
            print "Je load "
            self.oeuf = sf.Sprite(self.oeuf)
            print "Je Draw"
            return self.oeuf
        except IOError, e:
            print str(e)
