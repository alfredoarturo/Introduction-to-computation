conv = float(input("Ingresa 1 para convertir Celsius a Fahrenheit, 2 para convertir de Fahrenheit a Celcius\n"))
if conv == 1:
   grados = float(input("Ingresa los grados Celsius\n"))
   final = (1.8*grados) + 32
   print("%f grados Celsius son %f grados Fahrenheit"%(grados, final))
else:
   grados = float(input("ingresa los grados Fahreheit\n"))
   final = (grados - 32) / 1.8
   print("%f grados Fahrenheit son %f grados Celsius"%(grados, final))

