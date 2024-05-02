'''
작성일 : 23/3/10
작성자 : 김민채
목적 : 수업내 코딩 연습
'''

# *** EXERCISE 1 ***

num1 = int(input("첫 번째 정수를 입력하세요 : "))
num2 = int(input("두 번째 정수를 입력하세요 : "))

print(num1, "+", num2, "=", num1 + num2)
print(num1, "*", num2, "=", num1 * num2)
print(num1, "/", num2, "=", num1 / num2)
print(num1, "//", num2, "=", num1 // num2)
print(num1, "**", num2, "=", num1 ** num2)
print(num1, "%", num2, "=", num1 % num2)


# *** EXERCISE 2 ***

gender = int(input("성별을 입력해주세요 (1:남자, 2:여자) : "))

if gender == 1:
    print("당신은 남자입니다.")
elif gender == 2:
    print("당신은 여자입니다.")
else:
    print("잘못 입력하셨습니다.")

# *** EXERCISE 3 ***

age = int(input("나이를 입력하세요 : "))

if age > 60:
    print("당신은 senior 입니다.")
else:
    print("당신은 junior 입니다.")
