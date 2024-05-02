'''
작성일 : 23/4/18
작성자 : 김민채
목적 : 8주차 수업내 코딩 연습
'''

def search(st, ch):
    for i in range(0, len(st)):
        if st[i] == ch:
            print(i)
            return
    print("-1")

search('apple', 'p') #1
search('apple', 'f') #-1
search('apple', 'a') #0
