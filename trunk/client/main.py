#!/usr/bin/python

import sys
from net import Net
import mouse
import map
import music
import window

#from mouse, map, music, window import *

def     welcome():
    toto = raw_input("c'est à vous : ")
    if (toto == "IA"):
        return 1
    if (toto == "DISPLAY"):
        return 2
    elif:
        print "nous ne comprenons pas votre demande"
        welcome()

def     keep_connect(net):
    while 1:
        toto = "toto"

def	check_args(net):
    if (len(sys.argv) == 5 or len(sys.argv) == 7):
	i = 1
        while i < len(sys.argv):
            if sys.argv[i] == "-n":
                net._team = int(sys.argv[i + 1])
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
        net = Net()
        check_args(net)
        print "Nom d'equipe : " + str(net.team)
        print "Hote : " + net._host
        print "Port : " + str(net._port)
        net.initConnexion
        print "\tBienvenue sur le Zappy ! \nPour démarrer une nouvelle partie entrer : IA \nPour voir la partie en cours entrer : DISPLAY \n"
        a = welcome()
        if (a == 1):
            print "IA"
        elif (a == 2):
            print "display"
        keep.connect(net)
        net._sock.close()
    except IOError: exit(1)

main()
