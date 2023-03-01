import numpy as np
import os
import matplotlib.pyplot as plt
import matplotlib as mpl

mpl.rcParams['font.size'] = 16
import math

plt.title("Assimptotics")
plt.xlabel("Size of massive")
plt.ylabel("Time")
b = [0] * 4896
x1 = [0] * 4896
y1 = [0] * 4896
x2 = [0] * 4896
y2 = [0] * 4896
with open("points.txt", "r") as file:
    a = file.readlines()

for i in range(0, 4896):
    x1[i] = 500 * int(a[i].split(", ")[0])
    x2[i] = int(a[i].split(", ")[0])
    y1[i] = int(a[i].split(", ")[1])
    y2[i] = int(a[i].split(", ")[2])

x1 = np.array(x1)
x2 = np.array(x2)
y1 = np.array(y1)
y2 = np.array(y2)

plt.plot(x1, y1)
plt.show()

plt.plot(x2, y2)
plt.show()
print(max(y2))