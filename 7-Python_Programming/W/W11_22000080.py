'''
작성일 : 23/5/9
작성자 : 김민채
목적 : 11주차 수업내 코딩 연습
'''

# *** PRACTICE 1 : 전화번호 스페인어로 저장하고 출력하기 *** 
d = {0:'cero', 1:'uno', 2:'dos', 3:'tres', 4:'cuatro', 5:'cinco', 6:'seis', 7:'siete', 8:'ocho', 9:'nueve'}
sp = [] #스페인어
tel = [] #숫자

nums = input("전화번호 입력: ")

for i in range(len(nums)):
    sp.append(d[int(nums[i])])

print("스페인어로 바꾸면,", " ".join(sp))

for i in range(7):
    for key, value in d.items():
        if value == sp[i]:
            tel.append(key)

print("다시 숫자로 바꾸면,", " ".join(str(n) for n in tel))
