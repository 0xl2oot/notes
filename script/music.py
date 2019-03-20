# -*- coding: utf-8 -*-

from tkinter import *
#import tkMessageBox
import urllib
import json
import mp3play
import time
import thread

def music():
    word = entry.get().encode('utf-8')
    if not word:
        tkMessageBox.showinfo("提示：",'请先输入歌名再进行搜索')
        return 
    word = urllib.quote(word)
    html = urllib.urlopen('http://s.music.163.com/search/get/?type=1&s=%s&limit=9' %word).read()
    js = json.loads(html)
    listbox.delete(0,END)
    global data
    data = js['result']['songs']
    for i in data:
        listbox.insert(END,i['album']['name']+"("+i['artists'][0]['name']+")")


def play(event): 
    sy = listbox.curselection()[0]
    url = data[sy]['audio']
    urllib.urlretrieve(url,'music.mp3')
    mp3 = mp3play.load('music.mp3')
    mp3.play()
    mp3.seconds(time.sleep(mp3.seconds()))
    mp3.stop()

root = Tk()
# root.geometry('300x200+400+240')
root.geometry('+400+240')
root.iconbitmap('icon.ico')
root.title("音乐播放器")
entry = Entry(root)
entry.pack() #grid()布局
Button(root,text="搜 索",command = music).pack()
var = StringVar()
listbox = Listbox(root, width = 50, listvariable = var)
listbox.bind('<Double-Button-1>',play)
listbox.pack()
Label(root,text = "欢迎使用 ZD's Music ",fg = "blue").pack()
root.mainloop()



