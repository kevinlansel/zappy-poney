#!/usr/bin/python
# -*- coding: utf-8 -*-

import sys
from net import *
from map import *

def     keep_connect(net):
    while 1:
        toto = "toto"

def	check_args(net):
    if (len(sys.argv) == 5 or len(sys.argv) == 7):
	i = 1
        while i < len(sys.argv):
            if sys.argv[i] == "-n":
                net._team = str(sys.argv[i + 1])
            elif sys.argv[i] == "-h":
                net._host = sys.argv[i + 1]
	    elif sys.argv[i] == "-p":
                net._port = int(sys.argv[i + 1])
            i = i + 2
    else:
	print "USAGE: ./Client [-h hote] [-n equipe] [-p port]"
	exit()

def     main():
    try:
        _mapX = 13
        _mapY = 8
        net = Net()
        map = Map(_mapX, _mapY)
        check_args(net)
        print "Nom d'equipe : " + str(net._team)
        print "Hote : " + str(net._host)
        print "Port : " + str(net._port)
        net.initConnexion
        #keep.connect(net)
        #net._sock.close()
    except IOError: exit(1)

main()
