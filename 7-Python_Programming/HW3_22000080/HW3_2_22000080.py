'''
작성일 : 23/4/10
작성자 : 김민채
목적 : 문자열에서 자음 찾아 대소문자 카운트하기
'''

str = ''
while(len(str) < 20):
    str = input("20글자이상이 문자열을 입력하시오: ")

# 1. 자음 찾아 출력
con = ''
gather = ['A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u']
for i in range(len(str)):
    if str[i] not in gather and str[i] != ' ':
        con += str[i]
print("자음만 찾으면, ", con)

# 2. 대소문자 갯수 출력
upper = ''
lower = ''
for i in range(len(con)):
    if 'A' < con[i] < 'Z':
        upper += con[i]
    elif 'a' < con[i] < 'z':
        lower += con[i]
print(upper + ", 대문자 ", len(upper), "개")
print(lower + ", 대문자 ", len(lower), "개")