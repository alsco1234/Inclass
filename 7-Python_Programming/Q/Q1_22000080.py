"""
제출일 : 2023년 3월 24일
작성자 : 김민채
목적 : 파이썬 기초문법과 조건문 퀴즈
"""

# QUIZ 1. 입력 받은 정수의 특성에 따라서 다음과 같이 출력하라.
num = int(input("양의 정수 입력 : "))

if num <= 0:
    print("입력 오류: 양수가 아닙니다.")
elif num%2 == 0:
    print(num, "은 짝수입니다.")
else :
    print(num, "은 홀수입니다.")


# QUIZ 2. 년도를 입력받아 윤년을 계산하고 출력하라.
year = int(input("년도를 입력 : "))

leap = False

if year < 1 :
    print("입력 에러: 처리할 수 없는 년도입니다.")
else:
    if year%400 ==0 or (year%4 ==0 and year%100!=0) :
        leap = True

    if leap == True:
        print(year, "년은 윤년입니다.")
    else:
        print(year, "년은 평년입니다.")


# QUIZ 3. 거래금액을 입력받아 중개수수료를 계산하고 출력하라.
type = int(input("거래 유형 입력(전세 1, 매매 2) : "))
price = int(input("거래금액: "))

tax = 0

match type:
    case 1:
        if price >= 1000000000:
            tax = 0.2
        elif price >= 500000000:
            tax = 0.25
        elif price >= 100000000:
            tax = 0.3
        elif price >= 50000000:
            tax = 0.35
        else:
            tax = 0.4
    case 2:
        if price >= 1000000000:
            tax = 0.4
        elif price >= 500000000:
            tax = 0.5
        elif price >= 100000000:
            tax = 0.6
        elif price >= 50000000:
            tax = 0.7
        else :
            tax = 1
            
print("매매 ", price, "원의 중개수수료는 ", int(price * (tax/100)), "원 입니다.")
        
