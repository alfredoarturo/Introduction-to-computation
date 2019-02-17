reservar_mem_v1:
	input:
		renglones y columnas, dos enteros
	output:
		regresa memoria no continua reservada para la matriz

reservar_mem_v2:
	input:
		renglones y columnas, dos enteros
	output:
		regesa memoria continua reservada para la matriz

sumaparamult:
	input:
		dos apuntadores a float, que son a las matrices, dos enteros i, j que es el sub-indice de la matriz y r el numero de renglones.
	output:
		regresa el producto punto

multiplicaMatriz:
	input:
		dos matrices matrices, los renglones de la primera, los renglones de la segunda y las columnas de la segunda.
	output:
		regresa un apuntador de memoria con la matriz multiplicada

llenar Matriz:
	input:
		una matriz con sus renglones y matrices
	output:
		una matriz rellena con valores aleatorios

transpuesta_v1:
	input:
		una matriz, sus renglones y columnas
	output:
		regesa la transpuesta a la matriz ingresada, con memoria no continua

transpuesta_v2:
	input:
		una matrix, sus renglones y columnas
	output:
		regesa la transpuesta a la matriz ingresada, con memoria continua

liberarMem_v1:
	input:
		libera la memoria para la memoria no continua

leberarMem_v2:
	input:
		libera la memorioa para la memoria continua

main:
	aquí se declaran las matrices que se van a usar, se imprime la diferencia de tiempos en la multiplicacion entre la multiplicacion de momoria continua y no continua.