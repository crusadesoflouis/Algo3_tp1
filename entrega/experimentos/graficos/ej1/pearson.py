import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
from scipy import stats
import random

elementos = [2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40]
f = open('peor.txt', 'r')
tamanio = []
tiempo = []
longitud = int(f.readline())
for value in range(0,longitud):
    tamanio.append(int(f.readline()))
    tiempo.append(int(f.readline()))

complejidad = [0 + (n^3) for n in range(0,longitud)]
df2 = pd.DataFrame()
df2['elementos'] = elementos
df2['Tiempo'] = tiempo
df2['Complejidad exponecial'] = complejidad
sns.jointplot(df2['Complejidad exponecial'], df2['Tiempo'], kind="reg")
sns.plt.show()
