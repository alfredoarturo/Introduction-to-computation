print("Ingresa 10 numeros")
f = [0,0,0,0,0,0,0,0,0,0]
for i in range(0, 10):
	f[i] = int(input())
print("Shift a la derecha")
for i in range(0, 9):
	print("%i, "%(f[i+1]), end='')
print(0)
print("Shift a la izquierda")
print("%i, "%(0), end='')
for i in range(1, 10):
	print("%i, "%(f[i-1]), end='')
print('')
