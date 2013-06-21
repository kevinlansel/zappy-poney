# -*- coding: utf-8 -*-
import sfml as sf
from perso import *

class           Aqualy(Personnage):
    def         __init__(self, name, level):
        Personnage.__init__("Aqualy", 8)
        self.aqualy = sf.Image("ressources/picture/aqualy.png", width=20, height=20)
