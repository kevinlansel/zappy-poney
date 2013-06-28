# -*- coding: utf-8 -*-

import sfml as sf
from perso import *

class           Phyllali(Personnage):
    def         __init__(self, name, level):
        self.phyllali = sf.Texture.from_file("ressources/pictures/phyllali.png")
        Personnage.__init__(self, name, level)

    def         __str__(self):
        return "{0} {1}" .format(self.name, self.level)

    def         loadPhyllali(self, window):
        try:
            self.phyllali = sf.Sprite(self.phyllali)
            return self.phyllali
        except IOError, e:
            print str(e)
