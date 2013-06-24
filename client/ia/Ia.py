# -*- coding: utf-8 -*-

import  sys
from Inventaire import  Inventaire
from faim import faim

class   Ia(object):
    def __init__(self):
        self._lvl = 1
        self._group = 'NO'
        self._slave = 0
        self._chef = 0
        self._friend = 0
        self._wait = 0
        self._renfort = 0
        self._inv = Inventaire()

obj = Ia()
obj._inv.maj_inv("{nourriture 35, sibur 3, phiras 5, ..., deraumere 0}")
if (faim(obj._inv._inv)):
    
