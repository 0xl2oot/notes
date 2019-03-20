#!/usr/bin/python3

import pyperclip
import string

#message = 'this is a sentence.这是一句话。'
#message = '。话句一是这.ecnetnes a si siht'
#message = 'WKLV LV D VHQWHQFH.这是一句话。'
message = 'shesellsseashellsbytheseashore'
translated = ''
mode = 'encrypt'
#mode = 'decrypt'
LETTERS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

def convert(): # 反转密码
	# 一种实现办法
	# translated = ''
	# i = len(message) - 1
	# while i>=0:
	# 	translated += message[i]
	# 	i = i - 1
	# return translated

	# 另一种简单的实现办法
	return message[::-1]


def shift(key):
	# # 一种实现办法
	# translated = ''
	# M = message.upper()
	# i = 0
	# for symbol in M:
	# 	if symbol in LETTERS:
	# 		num = LETTERS.find(symbol)
	# 		if mode == 'encrypt':
	# 			num = num + key
	# 		elif mode == 'decrypt':
	# 			num = num - key
	# 		if num >= len(LETTERS):
	# 			num -= len(LETTERS)
	# 		elif num < 0:
	# 			num += len(LETTERS)
	# 		translated += LETTERS[num]
	# 	else:
	# 		translated += symbol			
	# return translated

	# 另一种简单的实现办法
	a = string.ascii_lowercase 
	b = string.ascii_uppercase
	key = key % 26      #key must be within 0 - 25  
	ta = a[key:] + a[:key]  
	tb = b[key:] + b[:key]  
	table = message.maketrans(a+b, ta+tb)  
	return message.translate(table)  




'''
translated = convert()
print('反转密码：\n'+translated+'\n')
'''



k = 3
translated = shift(k)
print('移位密码：\n'+translated+'\n')



pyperclip.copy(translated)
