#-*- coding: utf-8 -*-

import sfml as sf
import time
import sys

class   windows:
    def __init__(self):
	self.window = sf.RenderWindow(sf.VideoMode(800, 600), "Client Zappy")

    def DisplayWindow(self, window):
	self.window.display()

    def CheckClose(self, window):
	while window.is_open:
	    for event in window.events:
		if type(events) is sf.CloseEvent:
		    self.window.close()
		if type(events) is sf.KeyEvent and event.code is sf.Keyboard.ESCAPE:
		    self.window.close()
	    self.window.clear()
