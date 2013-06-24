# -*- coding: utf-8 -*-

import  sys

def     recup_voir(s):
    s = s.strip('{')
    s = s.strip('}')
    tmp = s.split(',')
    return (tmp)

def     joueur_on(case):
    case = case.split()
    i = 0
    j = 0

    while (i < len(case)):
        if (case[i] == "joueur"):
            j += 1
        i += 1
    return (j)

#def     dict_voir()

tmp = recup_voir("{joueur joueur joueur joueur,,, thystame,, nourriture,,,,, thystame,,,,,}")
print joueur_on(tmp[0])
