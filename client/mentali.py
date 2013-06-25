# -*- coding: utf-8 -*-

import sfml as sf
from perso import *

class           Mentali(Personnage):
    def         __init__(self, name, level):
        self.mentali = sf.Texture.from_file("ressources/pictures/mentali.png")
        Personnage.__init__(self, name, level)

    def         __str__(self):
        return "{0} {1}" .format(self.name, self.level)

    def         loadMentali(self, window):
        try:
            self.mentali = sf.Sprite(self.mentali)
            return self.mentali
        except IOError, e:
            print str(e)
