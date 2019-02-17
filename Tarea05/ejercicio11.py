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
i = 0
maxcamb = 0
camb = 0
moda = 0
letra_camb = final[0]
while i < len(final)-1:
    if letra_camb == final[i]:
        camb += 1
    else:
        camb = 1
        letra_camb = final[i]
    if camb > maxcamb:
        moda = i
        maxcamb = camb
    else:
        pass
    i += 1
print("La moda es: %s"%(chr(final[moda])))
