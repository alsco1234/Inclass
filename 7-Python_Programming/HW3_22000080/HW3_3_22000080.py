'''
작성일 : 23/4/10
작성자 : 김민채
목적 : 리스트를 복수명사로 만들기
'''

word = ['apple', 'book', 'box', 'buzz', 'cat', 'cantus', 'church', 'dish', 'knife', 'lady', 'leaf',  'pitch', 'stimulus', 'taxi', 'wish', 'wolf']
plural = []

for i in range(len(word)):

    # a. 명사의 끝이 'y'인 경우
    if word[i][-1] == 'y':
        plural.append(word[i][:-1] + 'ies')

    # b. 명사의 끝이 'f' 혹은 'fe'인 경우
    elif word[i][-1] == 'f':
        plural.append(word[i][:-1] + 'ves')
    elif word[i][-2:] == 'fe':
        plural.append(word[i][:-2] + 'ves')

    # d. 명사의 끝이 'us'로 끝나는 경우
    elif word[i][-2:] == 'us':
        plural.append(word[i][:-2] + 'i')

    # c. 명사의 끝이 's', 'x', 'z', 'ch', 'sh'인 경우
    elif word[i][-1] == 's' or word[i][-1] == 'x' or word[i][-1] == 'z':
        plural.append(word[i] + 'es')
    elif word[i][-2:] == 'ch' or word[i][-2:] == 'sh':
        plural.append(word[i] + 'es')

    # e. 위의 4가지 경우가 아닌 경우
    else:
        plural.append(word[i] + 's')

for i in range(len(plural)):
    print(word[i], "-", plural[i])