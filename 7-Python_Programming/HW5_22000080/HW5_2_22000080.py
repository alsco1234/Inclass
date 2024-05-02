'''
작성일 : 23/5/9
작성자 : 김민채
목적 : 숫자 야구 게임 만들기
'''
import random

def check_list(listname,input_num):
    if input_num in listname:
        return True
    else:
        return False

res = random.sample(range(0, 10), 4)
print("컴퓨터가 설정한 리스트:", res, "\n")

usr_try = 0

while(True):
    usr = []
    strike = 0
    ball = 0

    while(len(usr) < 4):
        num = input(">>>Input a number: ")
        if not num.isdigit() or int(num) < 0 or int(num) > 9:
            print("Please input a nunber from 0 to 9")
        elif check_list(usr, int(num)):
            print("Duplicate number")
        else:
            usr.append(int(num))

    for i in range(4):
        if usr[i] in res:
            if i == res.index(usr[i]):
                strike += 1
            else:
                ball += 1
    usr_try += 1
    print(f'{strike}-strike, {ball}-ball\n')

    if strike == 4:
        print("You win! on", usr_try, "try..")
        break
    