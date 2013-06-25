# -*- coding: utf-8 -*-

import sfml as sf
from perso import *

class           Evoli(Personnage):
    def __init__(self, name, level):
        Personnage.__init__(self, name, level)
        self.evoli = sf.Texture.from_file("ressources/pictures/evoli.png")

    def __str__(self):
        return "{0} {1}".format(self.name, self.level)

    def loadEvoli(self, window):
        try:
            tab = []
            # leve1
            aquali = sf.Texture.from_file("ressources/pictures/aquali.png")
            # level 2
            givrali = sf.Texture.from_file("ressources/pictures/givrali.png")
            # level 3
            mentali = sf.Texture.from_file("ressources/pictures/mentali.png")
            # level 4
            noctali = sf.Texture.from_file("ressources/pictures/noctali.png")
            # level 5
            phyllali = sf.Texture.from_file("ressources/pictures/phyllali.png")
            # level 6
            pyroli = sf.Texture.from_file("ressources/pictures/pyroli.png")
            # level 7
            voltali = sf.Texture.from_file("ressources/pictures/voltali.png")
 #           heart = sf.Texture.from_file("ressources/pictures/heart.png")
            evoli = sf.Sprite(self.evoli)
            aquali = sf.Sprite(aquali)
            givrali = sf.Sprite(givrali)
            mentali = sf.Sprite(mentali)
            noctali = sf.Sprite(noctali)
            phyllali = sf.Sprite(phyllali)
            pyroli = sf.Sprite(pyroli)
            voltali = sf.Sprite(voltali)
#            heart = sf.Sprite(heart)
            # evoli.move(sf.Vector2(0, 155))
            # aquali.move(sf.Vector2(155, 155))
            # givrali.move(sf.Vector2(300, 400))
            # mentali.move(sf.Vector2(155, 400))
            # noctali.move(sf.Vector2(300, 150))
            # phyllali.move(sf.Vector2(400, 155))
            # pyroli.move(sf.Vector2(50, 0))
            # voltali.move(sf.Vector2(300, 0))
            tab.append(evoli)
            tab.append(aquali)
            tab.append(givrali)
            tab.append(mentali)
            tab.append(phyllali)
            tab.append(pyroli)
            tab.append(voltali)
            #heart.move(sf.Vector2(155, 155))
            # image.position = -texture.size // 2
            # window.draw(evoli)
            # window.draw(aquali)
            # window.draw(givrali)
            # window.draw(mentali)
            # window.draw(noctali)
            # window.draw(phyllali)
            # window.draw(pyroli)
            # window.draw(voltali)
  #          window.draw(heart)
            return tab
        except IOError, e:
            print str(e)
