'''
작성일 : 23/5/16
작성자 : 김민채
목적 : 파일 읽어서 내용 확인하기
'''

def CountFile(filename):
    words = 0
    chars_NotInclude = 0
    chars_Include = 0
    rows = 0

    try:
        f = open(filename, "r")
    except:
        print("Error opening reading file")
    else:
        all_lines = f.read()
        lines = all_lines.split("\n")
        all_lines_not_empty = all_lines.replace("\n", "")
        all_lines_in_empty = all_lines.replace("\n", " ")

        # 단어수
        words = len(all_lines_in_empty.split(" "))

        # 문자 수(공백제외)
        chars_NotInclude = len(all_lines_in_empty.replace(" ", ""))

        # 문자 수(공백포함)
        chars_Include = len(all_lines_not_empty)

        # 줄 수
        rows = len(lines)
        
        f.close()

    return words, chars_NotInclude, chars_Include, rows


# main *******************************

# 1) input.txt 읽어서 내용 확인
words, chars_NotInclude, chars_Include, rows = CountFile("input.txt")

# 2) output.txt에 저장
try:
    fw = open("output.txt", "w")
except:
    print("Error opening writing file")
else:
    fw.write("단어수: " + str(words) + "\n")
    fw.write("문자수(공백제외): " + str(chars_NotInclude) + "\n")
    fw.write("문자수(공백포함): " + str(chars_Include) + "\n")
    fw.write("줄 수: " + str(rows))
    fw.close()

# 3) output.txt 읽어서 출력
try:
    fr = open("output.txt", "r")
except:
    print("Error opening reading file")
else:
    lines = fr.readlines()
    for i in range(len(lines)):
        print(lines[i])
    fr.close()