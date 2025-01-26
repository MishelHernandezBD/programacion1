// Revisor: Britany Mishel Hernandez Davila
Algoritmo Matematicas
	EligeSalir <- Falso
	Escribir 'Ingresar un número:'
	Leer N
	Repetir
		Escribir ' '
		Escribir 'Presione una tecla para continuar'
		Esperar Tecla
		Limpiar Pantalla
		Escribir 'Elija una opción:'
		Escribir '  1 - Seno, coseno, arcotangente'
		Escribir '  2 - Lograritmo natural, función exponencial'
		Escribir '  3 - Truncar, redondear'
		Escribir '  4 - Raíz cuadrada'
		Escribir '  5 - Valor absoluto'
		Escribir '  6 - Separar parte entera y decimal'
		Escribir '  7 - Hallar factorial'
		Escribir '  8 - Averiguar si es primo'
		Escribir '  9 - Ingresar otro número'
		Escribir '  0 - Salir'
		Escribir ' '
		Leer eleccion
		Según eleccion Hacer
			1:
				Escribir 'Seno:', Sen(N)
				Escribir 'Coseno:', Cos(N)
				Escribir 'Arcotangente:', Atan(N)
			2:
				Si N<=0 Entonces
					Escribir 'El numero debe ser mayor a cero!'
				SiNo
					Escribir 'Logaritmo natural: ', ln(N)
					Escribir 'Función exponencial: ', exp(N)
				FinSi
			3:
				Escribir 'Truncar: ', Trunc(N)
				Escribir 'Redondear: ', redon(N)
			4:
				Escribir 'Raiz Cuad.: ', RC(N)
			5:
				Escribir 'Valor Abs.: ', abs(N)
			6:
				Escribir 'Parte Entera: ', Trunc(N)
				Escribir 'Parte Decimal: ', N-Trunc(N)
			7:
				Si N<>Trunc(N) Entonces
					Escribir 'El numero debe ser entero!'
				SiNo
					Si abs(N)>50 Entonces
						Escribir 'Resultado muy grande!'
					SiNo
						r <- 1
						f <- 1
						Mientras f<=abs(N) Hacer
							Si N<0 Entonces
								r <- (-f)*r
							SiNo
								r <- f*r
							FinSi
							f <- f+1
						FinMientras
						Escribir 'Factorial:', r
					FinSi
				FinSi
			8:
				Si N<>Trunc(N) Entonces
					Escribir 'El numero debe ser entero!'
				SiNo
					Si N<0 Entonces
						Nu <- N*(-1)
					SiNo
						Nu <- N
					FinSi
					Si N MOD 2=0 Entonces
						Escribir 'Numero Primo:', Nu=2
						Si Nu<>2 Entonces
							Escribir N, '=2x', N/2
						FinSi
					SiNo
						EsPrimo <- Nu<>1
						Nu <- RC(Nu)
						Divisor <- 3
						Mientras Divisor<=Raiz(Nu) Y EsPrimo Hacer
							Si N MOD Divisor=0 Entonces
								EsPrimo <- Falso
							SiNo
								Divisor <- Divisor+2
							FinSi
						FinMientras
						Escribir 'Numero primo:', EsPrimo
						Si N>1 Y  NO EsPrimo Entonces
							Escribir N, '=', Divisor, 'x', N/Divisor
						FinSi
					FinSi
				FinSi
			9:
				Escribir 'Ingrese un número:'
				Leer N
			0:
				EligeSalir <- Verdadero
			De Otro Modo:
				Escribir 'eleccionción  no válida!'
		FinSegún
	Hasta Que EligeSalir
FinAlgoritmo
