# *** EXERCISE 1 : 회문 확인 1 ***
def palin(str):
    answer = ""
    for i in range(len(str)-1, -1, -1):
        answer += str[i]
    if str == answer:
        return True
    else:
        return False

s = input("회문 확인 할 문장 입력 : ")

# 알파벳 모으기
s2 = ""
for ch in s:
    if ch.isalpha():
        s2 += ch
# 대문자 바꾸기
s2.upper()

if palin(s2):
    print(s, '회문')
else:
    print(s, '회문 아님')


# *** EXERCISE 2 : 회문 확인 2 ***

def palin(str):
    str2 = ""
    for ch in str:
        if ch.isalpha():
            str2 += ch.upper()

    rev_str = ""
    for i in range(len(str2)-1, -1, -1):
        rev_str += str2[i]

    if rev_str == str2:
        print("palindrome")

palin("Step on no Pets!!!")


# *** EXERCISE 3 : 숫자로 문자 출력, chr() ***
import random

def gen_random(a, b):
    r = random.randrange(a, b)
    c = chr(65+r)
    print(r, c)

for i in range(10):
    gen_random(i+1, i+10)


# *** EXERCISE 4 : 삼각형의 밑변과 높이 받기 ***
def tri(height, width):
    print("삼각형의 넓이는 ", width * height * 1/2)

width = 0
height = 0

while(width <=0 and height<=0):
    width = int(input("삼각형의 밑변을 입력하시오"))
    height = int(input("삼각형의 높이을 입력하시오"))

tri(height, width)