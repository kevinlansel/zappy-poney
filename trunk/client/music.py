# -*- coding: utf-8 -*-

import sfml as sf

class Music:
    def __init__(self):
	self.music = sf.Music.from_file("ressources/audio/contact.wav")
	self.music.play()