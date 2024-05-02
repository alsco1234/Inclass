'''
작성일 : 23/5/16
작성자 : 김민채
목적 : Matplotlib를 활용하여 파이챠트를 그리기
'''

import matplotlib.pyplot as plt
import numpy as np

y = np.array([20, 20, 35, 15, 10])
mylabels = ["Kyunggi", "Chungcheng", "Seoul", "Jellra", "kyungsang"]

plt.pie(y, labels = mylabels)
plt.legend(title = "Five Districts")
plt.show()