# -*- coding: utf-8 -*-

import  sys


def     check_group(_lvl, _friend):
    if (_lvl == 1 && _friend == 0):
        return (0)
    elif (_lvl == 2 && _friend == 2):
        return (2)
    elif (_lvl == 3 && _friend == 2):
        return (2)
    elif (_lvl == 4 && _friend == 4):
        return (4)
    elif (_lvl == 5 && _friend == 4):
        return (4)
    elif (_lvl == 6 && _friend == 6):
        return (6)
    elif (_lvl == 7 && _friend == 6):
        return (6)
    else:
        return (-1)

def     check_inv(_inv):
    if (_lvl == 1 && _inv["linemate"] >= 1):
        return (1)
    elif (_lvl == 2 && _inv["linemate"] >= 1 && _inv["deraumere"] >= 1 &&
          _inv["sibur"] >= 1):
        return (2)
    elif (_lvl == 3 && _inv["linemate"] >= 2 && _inv["sibur"] >= 1 &&
          _inv["phiras"] >= 2):
        return (3)
    elif (_lvl == 4 && _inv["linemate"] >= 1 && _inv["deraumere"] >= 1 &&
          _inv["sibur"] >= 2 && _inv["phiras"] >= 1):
        return (4)
    elif (_lvl == 5 && _inv["linemate"] >= 1 && _inv["deraumere"] >= 2 &&
          _inv["sibur"] >= 1 && _inv["mendiane"] >= 3):
        return (5)
    elif (_lvl == 6 && _inv["linemate"] >= 1 && _inv["deraumere"] >= 2 &&
          _inv["sibur"] >= 3 && _inv["phiras"] >= 1):
        return (6)
    elif (_lvl == 7 && _inv["linemate"] >= 2 && _inv["deraumere"] >= 2 &&
          _inv["sibur"] >= 2 && _inv["mendiane"] >= 2 &&
          _inv["phiras"] >= 2 && _inv["thystame"] >= 1):
        return (7)



def     group_on(_lvl, _friend, msg):
    j = joueur_on(recup_voir(msg)[0])
    c = check_group(_lvl, _friend)

    if (j == c):
        return (1)
    else:
        return (0)
