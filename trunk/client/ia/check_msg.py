# -*- coding: utf-8 -*-

import  sys

def     check_msg(msg):
    if (msg.find("message") == 0):
        msg = msg.strip('message ')
        tmp = msg.split(',');
        case = tmp[0]
        #check_broadcast(case, tmp[1], lvl)
    else:
        titi()

def     check_broadcast(case, msg, lvl):
    msg = msg.split(' ');
    if (msg[0] == 'RENFORT' && msg[1] == _lvl && _group == 'NO' && _slave == 0 && _chef == 0):
        send_broadcast(answer[msg[0]] + _lvl)
    elif (msg[0] == 'ACCEPT' && msg[1] == lvl && chef == 0 && slave == 0 && group == 'NO'):
        group = 'YES'
        slave = 1
        send_brodcast("bordcast THANKS")
    elif (msg[0] == "JOIN" && msg[1] == lvl && case != 0):
        move_to(case)
    elif (msg[0] == "THANKS" && msg[1] == lvl && group == 'YES' && chef == 1 && check_full() == 0):
        friend += 1
    elif (msg[0] == "NEED" && msg[1] == lvl && slave == 0 && ):
        make_boradcast()

def     make_broadcast():
    if (_group =='NO' && _slave == 0 && check_inv(_inv, _lvl) == 1):
        send_broadcast("broadcast RENFORT" + _lvl)
    elif (_chef == 1 && _slave == 0 && check_full() == 0):
        send_broadcast("broadcast ACCEPT" + _lvl)
    elif (_chef == 1 && check_full() == 1):
        send_broadcast("broadcast JOIN" + _lvl)

def     send_boradcast(s):
    send(s)

answer = dict([("RENFORT" : "NEED"), ("NEED", "ACCEPT"), ("ACCEPT" : "THANKS")])


if ((_slave == 0 && check_inv() == 1 && _group() == 0) ||
    (_chef == 1 && check_inv() == 1 && group_full == 0)):                               #chef ou futur chef
    _wait = 1
    send_broadcast("broadcast RENFORT" + _lvl)

if (msg[0] == 'RENFORT' && msg[1] == _lvl && _group == 0 && _wait == 0):                #futur slave
    send_broadcast("broadcast NEED" + _lvl)

if (msg[0] == 'NEED' && msg[1] == _lvl && _wait == 1 && group_full() == 0):             #start chef
    if (_chef == 0):
        _friend += 1
    _chef = 1
    _group = 1
    send_broadcast("broadcast ACCEPT" + _lvl)
else:
    send_broadcast("broadcast STOP" + _lvl)

if (msg[0] == 'ACCEPT' && msg[1] == _lvl):                                              #deviens slave
    _slave = 1
    _group = 1
    send_broadcast("broadcast THANKS" + _lvl)

if (msg[0] == 'THANKS' && msg[1] == _lvl && _group() == 1):                             #chef avec membre +1
    _friend += 1

if (_chef == 1 && group_full() == 1 && group_on() == 0):                                #appel pour incantation
    send_broadcast("broadcast JOIN" + _lvl)

if (_chef == 1 && group_full() == 1 && group_on() == 1):
    #incantation()
    titi()
