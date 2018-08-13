import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import numpy as np
from scipy import stats
f = open('peor.txt','r')
g = open('peor2.txt','r')
random1 = open('random.txt','r')
random2 = open('random2.txt','r')
iguales1 = open('iguales.txt','r')
iguales2 = open('iguales2.txt','r')
peor_ej1 = []
peor_ej2 = []
random_ej1 = []
random_ej2 = []
iguales_ej1 = []
iguales_ej2 = []
longitud = 20
hola = f.readline()
for value in range(0,longitud):
    hola = f.readline()
    peor_ej1.append(int(f.readline()))
hola = g.readline()
for value in range(0,longitud):
    hola = g.readline()
    peor_ej2.append(int(g.readline()))
hola = iguales2.readline()
for value in range(0,longitud):
    hola = iguales2.readline()
    iguales_ej2.append(int(iguales2.readline()))
hola = iguales1.readline()
for value in range(0,longitud):
    hola = iguales1.readline()
    iguales_ej1.append(int(iguales1.readline()))

hola = random2.readline()
for value in range(0,longitud):
    hola = random2.readline()
    random_ej2.append(int(random2.readline()))
hola = random1.readline()
for value in range(0,longitud):
    hola = random1.readline()
    random_ej1.append(int(random1.readline()))


elementos = [2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40]
df = pd.DataFrame({'elementos': elementos,'peor_ej2':peor_ej2,'peor_ej1':peor_ej1,'random_ej1':random_ej1,'random_ej2':random_ej2,'iguales_ej1':iguales_ej1,'iguales_ej2':iguales_ej2})
plt.clf()
df.plot(x='elementos', logy = True)
plt.ylabel('Tiempo (milisegundos)')
plt.show()
