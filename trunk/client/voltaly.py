# -*- coding: utf-8 -*-

import sfml as sf
from perso import *

class           Voltali(Personnage):
    def         __init__(self, name, level):
        self.voltali = sf.Texture.from_file("ressources/pictures/voltali.png")
        Personnage.__init__(self, name, level)

    def         __str__(self):
        return "{0} {1}" .format(self.name, self.level)

    def         loadVoltali(self, window):
        try:
            self.voltali = sf.Sprite(self.voltali)
            return self.voltali
        except IOError, e:
            print str(e)
