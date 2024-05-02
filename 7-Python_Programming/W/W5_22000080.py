'''
작성일 : 23/3/31
작성자 : 김민채
목적 : 5주차 수업내 코딩 연습
'''

# *** EXERCISE 1 ***
word=['Apple', 'box', 'buzz', 'CANTUS', 'dish', 'knife', 'lady', 'pitch', 'stimulus', 'wish', 'wolf']
gather=['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']

for i in range( len(word)):
    result = []
    for j in range( len(word[i])):
        if word[i][j] in gather:
            result.append(word[i][j])
    print(word[i] + "은", result, "로 모음", len(result), "개")
