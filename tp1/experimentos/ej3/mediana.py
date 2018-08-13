import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import pylab as pl
import random
import numpy as np
# script que dado un documento de texto con
f = open('resultados_random_ej3.txt', 'r')
g = open('random.txt', 'w')
tamanio = int(f.readline())
g.write(str(tamanio)+'\n')
for value in range(0,tamanio):
    character = f.readline()
    g.write(character)
    resultados = []
    for value in range(0,10):
        resultados.append(int(f.readline()))
    mean = np.mean(resultados[0:10])
    parteEntera= int(mean)
    g.write(str(parteEntera)+'\n')
