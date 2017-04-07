import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np
from scipy import stats
f = open('resultados_mean.txt', 'r')
tamanio = []
tiempo = []
longitud = int(f.readline())
for value in range(0,longitud):
    tamanio.append(int(f.readline()))
    tiempo.append(int(f.readline()))

elementos = [2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50]
complejidad = [1500 + (n**2) for n in elementos]
df = pd.DataFrame({'elementos': elementos, 'Tiempo (nanosegundos)': tiempo})
plt.clf()
df.plot(x='elementos')
plt.ylabel('Tiempo (nanosegundos)')
plt.show()
