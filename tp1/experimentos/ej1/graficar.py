import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np
from scipy import stats
f = open('iguales.txt', 'r')
g = open('peor.txt','r')
h = open('random.txt','r')
peor = []
iguales = []
random = []
longitud = int(f.readline())
for value in range(0,longitud):
    hola = f.readline()
    iguales.append(int(f.readline()))
longitud = int(g.readline())
for value in range(0,longitud):
    hola = g.readline()
    peor.append(int(g.readline()))
for value in range(0,longitud):
    hola = h.readline()
    random.append(int(h.readline()))
elementos = [2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40]
df = pd.DataFrame({'elementos': elementos,'iguales':iguales,'peor':peor,'random':random})
plt.clf()
df.plot(x='elementos',logy = True)
plt.ylabel('Tiempo (milisegundos)')
plt.show()
