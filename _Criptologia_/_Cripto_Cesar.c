#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char ArrAphanumeric[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char Input_string[50];
char Output_string[50];

int comparar(char b);
void vaciar_arr();
void crifrado_cesar();
void descifrado_cesar();

int main(){
	int opc = 0;
	char opc_intern = ' ';
	do
	{
		printf("<<=========================TIPOS DE CIFRADO=========================>>\n");
		printf("<<========================1.- Cifrado Cesar=========================>>\n");
		printf("<<========================2.- Cifrado ==============================>>\n");
		printf("<<========================3.- Cifrado ==============================>>\n");
		printf("<<========================4.- Salir=================================>>\n");
		printf("--->> Ingrese su opcion: ");
		scanf("%d", &opc);
		switch(opc){
			case 1: {
				printf("<<=======================  CIFRADO CESAR=========================>>\n");
				printf("<<======================= a.- CIFRAR    =========================>>\n");
				printf("<<======================= b.- DESCIFRAR =========================>>\n");
				printf("--->> Ingrese su opcion: ");
				scanf("%s",&opc_intern);
				if (opc_intern == 'a')
				{
					printf("CIFRAR\n");
					crifrado_cesar();
					vaciar_arr();
				}else if (opc_intern == 'b')
				{
					printf("DESCIFRAR\n");
					descifrado_cesar();
					vaciar_arr();
				}
				break;
			}
			case 2:{
				printf("<<=======================  CIFRADO CESAR=========================>>\n");
				printf("<<======================= a.- CIFRAR    =========================>>\n");
				printf("<<======================= b.- DESCIFRAR =========================>>\n");
				printf("--->> Ingrese su opcion: ");
				scanf("%s",&opc_intern);
				if (opc_intern == 'a')
				{
					printf("CIFRAR\n");
					crifrado_cesar();
					vaciar_arr();
				}else if (opc_intern == 'b')
				{
					printf("DESCIFRAR\n");
					descifrado_cesar();
					vaciar_arr();
				}
				break;
			}
			case 3:{
				break;
			}
			case 4:{
				printf("BYE\n");
				break;
			}
			default: {
				printf("OPCION NO VALIDA\n");
				break;
			}
		}
	} while (opc != 4);
	return 0;
}

void descifrado_cesar(){
	int pos_val = 0;
	int input_lengt_arr = 0;
	int Clave_espaciado = 0;
	int aux_pos = 0, contador_pos_recorridas = 0;
	printf("Ingrese la su mensaje: ");
	scanf("%s", &Input_string);
	printf("Ingrese la Clave de espaciado: ");
	scanf("%d", &Clave_espaciado);
	int aux_clave = Clave_espaciado;

	input_lengt_arr = strlen(Input_string);
	printf("TAMANO DE ARRAY DE INPUT ---> %d \n", input_lengt_arr);

	printf("CODIFICANDO\n");

	for (int i = 0; i < input_lengt_arr; i++)
	{
		pos_val = comparar(Input_string[i]);
		Clave_espaciado = aux_clave;
		// if (aux_clave == Clave_espaciado)
		// {
		// 	printf("AMBAS CLAVES VALEN LO MISMO\n");
		// }
		int resultado = pos_val - Clave_espaciado;
		aux_pos = pos_val;
		if (pos_val < aux_clave)
		{
			while(aux_pos > 0){
				aux_pos--;
				contador_pos_recorridas++;
			}
			aux_clave = pos_val - contador_pos_recorridas;
			// printf("---->>> aux_clave vale %d \n", aux_clave);
			if (aux_clave == 0)
			{
				pos_val = 25;
				int tmp_clave = Clave_espaciado;
				Clave_espaciado = aux_clave;
				aux_clave = tmp_clave;
			}
			// printf("POSICIONES RECORRIDAS ANTES DEL 0 %d y el auxiliar de la posicion vale %d y la nueva posicion a regresar es: %d \n", contador_pos_recorridas, aux_pos, aux_clave);

		}
		// printf("===>>> pos_val %d Clave_espaciado ==>> %d\n", pos_val, Clave_espaciado);
		Output_string[i] = ArrAphanumeric[pos_val-Clave_espaciado];
		printf("===>> [ %d ] [ %c ]\n", pos_val, Output_string[i]);	
	}
	
	printf("Mensaje:[ %s ]\n", Input_string);
	printf("Mensaje Descifrado: [ %s ]\n", Output_string);
}

void crifrado_cesar(){
	int pos_val = 0;
	int input_lengt_arr = 0;
	int Clave_espaciado = 0;
	
	printf("Ingrese la su mensaje: ");
	scanf("%s", &Input_string);
	printf("Ingrese la Clave de espaciado: ");
	scanf("%d", &Clave_espaciado);
	
	input_lengt_arr = strlen(Input_string);
	printf("TAMANO DE ARRAY DE INPUT ---> %d \n", input_lengt_arr);

	printf("CODIFICANDO\n");

	for (int i = 0; i < input_lengt_arr; i++)
	{
		pos_val = comparar(Input_string[i]);
		Output_string[i] = ArrAphanumeric[pos_val+Clave_espaciado];
		printf("===>> [ %d ] [ %c ]\n", pos_val, Output_string[i]);	
	}
	
	printf("Mensaje:[ %s ]\n", Input_string);
	printf("Mensaje Cifrado: [ %s ]\n", Output_string);
}

int comparar(char b){
	char aux_a;
	char aux_b = b;
	int contador = 0;
	aux_a = ArrAphanumeric[contador];
	while(aux_a != aux_b){
		contador++;
		aux_a = ArrAphanumeric[contador];
	}
	printf("POS ---> [ %d ] VAL ---> [ %c ]\n",contador, aux_a);
	if (contador == 25)
	{
		return -1;
	}else {
		return contador;
	}
}

void vaciar_arr(){
	memset(Input_string, 0, 50 * (sizeof Input_string[0]) );
	memset(Output_string, 0, 50 * (sizeof Output_string[0]) );
}