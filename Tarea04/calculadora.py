import math
clave = 0
while clave != 8:
  clave = int(input("Ingresa 1 para sumar, 2 para restar, 3 para mutiplicar, 4 para dividir, 5 para sin, 6 para cos, 7 para tan y 8 para salir\n"))
  if clave != 8:
     if clave <= 4:
        num1 = float(input("Ingresa el primer número\n"))
        num2 = float(input("Ingresa el segundo número\n"))
        if clave == 1:
           final = num1 + num2
           print("La suma es: %f"%(final))
        elif clave == 2:
            final = num1- num2
            print("La resta es: %f"%(final))
        elif clave == 3:
            final = num1 * num2
            print("El producto es: %f"%(final))
        else:
            if num2 != 0:
              final = num1/num2
              print("La división es: %f"%(final))
            else:
              print("No se puede dividir por cero")
     else:
        num1 = float(input("Ingresa un número\n"))
        if clave == 5:
           final = math.sin(num1)
           print("El seno es: %f"%(final))
        elif clave == 6:
           final = math.cos(num1)
           print("El coseno es: %f"%(final))
        elif clave == 7:
           final = float(math.tan(num1))
           print("La tangente es: %f"%(final))
        else:
           print("Clave no identificada")
