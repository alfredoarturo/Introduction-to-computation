print("Introduce el primer número")
num1 = int(input())
print("Introduce el segundo número")
num2 = int(input())
print("Introduce el tercer número")
num3 = int(input())
if num1 > num2:
   if num1 > num3:
      print("El mayor número es: %d"%(num1))
   else:
      print("El mayor número es: %d"%(num3))
else:
   if num2 > num3:
      print("El mayor número es: %d"%(num2))
   else:
      print("el mayor número es: %d"%(num3))
