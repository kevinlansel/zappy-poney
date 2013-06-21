# -*- coding: utf-8 -*-

import sfml as sf
from perso import *

class           Voltaly(Personnage):
    def         __init__(self, name, level):
        Personnage.__init__("Voltaly", 7)
        self.pyroli = sf.Image("ressources/pictures/voltaly.png", width=20, height=20)
