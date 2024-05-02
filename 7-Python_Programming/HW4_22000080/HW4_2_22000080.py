'''
작성일 : 23/4/23
작성자 : 김민채
목적 : 화학식을 입력받아 분자량 계산하기
'''

chemical = input("화학식을 입력 하시오 : ")

sum = 0

i = 0
while(True):
    if i == len(chemical):
        break

    num = 1

    # 문자열 끝 분자 로 구성된 경우
    if i == len(chemical)-1:
        num = 1
    # 분자 로 구성된 경우
    elif chemical[i].isalpha() and not chemical[i+1].isdigit():
        num = 1
    # 분자 + 숫자로 구성된 경우 
    elif chemical[i].isalpha() and chemical[i+1].isdigit():
        num = int(chemical[i+1])

    match chemical[i]:
        case 'O':
            sum += 15.9994 * num
        case 'S':
            sum += 32.066 * num
        case 'C':
            sum += 12.011 * num
        case 'H':
            sum += 1.00794 * num
        case 'N':
            sum += 14.00674 * num
    
    i+=1

print(f'{chemical}의 분자량은 {sum:.5f}')
            

        