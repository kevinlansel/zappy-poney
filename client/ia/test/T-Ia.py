# -*- coding: utf-8 -*-

import  sys

class   Ia(object):
    def         __init__(self):
        self._lvl = 1
        self._group = 'NO'
        self._slave = 0
        self._chef = 0
        self._friend = 0
        self._wait = 0
        self._renfort = 0
        self._msg = []
        self._inv = dict([('nourriture', 10), ('linemate', 0), ('deraumere', 0), ('sibur', 0), ('mendiane', 0), ('phiras', 0), ('thystame', 0)])

    def         maj_inv(self, s):
        old = cut_string(s)
        i = 0
        while (i < len(old)):
            tmp = old[i].split(' ')
            if (tmp[0] in self._inv):
                self._inv[tmp[0]] = tmp[1]
            i += 1

    def     send_msg(s):
#        send(s)
#        tmp = read()
        tmp = "ok"
        return (tmp)

    def     check_message(s):
        if (s.find("message") == 0):
            self._msg.insert(0, s)

    def     mouv_rand_bouffe(self):
        rd = random.randint(1, 3)
        if (rd == 1):
            mv = "avance"
        elif (rd == 2):
            mv = "droite"
        elif (rd == 3):
            mv = "gauche"
        send_msg(mv)
        ramasser_nourriture(self)

    def     ramasser_nourriture(self):
        if (send_msg("prend nourriture") == "ok"):
            check_faim(self)
        else:
            mouv_rand_bouffe(self)

    def     check_faim(self):
        if (int(self._inv["nourriture"] < 2)):
            ramasser_nourriture(self)
        else:
            check_message(self)

obj = Ia()
obj.check_faim()
