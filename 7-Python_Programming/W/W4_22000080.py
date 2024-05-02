'''
작성일 : 23/3/21
작성자 : 김민채
목적 : 4주차 수업내 코딩 연습
'''
# *** EXERCISE ***
num = int(input("input a positive integer : "))

prime_yes = True

for i in range(2, num):
    if num % i ==0:
        prime_yes = False
        break

if prime_yes == True:
    print(num, "is a prime number")
else:
    print(num, "is not a prime number")


# *** EXERCISE 1 ***

str1 = input("첫 번째 문자열을 입력하세요 : ")
str2 = input("두 번째 문자열을 입력하세요 : ")

if str1 < str2:
    print(str1, "은 ", str2, "보다 작다")
elif str1 > str2:
    print(str1, "은 ", str2, "보다 크다")
else:
    print(str1, "은 ", str2, "와 같다")


# *** EXERCISE 2 ***

num = int(input("양의 정수를 입력하세요 : "))


for i in range(2, num) :
  if num % i == 0:
       print(num, "은 소수(prime number)가 아닙니다.")
       break

else :
  print(num, "은 소수(prime number) 입니다.")

  
