string = str(input("Ingresa una cadena de caracteres para obtener la mediana\n"))
lista = []
final = []
aux = ""
i = 0
while i < len(string):
   lista.append(ord(string[i]))
   i += 1
i = 0
while i < len(lista):
   a = 0
   while i-a >= 0:
      if lista[i] < lista[i-a]:
         aux = lista[i-a]
         lista[i-a] = lista[i]
         lista[i] = aux
         a = 0
      else:
         aux = lista[i]
         lista[i] = lista[i-a]
         lista[i-a] = aux
      a += 1
   i += 1
final.append(lista[len(lista)-1])
i = 0
while i < len(lista)-1:
   final.append(lista[i])
   i += 1

if len(final) % 2 == 1:
    print("la mediana es: %s"%(chr(final[int(len(final)+1)/2])))
else:
    print("la mediana es: %s"%(chr(int((final[int(len(final)/2)]+final[int(len(final)/2)+1])/2))))
