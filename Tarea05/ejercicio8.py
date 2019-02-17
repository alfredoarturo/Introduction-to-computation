string = input("Ingresa una cadena de caracteres para sacar la media\n")
i = 0
suma = 0
lista = []
while i < len(string):
   suma = suma + ord(string[i])
   i += 1
media = chr(int(suma/len(string)))
numero = int(suma/len(string))
print("La media de los caracteres es: %s y numericamente es: %d"%(media, numero))
