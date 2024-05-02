Birthdate = input("생년월일을 입력하세요: ")

Year = Birthdate[0:4]
Month = Birthdate[4 : 6]
Day = Birthdate[6: ]

if Month < "01" or Month > "12" :
     print("월이 잘못 입력 되었습니다, 다시 실행해 주세요!")

if Birthdate > "20200301" :
    print("나이를 계산할 수 없습니다")
else:
    age = 2020 - int(Year)

    if Month > "03" :
        age = age - 1

    print("당신의 나이는 ", age, " 입니다")