#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define DEBUG_ 0

const char ArrAlpha[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
const char Matrix_alphabet[4][7] = {{'a', 'b', 'c', 'd', 'e', 'f', 'g'},{'h', 'i', 'j', 'k', 'l', 'm', 'n'},{'o', 'p', 'q', 'r', 's', 't','u'},{'v', 'w', 'x', 'y', 'z','+','+'}};
char Input_string[50];
char Input_string_poly[250];
int Arr_output_poly[100];
char Output_string[50];

int comparar(char b);
void get_pos_poly(char value);
void vaciar_arr();
void crifrado_cesar();
void descifrado_cesar();
void cifrado_poly();
void descifrado_poly();
void show_matrix();
bool validate_char(char letra);
bool validate_number(char letra);
void get_chart_poly(int val_i, int val_j);


int main(){
	int opc = 0;
	char opc_intern = ' ';
	do
	{
		printf("<<=========================TIPOS DE CIFRADO=========================>>\n");
		printf("<<========================1.- Cifrado Cesar=========================>>\n");
		printf("<<========================2.- Cifrado Polybius======================>>\n");
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
				printf("<<=======================  CIFRADO POLYBIUS =======================>>\n");
				printf("<<======================= a.- CIFRAR    ===========================>>\n");
				printf("<<======================= b.- DESCIFRAR ===========================>>\n");
				printf("--->> Ingrese su opcion: ");
				scanf("%s",&opc_intern);
				if (opc_intern == 'a')
				{
					printf("CIFRAR\n");
					cifrado_poly();
					vaciar_arr();
				}else if (opc_intern == 'b')
				{
					printf("DESCIFRAR\n");
					show_matrix();
					descifrado_poly();
					vaciar_arr();
				}
				break;
			}
			case 3:{
				get_chart_poly(1,1);
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

void cifrado_poly(){
	int pos_val = 0, contador_validate = 0;
	int input_lengt_arr = 0;
	bool resultado = false;
	printf("Ingrese la su mensaje: ");
	scanf("%s", &Input_string);
	input_lengt_arr = strlen(Input_string);
	if (DEBUG_)
	{
		printf("\tTAMANO DE ARRAY DE INPUT ---> [ %d ]\n", input_lengt_arr);
	}
	while(resultado == false && contador_validate < input_lengt_arr){
		if (DEBUG_)
		{
			printf("vuelta %d val %c\n",contador_validate, Input_string[contador_validate]);
		}
		resultado = validate_char(Input_string[contador_validate]);
		contador_validate++;
	}
	if (DEBUG_)
	{
		printf("True = 1 | False = 0 [ %d ] \n",resultado);
	}
	if (resultado)
	{
		printf("\n\n\nERROR EL MENSAJE CONTIENE UN CARACTER NO VALIDO (ñ / Ñ / 0 ~ 9 )INTENTE DE NUEVO\n\n\n");
	}else{
		show_matrix();
		printf("Mensaje a crifrar ---> [ %s ]\n", Input_string);
		printf("Mensaje cifrado: ");
		for (int i = 0; i < input_lengt_arr; i++)
		{
			get_pos_poly(Input_string[i]);
			if(i+1 < input_lengt_arr){
				printf(",");
			}
		}
		printf("\n");		
	}
}

void descifrado_poly(){
	int pos_val = 0, contador_validate = 0, contador_pos_new_values = 0;
	int input_lengt_arr = 0;
	bool resultado = false;
	int aux_val_1 = 0, aux_val_2 = 0;
	printf("Ingrese la su mensaje cifrado: ");
	scanf("%s", &Input_string_poly);
	input_lengt_arr = strlen(Input_string_poly);
	if (DEBUG_)
	{
		printf("\tTAMANO DE ARRAY DE INPUT ---> [ %d ]\n", input_lengt_arr);
	}
	while(resultado == false && contador_validate < input_lengt_arr){
		if (DEBUG_)
		{
			printf("vuelta %d val [ %c || %d ]\n",contador_validate, Input_string_poly[contador_validate],Input_string_poly[contador_validate]);
		}
		resultado = validate_number(Input_string_poly[contador_validate]);
		contador_validate++;
	}
	if (DEBUG_)
	{
		printf("True = 1 | False = 0 [ %d ] \n",resultado);
	}
	if (resultado)
	{
		printf("\n\n\nERROR EL MENSAJE CONTIENE UN CARACTER NO VALIDO (ñ o Ñ)INTENTE DE NUEVO\n\n\n");
	}else{
		printf("Mensaje desencriptado: ");
		for (int i = 0; i < input_lengt_arr; i++)
		{
			if (DEBUG_)
			{
				printf("---> Pos [ %d ] Val [ %c ]\n",i,Input_string_poly[i]);
			}
			if (Input_string_poly[i] >= 49 && Input_string_poly[i] <= 57)
			{
				if (DEBUG_)
				{
					printf("\t-->> i [ %d ] ---> C [ %d ] ---->[ %c ] \n",i,contador_pos_new_values,Input_string_poly[i]);
				}
				if ((contador_pos_new_values % 2) == 0)
				{
					aux_val_1 = Input_string_poly[i] - '0';
					if (DEBUG_)
					{
						printf("aux_val_1 %d [ %c ]\n",aux_val_1, Input_string_poly[i]);
					}
				}else{
					aux_val_2 = Input_string_poly[i] - '0';
					if (DEBUG_)
					{
						printf("aux_val_2 %d [ %c ]\n",aux_val_2, Input_string_poly[i]);;
					}
					get_chart_poly(aux_val_1,aux_val_2);
				}
				contador_pos_new_values++;
			}
		}
		printf("\n");
	}
}

void get_chart_poly(int val_i, int val_j){
	printf("%c",Matrix_alphabet[val_i-1][val_j-1]);
}

void get_pos_poly(char value){
	int aux_pos = 0;
	char val;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			if (value == Matrix_alphabet[i][j])
			{
				if (DEBUG_)
				{
					printf("---> [ %c ]ENCONTRADO EN ---> [ %d ][ %d ]\n",value,i+1,j+1);
				}
				printf("(%d,%d)",i+1,j+1);
			}
		}
	}
}

void show_matrix(){
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			printf("[ %c ]", Matrix_alphabet[i][j]);
		}
		printf("\n");
	}
}

