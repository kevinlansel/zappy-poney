# -*- coding: utf-8 -*-

import sfml as sf
from perso import *

class           Pyroli(Personnage):
    def         __init__(self, name, level):
        Personnage.__init__("Pyroly", 6)
        self.pyroli = sf.Image("ressources/pictures/pyroli.png", width=20, heigt=20)
