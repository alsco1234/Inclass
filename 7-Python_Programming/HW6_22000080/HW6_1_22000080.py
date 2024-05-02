'''
작성일 : 23/5/23
작성자 : 김민채
목적 : 과일명과 색상 딕셔너리로 다루기
'''

# 1) 사전형 구성
d = {'apple':['red','pink','ivory','green'], 'strawberry':['red','black','green'], 'grape':['purple','green'], 'bluberry':["purple",'white'],'peach':['pink','ivory','white','yellow']}

# 2) 색상을 영문으로 입력받기
color = input("색상 입력: ")

res = []
for key, value in d.items():
    for i in range(len(value)):
        if value[i] == color:
            res.append(key)

print("해당 색상을 가지는 과일은", res)