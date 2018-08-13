import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np
from scipy import stats
import random
f = open('random.txt', 'r')
tamanio = []
tiempo = []
longitud = int(f.readline())
for value in range(0,longitud):
    tamanio.append(int(f.readline()))
    tiempo.append(int(f.readline()))
elementos = list(range(2,732,2))
complejidad = [0 + (1.9**n) for n in range(0,longitud)]
df2 = pd.DataFrame()
df2['elementos'] = elementos
df2['Tiempo'] = tiempo
df2['Complejidad exponencial'] = complejidad
sns.jointplot(df2['Complejidad exponencial'], df2['Tiempo'], kind="reg")
sns.plt.show()
