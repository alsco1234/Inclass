'''
작성자 : 김민채
날짜 : 2023. 05. 19
목적 : 봄 파이썬프로그래밍 퀴즈2
'''

# **** 1 **** 
import random

def sel(num, listname):
    if num < 1:
        return None

    res = []
    
    for i in range(num):
        res.append(tuple( (listname[i], random.choice(['0원', '5천원', '7천원', '1만원', '2만원'])) ))

    return res
    
persons = []
num_persons = int(input("인원을 입력하세요"))

for i in range(num_persons):
    persons.append(input("사람의 이름을 입력하세요"))

res = sel(num_persons, persons)

for person in res:
    if person[1] == '2만원':
        print("2만원을 받은 사람은", person[0])


# **** 2 ****
def enc(ch):
    if not ch.isalpha():
        return ch
    elif ch.isupper():
        return code[ch].lower()
    else:
        return code[ch.upper()]
    

def dec(ch):
    if ch.isupper():
        for key, value in code.items():
            if value == ch:
                return key.lower()
    else:
        for key, value in code.items():
            if value == ch.upper():
                return key


code = {'A':'Z','B':'Y','C':'X','D':'W','E':'V','F':'U','G':'T','H':'S','I':'R','J':'Q','K':'P','L':'O','M':'N','N':'M','O':'L','P':'K','Q':'J','R':'I','S':'H','T':'G','U':'F','V':'E','W':'D','X':'C','Y':'B', 'Z':'A'}
input_str = ""

while len(input_str) < 10:
    input_str = input("문자열 입력:")

print("암호화 결과")
enc_res = ""
for i in range(len(input_str)):
    enc_res += enc(input_str[i])    
print(enc_res)

print("복호화 결과")
dec_res = ""
for i in range(len(enc_res)):
    dec_res += dec(enc_res[i])
print(dec_res)


# **** 3 ****
def fibo(n):
    if n == 1 or n == 2:
        return 1
    else:
        return fibo(n-1) + fibo(n-2)

num = int(input("양의 정수 입력 :"))

fibo_res = []
for i in range(1, num+1):
    fibo_res.append(fibo(i))

print(fibo_res)

        
