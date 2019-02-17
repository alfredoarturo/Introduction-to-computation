import math
f = []
print("Introduzca un valor para el dominio de la funcion\n");
N = int(input())
print("Introduzca un valor para el periodo de la funcion\n");
k = int(input())
F=2*math.pi/N
for n in range(0,N):
    f[n]= math.sin(F*k*n)

for n in range(0, N):
    print("f[%d]->%f\n",n,f[n])

print("Introduzca el valor a evaluar en la funcion\n")
inp = float(input())
min =int(inp)
max = min + 1
final = ((f[max]-f[min])*(inp-min)/(max-min))+f[min]
printf("La respuesta es: %f",final)