import math
conv = float(input("1 para convertir de Grados a Radianes, 2 para convertir de Radianes a Grados\n"))
if conv == 1:
   inp = float(input("Ingresa los Grados\n"))
   final = inp*math.pi/180
   print("%f Grados son %f Radianes"%(inp, final))
else:
   inp = float(input("Ingresa los Radianes\n"))
   final = inp*180/math.pi
   print("%f Radianes son %f Grados"%(inp, final))