void descifrado_cesar(){
	int pos_val = 0, contador_validate = 0, input_lengt_arr = 0, Clave_espaciado = 0, aux_pos = 0, contador_pos_recorridas = 0;
	bool resultado = false;
	printf("Ingrese la su mensaje: ");
	scanf("%s", &Input_string);
	printf("Ingrese la Clave de espaciado: ");
	scanf("%d", &Clave_espaciado);
	int aux_clave = Clave_espaciado;

	input_lengt_arr = strlen(Input_string);

	if (DEBUG_)
	{
		printf("TAMANO DE ARRAY DE INPUT ---> %d \n", input_lengt_arr);
		printf("CODIFICANDO\n");
	}
	while(resultado == false && contador_validate < input_lengt_arr){
		if (DEBUG_)
		{
			printf("vuelta %d val %c\n",contador_validate, Input_string[contador_validate]);
		}
		resultado = validate_char(Input_string[contador_validate]);
		contador_validate++;
	}
	if (DEBUG_)
	{
		printf("True = 1 | False = 0 [ %d ] \n",resultado);
	}
	if (resultado)
	{
		printf("\n\n\nERROR EL MENSAJE CONTIENE UN CARACTER NO VALIDO (ñ o Ñ)INTENTE DE NUEVO\n\n\n");
	}else{
		for (int i = 0; i < input_lengt_arr; i++)
		{
			pos_val = comparar(Input_string[i]);
			Clave_espaciado = aux_clave;
			int resultado = pos_val - Clave_espaciado;
			aux_pos = pos_val;
			if (pos_val < aux_clave)
			{
				while(aux_pos > 0){
					aux_pos--;
					contador_pos_recorridas++;
				}
				aux_clave = pos_val - contador_pos_recorridas;
				if (aux_clave == 0)
				{
					pos_val = 25;
					int tmp_clave = Clave_espaciado;
					Clave_espaciado = aux_clave;
					aux_clave = tmp_clave;
				}
				if (DEBUG_)
				{
					printf("POSICIONES RECORRIDAS ANTES DEL 0 %d y el auxiliar de la posicion vale %d y la nueva posicion a regresar es: %d \n", contador_pos_recorridas, aux_pos, aux_clave);
				}

			}
			Output_string[i] = ArrAlpha[pos_val-Clave_espaciado];
			if (DEBUG_)
			{
				printf("===>> [ %d ] [ %c ]\n", pos_val, Output_string[i]);	
			}
		}
		printf("Mensaje:[ %s ]\n", Input_string);
		printf("Mensaje Descifrado: [ %s ]\n", Output_string);
	}
}

void crifrado_cesar(){
	int pos_val = 0, input_lengt_arr = 0, Clave_espaciado = 0, contador_validate = 0;
	bool resultado = false;
	printf("Ingrese la su mensaje: ");
	scanf("%s", &Input_string);
	printf("Ingrese la Clave de espaciado: ");
	scanf("%d", &Clave_espaciado);
	
	input_lengt_arr = strlen(Input_string);
	printf("TAMANO DE ARRAY DE INPUT ---> %d \n", input_lengt_arr);
	while(resultado == false && contador_validate < input_lengt_arr){
		if (DEBUG_)
		{
			printf("vuelta %d val %c\n",contador_validate, Input_string[contador_validate]);
		}
		resultado = validate_char(Input_string[contador_validate]);
		contador_validate++;
	}
	if (DEBUG_)
	{
		printf("True = 1 | False = 0 [ %d ] \n",resultado);
	}
	if (resultado)
	{
		printf("\n\n\nERROR EL MENSAJE CONTIENE UN CARACTER NO VALIDO (ñ o Ñ)INTENTE DE NUEVO\n\n\n");
	}else{	
		printf("CODIFICANDO\n");

		for (int i = 0; i < input_lengt_arr; i++)
		{
			pos_val = comparar(Input_string[i]);
			Output_string[i] = ArrAlpha[pos_val+Clave_espaciado];
			printf("===>> [ %d ] [ %c ]\n", pos_val, Output_string[i]);	
		}
		
		printf("Mensaje:[ %s ]\n", Input_string);
		printf("Mensaje Cifrado: [ %s ]\n", Output_string);
	}
}

int comparar(char b){
	char aux_a;
	char aux_b = b;
	int contador = 0;
	aux_a = ArrAlpha[contador];
	while(aux_a != aux_b){
		contador++;
		aux_a = ArrAlpha[contador];
	}
	if (DEBUG_)
	{
		printf("POS ---> [ %d ] VAL ---> [ %c ]\n",contador, aux_a);
	}
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

bool validate_char(char letra){
	if (letra == -61 || (letra >= 48 && letra <= 57))
	{
		return true;
	}else{
		return false;
	}
}

bool validate_number(char letra){
	if ( letra == ',' || (letra >= 40 && letra <= 41) || (letra >= 49 && letra <= 55))
	{
		return false;
	}else{
		return true;
	}	
}