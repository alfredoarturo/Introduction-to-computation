f = [0,0,0,0,0,0,0,0,0,0]
enc = 0
print("Ingresa 10 numeros")
for n in range(0, 10):
	f[n] = int(input())
print("Ingresa el numero a buscar")
num1 = int(input())
for n in range(0, 10):
	if f[n] == num1:
		enc = 1
if enc == 1:
	print("El numero %d esta en la lista"%num1)
else:
	print("El numero %d no esta en la lista"%num1)