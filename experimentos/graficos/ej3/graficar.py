import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np
from scipy import stats
f = open('peor.txt','r')
random1 = open('random.txt','r')
iguales1 = open('iguales.txt','r')
peor = []
random = []
iguales = []
longitud = int(f.readline())
for value in range(0,longitud):
    hola = f.readline()
    peor.append(int(f.readline()))

hola = iguales1.readline()
for value in range(0,longitud):
    hola = iguales1.readline()
    iguales.append(int(iguales1.readline()))


hola = random1.readline()
for value in range(0,longitud):
    hola = random1.readline()
    random.append(int(random1.readline()))


elementos = range(0, 730, 2)
df = pd.DataFrame({'elementos': elementos,'peor_ej':peor,'random':random,'iguales':iguales})
plt.clf()
df.plot(x='elementos', logy = True)
plt.ylabel('Tiempo (milisegundos)')
plt.show()
