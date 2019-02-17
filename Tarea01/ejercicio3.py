print("Introduce el coeficiente de x²")
a = int(input())
print("Introduce el coeficiente de x¹")
b = int(input())
print("Introduce el coeficiente de x⁰")
c = int(input())
if (b**2)-4*a*c > 0:
   raiz1 = (-b + ((b**2) - 4*a*c)**(1/2))/(2*a)
   raiz2 = (-b - ((b**2) - 4*a*c)**(1/2))/(2*a)
   print("Las raíces a la ecuación son: %f, %f"%(raiz1, raiz2))
else:
   print("La ecuación no tiene raíces reales")
