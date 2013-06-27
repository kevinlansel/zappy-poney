# -*- coding: utf-8 -*-

import  sys

lvl1 = dict([('linemate', 1), ('deraumere', 0), ('sibur', 0), ('mendiane', 0), ('phiras', 0), ('thystame', 0)])
lvl2 = dict([('linemate', 1), ('deraumere', 1), ('sibur', 1), ('mendiane', 0), ('phiras', 0), ('thystame', 0)])
lvl3 = dict([('linemate', 2), ('deraumere', 0), ('sibur', 1), ('mendiane', 0), ('phiras', 2), ('thystame', 0)])
lvl4 = dict([('linemate', 1), ('deraumere', 1), ('sibur', 2), ('mendiane', 0), ('phiras', 1), ('thystame', 0)])
lvl5 = dict([('linemate', 1), ('deraumere', 2), ('sibur', 1), ('mendiane', 3), ('phiras', 0), ('thystame', 0)])
lvl6 = dict([('linemate', 1), ('deraumere', 2), ('sibur', 3), ('mendiane', 0), ('phiras', 1), ('thystame', 0)])
lvl7 = dict([('linemate', 2), ('deraumere', 2), ('sibur', 2), ('mendiane', 2), ('phiras', 2), ('thystame', 1)])

def     check_lvl1(_inv):
    tab = []
    if (int(_inv["linemate"]) < int(lvl1["linemate"])):
        tab.append("linemate")
    return (tab)

def     check_lvl2(_inv):
    tab = []
    if (int(_inv["linemate"]) < int(lvl2["linemate"])):
        tab.append("linemate")
    if (int(_inv["deraumere"]) < int(lvl2["deraumere"])):
        tab.append('deraumere')
    if (int(_inv["sibur"]) < int(lvl2["sibur"])):
        tab.append("sibur")
    return (tab)

def     check_lvl3(_inv):
    tab = []
    if (int(_inv["linemate"]) < int(lvl3["linemate"])):
        tab.append("linemate")
    if (int(_inv["sibur"]) < int(lvl3["sibur"])):
        tab.append("sibur")
    if (int(_inv["phiras"]) < int(lvl3["phiras"])):
        tab.append("phiras")
    return (tab)


def     check_lvl4(_inv):
    tab = []
    if (int(_inv["linemate"]) < int(lvl4["linemate"])):
        tab.append("linemate")
    if (int(_inv["deraumere"]) < int(lvl4["deraumere"])):
        tab.append('deraumere')
    if (int(_inv["sibur"]) < int(lvl4["sibur"])):
        tab.append("sibur")
    if (int(_inv["phiras"]) < int(lvl4["phiras"])):
        tab.append("phiras")
    return (tab)


def     check_lvl5(_inv):
    tab = []
    if (int(_inv["linemate"]) < int(lvl5["linemate"])):
        tab.append("linemate")
    if (int(_inv["deraumere"]) < int(lvl5["deraumere"])):
        tab.append('deraumere')
    if (int(_inv["sibur"]) < int(lvl5["sibur"])):
        tab.append("sibur")
    if (int(_inv["mendiane"]) < int(lvl5["mendiane"])):
        tab.append("mendiane")
    return (tab)


def     check_lvl6(_inv):
    tab = []
    if (int(_inv["linemate"]) < int(lvl6["linemate"])):
        tab.append("linemate")
   if (int(_inv["deraumere"]) < int(lvl6["deraumere"])):
        tab.append('deraumere')
    if (int(_inv["sibur"]) < int(lvl6["sibur"])):
        tab.append("sibur")
    if (int(_inv["phiras"]) < int(lvl6["phiras"])):
        tab.append("phiras")
    return (tab)


def     check_lvl7(_inv):
    tab = []
    if (int(_inv["linemate"]) < int(lvl7["linemate"])):
        tab.append("linemate")
    if (int(_inv["deraumere"]) < int(lvl7["deraumere"])):
        tab.append('deraumere')
    if (int(_inv["sibur"]) < int(lvl7["sibur"])):
        tab.append("sibur")
    if (int(_inv["mendiane"]) < int(lvl7["mendiane"])):
        tab.append("mendiane")
    if (int(_inv["phiras"]) < int(lvl7["phiras"])):
        tab.append("phiras")
    if (int(_inv["thystame"]) < int(lvl7["thystame"])):
        tab.append("thystame")
    return (tab)

