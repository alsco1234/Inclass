'''
작성일 : 23/3/21
작성자 : 김민채
목적 : 양의 정수를 입력받아 factorial 출력하기
'''

num = int(input("양의 정수를 입력하세요 : "))

if num < 1:
    print("계산할 수 없는 값입니다")
else:
    for i in range(num):
        fac = 1
        for j in range(1, i+2) :
            fac *= j
        
        # 형식 맞춰 출력하기
        if i != num-1:
            print(fac, end='')
        else:
            print(fac)
        if i != num-1 :
            print(", ", end='')
