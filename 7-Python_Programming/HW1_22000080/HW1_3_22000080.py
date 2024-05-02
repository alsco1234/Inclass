'''
작성일 : 23/3/10
작성자 : 김민채
목적 : 입출력 연습
'''

name = input('>>> 이름 : ')

for i in range(3 + 1):
    print(name[0:i])

for j in range(1, 3):
    print(name[j:])