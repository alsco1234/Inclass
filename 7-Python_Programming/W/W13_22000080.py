'''
작성일 : 23/5/23
작성자 : 김민채
목적 : 13주차 수업내 코딩 연습
'''

"""
from tkinter import *
import sys

def hello(event):
    print("Single CLick, Button-l")

def quit(event):
    print("Douvle Click, so lets stop")
    sys.exit()

widget = Button(None, text='Mouse CLicks')
widget.pack()

widget.bind('<Button-1>', hello)
widget.bind('<Double-1>', quit)

mainloop()
"""

from tkinter import *
from math import *

root = Tk()
root.geometry("300x200+100+100")

def press():
    label2.configure(text = "입력 값 = " + str(entry.get()))

label1 = Label(root, text = "이름이 무엇입니까?")
label1.pack()

entry = Entry(root)
entry.pack()

button = Button(root, text = "클릭", command = press)
button.pack()

label2 = Label(root)
label2.pack()

root.mainloop()