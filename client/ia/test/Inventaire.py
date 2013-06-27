# -*- coding: utf-8 -*-

import  sys

class	Inventaire(object):
	def	__init__(self):
		self._inv = dict([('nourriture', 1260), ('linemate', 0), ('deraumere', 0), ('sibur', 0), ('mendiane', 0), ('phiras', 0), ('thystame', 0)])

	def	maj_inv(self, s):
		old = cut_string(s)
		i = 0
		while (i < len(old)):
			tmp = old[i].split(' ')
			if (tmp[0] in self._inv):
				self._inv[tmp[0]] = tmp[1]
			i += 1

def     cut_string(s):
	s = s.strip('{')
	s = s.strip('}')
	inv = s.split(", ")
	return (inv)

