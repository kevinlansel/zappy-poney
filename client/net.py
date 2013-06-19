#!/usr/bin/python
# -*- coding: utf-8 -*-

import socket

class   Net:
    def __init__(self):
        self._port = 0
        self._team = 0
        self._kill = 0
        self._sock = 0
        self._host = "localhost"

    def initConnexion():
        self._sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	try:
	    self._sock.connect((self._host, self._port))
	except socket.error:
	    exit()
	print "Connexion etablie avec le serveur"
	query = "BIENVENUE"
	self._sock.send(query)

    def     send_sizeMap():
        self._sock.send("msz")

    def     send_caseContent(x, y):
        chaine = "bct " + str(x) + " " + str(y)
        self._sock.send(chaine)

    def     send_mapContent():
        self._sock.send("mct")

    def     send_teamName():
        self._sock.send("tna")

    def     send_playerPosition(id_player):
        chaine = "ppo # " + str(id_player)
        self._sock.send(chaine)

    def     send_playerLevel(id_player):
        chaine = "plv # " + str(id_player)
        self._sock.send(chaine)

    def     send_playerInventaire(id_player):
        chaine = "pin # " + str(id_player)
        self._sock.send(chaine)

    def     askForTimeUnit():
        self._sock.send("sgt")

    def     modifyTimeUnit(timevalue):
        chaine = "sst " + str(timevalue)
        self._sock.send(chaine)
