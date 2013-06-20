#!/usr/bin/python
# -*- coding: utf-8 -*-

from socket import *

class   Net:
    def __init__(self):
        self._port = 0
        self._team = 0
        self._kill = 0
        self._sock = 0
        self._host = "localhost"

def     send_sizeMap(net):
    net._sock.send("msz\n")

def     send_caseContent(net, x, y):
    chaine = "bct " + str(x) + " " + str(y) + "\n"
    net._sock.send(chaine)

def     send_mapContent(net):
    net._sock.send("mct\n")

def     send_teamName(net):
    net._sock.send("tna\n")

def     send_playerPosition(net, id_player):
    chaine = "ppo #" + str(id_player) + "\n"
    net._sock.send(chaine)

def     send_playerLevel(net, id_player):
    chaine = "plv #" + str(id_player) + "\n"
    net._sock.send(chaine)

def     send_playerInventaire(net, id_player):
    chaine = "pin #" + str(id_player) + "\n"
    net._sock.send(chaine)

def     askForTimeUnit(net):
    net._sock.send("sgt\n")

def     modifyTimeUnit(net, timevalue):
    chaine = "sst " + str(timevalue) + "\n"
    net._sock.send(chaine)
