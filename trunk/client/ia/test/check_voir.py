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

def     locate_mat(see, mat):
    i = 0
    tab = []
    while (i < len(see)):
        k = 0
        tmp = see[i].split()
        while (k < len(tmp)):
            if (mat == tmp[k]):
                tab.append(i)
                k = len(tmp)
            else:
                k += 1
        i += 1
    return (tab)

#def     dict_voir()

tmp = recup_voir("{nourriture joueur joueur joueur joueur,,, thystame,, nourriture,,,,, thystame,,,,,}")
#print joueur_on(tmp[0])
print locate_mat(tmp, "nourriture")
