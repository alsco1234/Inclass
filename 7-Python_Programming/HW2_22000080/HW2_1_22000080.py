'''
작성일 : 23/3/21
작성자 : 김민채
목적 : 키, 몸무게 그리고 인종을 입력받아 BMI 계산 후 출력하기
'''

height = float(input("키를 입력하세요 (m) : "))
weight = float(input("체중을 입력하세요 (kg) : "))
race = int(input("인종을 입력하세요 (유럽인=1, 아시아인=2)"))

if race != 1 and race != 2:
    print("인종을 다시 입력하세요.")
else :
    bmi = weight / (height * height)

    if bmi < 18.5 : 
        print("[저체중] 입니다.")
    elif bmi < 23 :
        if race == 1: print("[정상I] 입니다.")
        elif race == 2: print("[정상] 입니다.")
    elif bmi < 25 :
        if race == 1: print("[정상II] 입니다.")
        elif race == 2: print("[과체중] 입니다.")
    elif bmi < 30 :
        if race == 1: print("[과체중] 입니다.")
        elif race == 2: print("[비만I] 입니다.")
    elif bmi < 40 :
        if race == 1: print("[비만I] 입니다.")
        elif race == 2: print("[비만II] 입니다.")
    else:
        if race == 1: print("[비만II] 입니다.")
        elif race == 2: print("[심각한 비만] 입니다.")