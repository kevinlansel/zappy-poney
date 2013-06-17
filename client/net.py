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
	query = "Connexion d'un nouveau client"
	sock.send(query)
