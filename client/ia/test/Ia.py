# -*- coding: utf-8 -*-

import  sys

KO = 0
OK = 1
RENFORT = 1
JOIN = 2
NEED = 3
ACCEPT = 4
THANKS = 5

class   Ia(object):
    def __init__(self):
        self._lvl = 1
        self._group = 'NO'
        self._slave = 0
        self._chef = 0
        self._friend = 0
        self._wait = 0
        self._renfort = 0
        self._msg = []
        self._inv = dict([('nourriture', 1260), ('linemate', 0), ('deraumere', 0), ('sibur', 0), ('mendiane', 0), ('phiras', 0), ('thystame', 0)])

    def	maj_inv(self, s):
        old = cut_string(s)
        i = 0
        while (i < len(old)):
            tmp = old[i].split(' ')
            if (tmp[0] in self._inv):
                self._inv[tmp[0]] = tmp[1]
            i += 1

def     faim(_inv):
    tmp = int(_inv['nourriture'])
    if (tmp < 252):
        return (OK)
    else:
        return (KO)

def     cut_string(s):
	s = s.strip('{')
	s = s.strip('}')
	inv = s.split(", ")
	return (inv)

obj = Ia()
obj.maj_inv("{nourriture 252, sibur 3, phiras 5, ..., deraumere 0}")

def     recup_feed():
    rcp = "ko"

    while (rcp == "ko"):
        see = send_msg("voir");
        tab = recup_voir(see);
        loc = locate_mat(tab, "nourriture")
        if (len(loc) != 0 && int(loc[0]) == 0):
            rcp = take_mat("nourriture")
        if (len(loc) != 0 && int(loc[0]) != 0 && rcp == "ko"):
            move_rd();

def     tak_mat(mat):
    return (send_msg("prendre " + mat))

def     recup_mat():
    i = 0
    tmp = "ko"

    if (_lvl == 1):
        what = check_lvl()
    elif (_lvl == 2):
        what = check_lvl()
    elif (_lvl == 3):
        what = check_lvl()
    elif (_lvl == 4):
        what = check_lvl()
    elif (_lvl == 5):
        what = check_lvl()
    elif (_lvl == 6):
        what = check_lvl()
    elif (_lvl == 7):
        what = check_lvl()
    see = send_msg("voir")
    voir = recup_voir(see)
    while (i < len(what)):
        tmp = locate_mat(voir, what[i])
        if (len(tmp) > 0 && (int)tmp[0] == 0):
            tmp = take_mat(what[i])
            i = len(what)
        else:
            i += 1
if (

def     recup_msg(msg):
    if (msg.find("message ") == 0):
        msg = msg.strip('message ')
        _msg.insert(0, msg)

def     check_msg():
    i = 0

    while (len(_msg) > 0):
        tmp = _msg[0].split(",")
        if (len(tmp) == 2):
            msg = tmp[1].split()
            if (len(msg) == 2):
                if (tmp[1].find("RENFORT")):
                    rcp_renfort(msg)
                elif (tmp[1].find("NEED")):
                    rcp_need(msg)
                elif (tmp[1].find("ACCEPT")):
                    rcp_accept(msg)
                elif (tmp[1].find("THANKS")):
                    rcp_thanks(msg)
                elif (tmp[1].find("JOIN")):
                    rcp_join(msg)
        tmp.pop(0)

while (1):
    if (faim(obj._inv)):
        recup_feed();
    else:
        if (len(_msg)):
            check_msg()
        else:
            rcp = send_msg("inventaire")
            maj_inv(rcp)
            if (check_inv() != _lvl):
                recup_mat()
            else:
                make_group()
            print "Check Messsage"
