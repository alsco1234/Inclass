'''
작성일 : 23/6/4
작성자 : 김민채
목적 : tkinter를 이용하여 앞으로 읽어도 뒤에서부터 읽어도 같은 단어 또는 문장 확인하기
'''

from tkinter import *

def palin():
    str2 = ""
    for ch in entry.get():
        if ch.isalpha():
            str2 += ch.upper()

    rev_str = ""
    for i in range(len(str2)-1, -1, -1):
        rev_str += str2[i]

    if rev_str == str2:
        label2.configure(text = "True")
    else:
        label2.configure(text = "False")

    

root = Tk()
root.title("isPalindrom")

# 1. 설명 글자
label1 = Label(root, text = "Input a string to check palindrome or not")
label1.pack()

# 2. 문자열 입력받기
entry = Entry(root)
entry.pack()

# 4. 결과 출력 위한 레이블
label2 = Label(root)

# 3. 결과 버튼 누르면
button = Button(root, text = "Check", command = palin)
button.pack()

label2.pack()

root.mainloop()
