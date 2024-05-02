'''
작성일 : 23/4/11
작성자 : 김민채
목적 : 10개의 정수를 입력받아 계산하기
'''

nums = []

for i in range (1, 11):
    print(i, end='')
    num = int(input(" 번째 정수를 입력하시오 : "))
    nums.append(num)

print("리스트 :", nums)

# 1. 오른쪽 이동
nums.insert(0, nums[9])
nums.pop(-1)
print("오른쪽으로 한 칸씩 이동 :", nums)

# 2. 중간 2개 삭제
nums.pop(4)
nums.pop(4)
print("중간에 위치한 2개의 element 제거 :", nums)

# 3. 최댓값
print("전체 element중 가장 큰 수 :", max(nums))

# 4. 중복 판별
dup = []
for i in range(len(nums)):
    for j in range(len(nums)):
        if i!=j and nums[i] == nums[j]:
            dup.append(i)
if len(dup) == 0:
    print("중복 여부 체크 : no duplicate elements")
else:
    print("중복 여부 체크 : exit duplicate elements :", dup)

# 5. 합과 평균
print("저장된 값들의 합계는", sum(nums), ", 평균은", sum(nums)/8)