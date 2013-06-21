# -*- coding: utf-8 -*-

import sfml as sf
from perso import *

class           Noctali(Personnage):
    def         __init__(self, name, level):
        Personnage.__init__("Noctali", 4)
        self.noctali = sf.Image("ressources/pictures/noctali.png", width=20, height=20)
