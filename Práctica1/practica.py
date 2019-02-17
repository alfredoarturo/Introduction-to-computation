palabra = str(input("Ingresa una cadena para ber si es palindromo\n"))
i = 0
pal = True
while i < len(palabra):
   uno = palabra[i]
   dos = palabra[(len(palabra)-i)-1]
   if uno == dos:
      pass
   else:
      pal = False
   i = i +1
if pal:
   print("Es palindromo")
else:
   print("No es palindromo")
