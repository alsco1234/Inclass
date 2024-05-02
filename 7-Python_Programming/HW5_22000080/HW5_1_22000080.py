'''
작성일 : 23/5/9
작성자 : 김민채
목적 : 함수 3개 정의하고 실행하기
'''

# 1) 정 가운데 글자 리턴 ***
def middle(str):
    if len(str)%2 == 0:
        return str[int(len(str)/2)-1] + str[int(len(str)/2)]
    else:
        return str[int(len(str)/2)]
    
print(middle("abcde"))
print(middle("abcd"))
print(middle("123ab123"))

# 2) 모음 갯수 세어 리턴 ***
def countVowels(str):
    count = 0
    for i in range(len(str)):
        if str[i].upper() in ['A', 'E', 'I', 'O', 'U']:
            count = count + 1
    return count
    
print(countVowels("abcde"))
print(countVowels("AbCd"))
print(countVowels("123Ab123"))

# 3) index 홀수인 문자열 리턴 ***
def select(str):
    res = "("
    for i in range(len(str)):
        if i%2 != 0:
            res += str[i]
            res += ","
    return res[:-1] + ")"

print(select("reverse"))
print(select("abcde"))
print(select("AbCd"))