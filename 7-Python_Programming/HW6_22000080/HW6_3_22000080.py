'''
작성일 : 23/5/9
작성자 : 김민채
목적 : 마방진(Magic Square)
'''

# row, col이 정상적인 위치인지
def is_in(rnc, n):
    if rnc >= 0 and rnc < n:
        return True
    return False

# magic_square 초깃값 정의하여 반환
def define_magic_square(nun):
    magic_square = []

    for i in range(nun):
        row = []
        for j in range(nun):
            row.append(0)
        magic_square.append(row)

    return magic_square

# magic_square 마방진값 넣기
def make_magic_square(magic_square):
    n = len(magic_square[0])  # 마방진의 크기
    row = 0
    col = 2

    for i in range(1, n*n+1):
        magic_square[row][col] = i
        
        # 다음 위치 계산
        new_row = (row - 1) % n
        new_col = (col - 1) % n

        # 1) 이미 값이 있거나 row, col 둘다 없는 경우
        if (magic_square[new_row][new_col] != 0) or (not is_in(row, n) and not is_in(col, n)):
            row = (row + 1) % n
        # 2) row, col중 하나만 존재하지 않는 경우
        elif is_in(row, n) and not is_in(row, n):
            row = n-1
            col = new_col
        elif not is_in(row, n) and is_in(row, n):
            row = new_row
            col = n-1
        # 3) 갈 위치가 비어있고, row col이 모두 정상적인 경우
        else : 
            row = new_row
            col = new_col

# magic_square 출력
def print_magic_square(magic_square):
    for row in magic_square:
        for num in row:
            print(num, end="\t")
        print(" ")


# main ***
magic_square = define_magic_square(5)

make_magic_square(magic_square)

print_magic_square(magic_square)
