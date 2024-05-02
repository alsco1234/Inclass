'''
작성일 : 23/3/14
작성자 : 김민채
목적 : 3주차 수업내 코딩 연습
'''

# *** EXERCISE 1 ***

cel = int(input("섭씨 온도를 입력하세요 : "))

if cel <= -10:
    print("아주 추운 날씨")
elif cel <= 0:
    print("추운 날씨")
elif cel <= 12:
    print("살짝 싸늘한 날씨")
elif cel <= 25:
    print("활동하기 좋은 날씨")
elif cel <= 32:
    print("더운 날씨")
else:
    print("아주 더운 날씨")