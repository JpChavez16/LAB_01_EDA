import matplotlib.pyplot as plt
import numpy as np

distancias_2 = np.loadtxt("distancias_5000.txt")
plt.hist(distancias_2, bins=10, edgecolor='black', color='steelblue')
plt.xlabel('Distancia Euclidiana')
plt.ylabel('Frecuencia')
plt.title('Histograma de Distancias Euclidianas Dimensión 5000')
plt.grid(True)
plt.show()
