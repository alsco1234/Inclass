'''
작성일 : 23/4/25
작성자 : 김민채
목적 : 9주차 수업내 코딩 연습
'''
def prime(num):
    # 소수이면 True, 소수가 아니면 False
    for i in range(2, num):
        if num%i == 0:
            return False
    return True

def N_prime(num):
    # 약수 찾아 저장후 리스트 리턴
    measures = []
    for i in range(1, num+1):
        if num%i == 0:
            measures.append(i)
    return measures

num = -1
while(num<0):
    num = int(input("엉의 정수를 입력하세요"))

if prime(num):
    print("소수입니다")
else:
    print("약수들은", N_prime(num), "입니다")