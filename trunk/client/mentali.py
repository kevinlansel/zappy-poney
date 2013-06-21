# -*- coding: utf-8 -*-

import sfml as sf
from perso import *

class           Mentali(Personnage):
    def         __init__(self, name, level):
        Personnage.__init__("Mentali", 3)
        self.mentali = sf.Image("ressources/pictures/mentali.png", width=20, height=20)
