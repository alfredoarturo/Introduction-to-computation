print("Introduzca 5 números")

maxnum = 0
minnum = 0

num1 = float(input("Introduzca el primer número\n"))
num2 = float(input ("Introduzca el segundo número\n"))
num3 = float(input("Introduzca el tercer número\n"))
num4 = float(input("Introduzca el cuarto número\n"))
num5 = float(input("Introduzca el quinto número\n"))

if num1 < num2:
   maxnum = num2
   minnum = num1

else:
   minnum = num2
   maxnum = num1

if maxnum < num3:
   maxnum = num3

else:
   if minnum > num3:
      minnnum = num3

if maxnum < num4:
   maxnum = num4

else:
   if minnum > num4:
      minnum = num4

if maxnum < num5:
   maxnum = num5

else:
   if minnum > num5:
      minnum = num5

print("El mayor número es: %f y el menor número es: %f"%(maxnum,  minnum))
