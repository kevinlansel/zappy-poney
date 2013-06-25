# -*- coding: utf-8 -*-

import sfml as sf
from perso import *

class           Noctali(Personnage):
    def         __init__(self, name, level):
        self.noctali = sf.Texture.from_file("ressources/pictures/noctali.png")
        Personnage.__init__(self, name, level)

    def         __str__(self):
        return "{0} {1}" .format(self.name, self.level)

    def         loadNoctali(self, window):
        try:
            self.noctali = sf.Sprite(self.noctali)
            return self.noctali
        except IOError, e:
            print str(e)
