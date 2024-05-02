'''
작성일 : 23/5/2
작성자 : 김민채
목적 : 10주차 수업내 코딩 연습
'''

# *** EXERCISE 1 : 암호화 (tuple을 다른 쌍응로 바꾸는 것)***
import random 

s = 'abcdefghijklmnopqrstuvwxyz'
# random.sample(s, 26) 사용하여 순서를 바꾸어 알파벳 26개를 base_s 에 저장한다
base_s = random.sample(s, 26) 
password = [ ] 
#zip() 함수를 사용하여, s와 base_s로  튜플로 이루어진 리스트를 생성한다
password_hint = list(zip(s, base_s))
print(password_hint) 

input_str = input("문자열 입력: ") 
for letter in input_str: 
    for i in range(26): 
        if letter == password_hint[i][0]: 
            password.append(password_hint[i][1]) 

print(password)

# *** EXERCISE 2 : 암호화 (tuple을 다른 쌍응로 바꾸는 것)***
s= input("문자열을 입력해 주세요: ")

dic = {'A':'o', 'B':'p', 'C':'q', 'D':'r', 'E':'s', 'F':'t', 'G':'u' }
enc = ''

for c in s:
    for k in dic.keys():
        if c == k:
            enc = enc + dic[k]
            # break
print(enc)


# *** PRACTICE ***
def fibonacci(n):
    if n ==1 or n==2 :
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)

n = int(input("출력할 피보나치 수열을 입력하세요 : "))
print(fibonacci(n))
    