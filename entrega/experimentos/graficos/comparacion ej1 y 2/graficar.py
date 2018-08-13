import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np
from scipy import stats
f = open('peor.txt','r')
g = open('peor2.txt','r')
peor_ej2 = []
peor_ej1 = []
longitud = int(f.readline())
for value in range(0,longitud):
    hola = f.readline()
    peor_ej2.append(int(f.readline()))
longitud = int(g.readline())
for value in range(0,longitud):
    hola = g.readline()
    peor_ej1.append(int(g.readline()))
elementos = [2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40]
df = pd.DataFrame({'elementos': elementos,'peor_ej2':peor_ej2,'peor_ej1':peor_ej1})
plt.clf()
df.plot(x='elementos', logy = True)
plt.ylabel('Tiempo (milisegundos)')
plt.show()
