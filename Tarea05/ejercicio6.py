conv = float(input("Ingresa 1 para convertir horas y minutos a segundos y 2 para convertir segundos a horas y minutos\n"))
if conv == 1:
   horas = int(input("Ingresa las horas\n"))
   minutos = int(input("Ingresa los minutos\n"))
   final = minutos*60 + horas*3600
   print("%f horas con %f minutos son %d segundos"%(horas, minutos, final))
else:
   seg = int(input("Ingresa los segundos\n"))
   horas = int(seg/3600)
   segundos = seg % 60
   minutos = int((seg-horas*3600)/60)
   print("%d segundos son %d horas con %d minutos con %d segundos"%(seg, horas, minutos, segundos))
