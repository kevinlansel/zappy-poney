# -*- coding: utf-8 -*-

import  sys

def     check_msg(msg):
    if (msg.find("message") == 0):
        msg = msg.strip('message ')
        tmp = msg.split(',');
        case = tmp[0]
        print case
        print tmp[1]
        #check_broadcast(case, tmp[1], lvl)
    else:
        print "Hey"

check_msg("message 8, titi 1")

def     check_broadcast(case, msg, lvl):
    msg = msg.split(' ');
    if (msg[0] == 'RENFORT' and msg[1] == _lvl and _group == 'NO' and _slave == 0 and _chef == 0):
        send_broadcast(answer[msg[0]] + _lvl)
    elif (msg[0] == 'ACCEPT' and msg[1] == lvl and chef == 0 and slave == 0 and group == 'NO'):
        group = 'YES'
        slave = 1
        send_brodcast("bordcast THANKS")
    elif (msg[0] == "JOIN" and msg[1] == lvl and case != 0):
        move_to(case)
    elif (msg[0] == "THANKS" and msg[1] == lvl and group == 'YES' and chef == 1 and check_full() == 0):
        friend += 1
    elif (msg[0] == "NEED" and msg[1] == lvl and slave == 0):
        make_boradcast()

def     make_broadcast():
    if (_group =='NO' and _slave == 0 and check_inv(_inv, _lvl) == _lvl):
        send_broadcast("broadcast RENFORT" + _lvl)
    elif (_chef == 1 and _slave == 0 and check_full() == 0):
        send_broadcast("broadcast ACCEPT" + _lvl)
    elif (_chef == 1 and check_full() == 1):
        send_broadcast("broadcast JOIN" + _lvl)

def     send_boradcast(s):
    send(s)

answer = dict([("RENFORT" , "NEED"), ("NEED", "ACCEPT"), ("ACCEPT" , "THANKS")])

def     make_group():
    if ((_slave == 0 and check_inv() == 1 and _group() == 0) or
        (_chef == 1 and check_inv() == 1 and group_full == 0)):                               #chef ou futur chef
        _wait = 1
        send_broadcast("broadcast RENFORT" + _lvl)

def     rcp_renfort():
    if (msg[0] == 'RENFORT' and msg[1] == _lvl and _group == 0 and _wait == 0):                #futur slave
        send_broadcast("broadcast NEED" + _lvl)

def     rcp_need():
    if (msg[0] == 'NEED' and msg[1] == _lvl and _wait == 1 and group_full() == 0):             #start chef
        if (_chef == 0):
            _friend += 1
            _chef = 1
            _group = 1
            send_broadcast("broadcast ACCEPT" + _lvl)
    elif (msg[0] == 'NEED' and msg[1] == _lvl and _wait == 1 and group_full() == 1):
        send_broadcast("broadcast STOP" + _lvl)

def     rcp_accept():
    if (msg[0] == 'ACCEPT' and msg[1] == _lvl):                                              #deviens slave
        _slave = 1
        _group = 1
        send_broadcast("broadcast THANKS" + _lvl)

def     rcp_thanks():
    if (msg[0] == 'THANKS' and msg[1] == _lvl and _group() == 1):                             #chef avec membre +1
        _friend += 1

def     snd_join():
    if (_chef == 1 and group_full() == 1 and group_on() == 0):                                #appel pour incantation
        send_broadcast("broadcast JOIN" + _lvl)

def     rcp_join(msg, case):
    if (msg[0] == "JOIN" and msg[1] == _lvl and _slave == 1):
        move_to(case)

def     inc():
    if (_chef == 1 and group_full() == 1 and group_on() == 1):
    #incantation()
        titi()
