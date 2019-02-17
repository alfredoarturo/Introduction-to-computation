f = [0,0,0,0,0,0,0,0,0,0]
print("Ingresa 10 numeros")
for n in range(0, 10):
	f[n] = int(input())
print("Ingresa el numero de lugares desplazados")
desp = int(input())
print("Shidt a la izquierda")
for n in range(0, 10):
	a = (desp + n) % 10
	print("%i, "%(f[a]), end = "")
print("\nShift a la derecha\n")
for n in range(0, 10):
	a = (n-desp+10) % 10
	print("%i, "%(f[a]), end="")
print("\n")