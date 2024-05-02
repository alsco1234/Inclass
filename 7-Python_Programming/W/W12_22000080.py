'''
작성일 : 23/5/9
작성자 : 김민채
목적 : 11주차 수업내 코딩 연습
'''

# *** EXERCISE : 파일 읽어서 평균 출력하기 ***
with open('num.txt', 'r') as f:
    line = None # 파일에서 읽은 한줄
    all_avg = 0.0 # 전체 줄 평균
    count = 0 # 읽은 번째 줄

    # 한줄씩읽기
    while True :
        line = f.readline()
        if len(line) == 0:
            break
        count += 1

        # 전처리
        newline = line.replace(" ", "")
        nums = newline[:-1].split(",")

        # res라는 리스트에 저장
        res = []
        for i in range(len(nums)):
            if nums[i] != '':
                res.append(int(nums[i]))

        # 줄 평균 구하고 출력
        all_avg += (sum(res) / len(res))
        print(count, ":", sum(res) / len(res) )

    # 전체 평군 츨략
    print("전체평균 : ", all_avg / count)