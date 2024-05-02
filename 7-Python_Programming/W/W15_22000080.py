'''
작성일 : 23/5/23
작성자 : 김민채
목적 : 13주차 수업내 코딩 연습
'''

from tkinter import *
from PIL import ImageTk, Image
root = Tk()
root.title('Show Image')

def showing1(event):
    label.configure(text='')
    img = Image.open('cat.gif')
    canvas.image = ImageTk.PhotoImage(img)
    canvas.create_image(0,0, image=canvas.image, anchot='nw')

def showing2(event):
    label.configure(text='')
    img = Image.open('dog.gif')
    canvas.image = ImageTk.PhotoImage(img)
    canvas.create_image(0,0, image=canvas.image, anchot='nw')

def resetCanvas(event):
    canvas.delete('all')
    label.configure(text='Disappear')
7
button1 = Button(root, text = 'Show cat')
button1.pack()

button2 = Button(root, text = 'Show dog')
button2.pack()

canvas = Canvas(root, width=500, height=400)
canvas.pack()

label = Label(root)
label.pack()

button1.bind('<Button-1>', showing1)
button1.bind('<Double-1>', resetCanvas)
button2.bind('<Button-1>', showing1)
button2.bind('<Double-1>', resetCanvas)

root.mainloop()