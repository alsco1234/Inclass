'''
작성일 : 23/3/21
작성자 : 김민채
목적 : 5주차 수업내 코딩 연습
'''
# *** Bubble sort : 내림차순 정렬 ***
numbers = [5, 4, 1, 3, 9, 2, 15]

for i in range( len(numbers) - 1):
    for j in range( len(numbers) -1 -i):
        if numbers[j] < numbers[j+1]:
            temp = numbers[j+1]
            numbers[j+1] = numbers[j]
            numbers[j] = temp

print(numbers)

# *** List에 item 추가하기 : append ***
t1 = ['x', 'y', 'z']
t1.append('a')
print(t1)
['x', 'y', 'z', 'a']

t1.append('e')
print(t1)
['x', 'y', 'z', 'a', 'e']

# *** EXERCISE 1 ***
for i in range(2, 20):
    print("\n ===", i, "단 ===")
    for j in range(1, 20):
        print(i, "*", j, "=", i*j)

# *** EXERCISE 2 ***
word=['Apple', 'box', 'buzz', 'CANTUS', 'dish', 'knife', 'lady', 'pitch', 'stimulus', 'wish', 'wolf']
gather=['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']

for i in range( len(word)):
    count = 0
    print(word[i] + "은", end='')
    for j in range( len(word[i])):
        if word[i][j] in gather:
            print(word[i][j], end='')
            if j != len(word[i]) -1:
                print(",", end='')
            count += 1
    print("로 모음", str(count)+"개")