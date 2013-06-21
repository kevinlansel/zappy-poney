# -*- coding: utf-8 -*-

import sfml as sf
from perso import *

class           Phyllali(Personnage):
    def         __init__(self, name, level):
        Personnage.__init__("Phyllali", 5)
        self.phyllali = sf.Image("ressources/pictures/phyllali.png", width=20, height=20)
