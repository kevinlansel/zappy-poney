# -*- coding: utf-8 -*-

import sfml as sf
from perso import *

class           Givraly(Personnage):
    def         __init__(self, name, level):
        Personnage.__init__("Givraly", 2)
        self.givraly = sf.Image("ressources/picture/givraly.png", width=20; height=20)
