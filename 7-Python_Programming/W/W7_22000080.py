'''
작성일 : 23/4/11
작성자 : 김민채
목적 : 7주차 수업내 코딩 연습
'''

# 문자열 입력받기
s = ''
while(len(s)<10):
    s = input("10글자 이상의 문자열을 입력하세요 : ")

# 바꾸어 출력하기
s = s.swapcase()
s = s.replace(' ', '*')
print(s)

# 단어로 나누어 출력하기
s2 = ''
for i in range(0, len(s)):
    if s[i].islower():
        s2 += ' '
    s2  += s[i]
result = s2.split()
print(result)





