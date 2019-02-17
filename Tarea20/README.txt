El archivo main.c contiene la carrera de caballos.
Para lograr hacer la carrera de caballos se implementaron varias funciones y una estructura.
La estructura caballo contiene dos enteros, que marcan las coordenadas x,y de los caballos.
Funciones:
	caballos:
		regresa un vector por la izquierda de caballos
		Inicializa las coordenadas x,y de los caballos para que no queden todos en el mismo renglón.
	mover:
		mueve a los caballos, si se tiene 1 avanza, si se tiene 0 no avanza.
		cuando un caballo llega a la meta termina con el programa
	limpiar_pantalla:
		pone toda la pantalla con espacios.
	dibujar_meta:
		dibuja la meta.
	imprimir:
		imprime a cada uno de los caballos en su posición actual.
	carrera:
		inicializa las funciones necesarias para la carrera
	run:
		reserva memoria y la semilla rand.
		Hace que carrera pueda funcionar.


El archivo string.c contiene lo siguiente:
	strlenRecursive:
		obtiene la longitud de una cadena y regresa un entero por la izquierda, recibe un apuntador a char
	reverseRecursive:
		revierte una cadena de caracteres de forma recursiva, recibe dos apuntadores a char, uno a la cadena original y otro a donde se va a poner la revertida.
	reverseInter:
		revierte una cadena de caracteres de forma interativa, recibe dos apuntadores a char, uno a la cadena original y otro a donde se va a poner la revertida.
	strcpyRecursive:
		copia una cadena de caracteres a otra cadena de caracteres de forma recursiva. Recibe dos apuntadores a char, uno a la cadena origina y otro a donde se va a copiar.
	strcpyInter:
		copia una cadena de caracteres a otro cadena de caracteres de forma interativa. Recibe dos apuntadores a char, uno a la cadena original y otro a donde se va a copiar.


El archivo recursivas.c contiene lo siguiente:
	factorialRecursive:
		recibe un long y regresa un long por la izquierda.
		Se regresa el factorial del número ingresado
	suma_de_enterosRrcursive:
		recibe un long y regresa un long por la izquierda.
		Se regresa la suma desde el 1 hasta el número ingresado
	strlenRecursive:
		recibe un apuntador a char y regresa por la izquierda un entero que es la longitud de la cadena ingresada.