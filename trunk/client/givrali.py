# -*- coding: utf-8 -*-

import sfml as sf
from perso import *

class           Givrali(Personnage):
    def         __init__(self, name, level):
        print "Construct"
        self.givrali = sf.Texture.from_file("ressources/pictures/givrali.png")
        Personnage.__init__(self, name, level)

    def         __str__(self):
        return "{0} {1}" .format(self.name, self.level)

    def         loadGivrali(self, window):
        try:
            print "Je load "
            self.givrali = sf.Sprite(self.givrali)
            print "Je Draw"
            return self.givrali
#            window.draw(self.givrali)
        except IOError, e:
            print str(e)
