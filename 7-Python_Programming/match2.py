'''
작성일 : 23/3/10
작성자 : 김민채
목적 : match_case 연습, 문자열 크기 비교
'''

# *** EXERCISE 1 ***

for ch in ["a", "b", "c", "b", "x", "y"]:
    match ch:
        case "a" | "d":
            print(1)
        case "b" | "e":
            print(2)
        case "c" | "1":
            print(3)
        case _:
            print(ch)

# *** EXERCISE 2 ***

number = int(input("input integer = "))
mod_3 = number % 3
mod_5 = number % 5

match (mod_3, mod_5):
    case (0, 0):
        print("3, 5의 배수")
    case (0, _):
        print("3의 배수")
    case (_, 0):
        print("5의 배수")
    case (_, _):
        print("3, 5의 배수 아님 ", number)

# *** EXERSIZE 3 ***

print("한글" > "english") # True

        
