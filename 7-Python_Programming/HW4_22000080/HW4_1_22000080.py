'''
작성일 : 23/4/23
작성자 : 김민채
목적 : 오차값을 입력받아 시점의 pi 출력하기
'''
    
err = float(input("오차값을 실수로 입력하세요: "))
if err > 0.01:
    print("0.01 이하 값만 입력하세요")
else:
    pi = 0.0
    i = 0
    while(True):
        i += 1
        term = (4 / (2*i -1))

        if term < err:
            print(f'{pi:.20f}')
            break

        if i%2 == 0:
            pi -= term
        else:
            pi += term
