# -*- coding: utf-8 -*-
import sfml as sf
from perso import *

class           Aqualy(Personnage):
    def         __init__(self, name, level):
        self.aquali = sf.Texture.from_file("ressources/pictures/aquali.png")
        Personnage.__init__(self, name, level)

    def         __str__(self):
        return "{0} {1}".format(self.name, self.level)

    def         loadAquali(self):
        try:
            self.Aquali = sf.Sprite(self.aquali)
            return self.aquali
        except IOError, e:
            print str(e)

