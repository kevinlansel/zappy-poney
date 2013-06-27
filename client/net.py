#!/usr/bin/python
# -*- coding: utf-8 -*-

from socket import *
from window import *

class   Net:
    def __init__(self):
        self._port = 0
        self._team = 0
        self._kill = 0
        self._sock = 0
        self._host = "localhost"

tailleX = ""
tailleY = ""

def     recup_sizeMap(net):
    net._sock.send("msz\n")
    data = net._sock.recv(1024)
    i = 4
    coordX = ""
    coordY = ""
    while i < len(data):
        while data[i] != ' ':
            coordX += data[i]
            i += 1
        i += 1
        while i < len(data):
            coordY += data[i]
            i += 1
        w = Windows(coordX, coordY)
        global tailleX
        global tailleY
        tailleX = coordX
        tailleY = coordY
        # crée l'instance de windows avec la taille de la map et retourne window
    return w

def     recup_caseContent(net, x, y):
    chaine = "bct " + str(x) + " " + str(y) + "\n"
    net._sock.send(chaine)
    data = net._sock.recv(1024)
    i = 4
    ress = ""
    s2 = []
    while i < len(data):
        if data[i] == ' ' or i+1 == len(data):
            s2.append(ress)
            ress = ""
        else:
            ress += data[i]
            i += 1
    # retourne un tableau de chaine de caractere ayant toutes les ressources
    return s2


def     recup_mapContent(net):
    # faire un compteur avec le nombre de cases donc X * Y
    # et recv tant qu'on est inférieur à ce nombre
    net._sock.send("mct\n")
    nbCase = int(tailleX) * int(tailleY)
    j = 0
    s1 = []
    while j < nbCase:
        data = net._sock.recv(1024)
        i = 4
        ress = ""
        s2 = []
        while i < len(data):
            if data[i] == ' ' or i+1 == len(data):
                s2.append(ress)
                ress = ""
            else:
                ress += data[i]
                i += 1
        s1.append(s2)
        j += 1
    return s1

def     recup_teamName(net):
    # faire un compteur avec le nombre d'equipes
    # et recv tant qu'on est inférieur à ce nombre
    net._sock.send("tna\n")
    s1 = []
    j = 0
    nbligne = 0
    while j < nbligne:
        data = raw_input()
        i = 4
        s2 = ""
        while i < len(data):
            s2 += data[i]
            i += 1
        j += 1
        s1.append(s2)
    return s1 #renvoie un tableau de chaine de caracteres

def     recup_playerPosition(net, id_player):
    chaine = "ppo #" + str(id_player) + "\n"
    net._sock.send(chaine)
    data = net._sock.recv(1024)
    i = 7
    chaine = []
    while i <= len(data):
        chaine.append(data[i])
        i += 1
    return chaine

def     recup_playerLevel(net, id_player):
    chaine = "plv #" + str(id_player) + "\n"
    net._sock.send(chaine)
    data = net._sock.recv(1024)
    i = 7
    chaine = []
    while i <= len(data):
        chaine.append(data[i])
        i += 1
    return chaine

def     recup_playerInventaire(net, id_player):
    chaine = "pin #" + str(id_player) + "\n"
    net._sock.send(chaine)
    data = net._sock.recv(1024)
    i = 7
    chaine = []
    while i <= len(data):
        chaine.append(data[i])
        i += 1
    return chaine

def     askForTimeUnit(net):
    net._sock.send("sgt\n")
    data = net._sock.recv(1024)
    i = 4
    chaine = []
    while i < len(data):
        chaine.append(data[i])
        i += 1
    return chaine


def     modifyTimeUnit(net, timevalue):
    chaine = "sst " + str(timevalue) + "\n"
    net._sock.send(chaine)
