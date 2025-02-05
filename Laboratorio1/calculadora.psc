Algoritmo calculadora
	//Definir variables
	Definir operacion Como Entero
	Definir num1, num2, resultado Como Real
	//Menu de operaciones 
	Repetir
		Escribir "1. Suma"
		Escribir "2. Resta"
		Escribir "3. Multiplicación"
		Escribir "4. División"
		Escribir "5. Salir"
		Escribir "Seleccione el numero de la operacion: "
		Leer operacion
		
		//Operaciones 
		Si operacion >= 1 Y operacion <= 4 Entonces
			Escribir "Ingrese el primer número: "
			Leer num1
			Escribir "Ingrese el segundo número: "
			Leer num2
			
			Segun operacion Hacer
				Caso 1:
					resultado <- num1 + num2
					Escribir "Respuesta: ",resultado
				Caso 2:
					resultado <- num1 - num2
					Escribir "Respuesta: ",resultado
				Caso 3:
					resultado <- num1 * num2
					Escribir "Respuesta: ",resultado
				Caso 4:
					Si num2 <> 0 Entonces
						resultado <- num1 / num2
						Escribir "Respuesta: ",resultado
					Sino
						Escribir "Error: No se puede dividir entre cero."
					FinSi
			FinSegun
		Sino
			//Salida
			Si operacion = 5 Entonces
				Escribir "Vuelva pronto"
			Sino
				Escribir "Ingrese una opccion valida"
			FinSi
		FinSi
	Hasta Que operacion = 5
FinAlgoritmo
