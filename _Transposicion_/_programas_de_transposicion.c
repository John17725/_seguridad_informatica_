#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define DEBUG_ 1

int calc_leng_matrix(int len_string_input);
void cifrate_transposition_by_rows();
void descifrate_transposition_by_rows();
int find_leng_matrix(int len_string_input);
void cifrate_transposition_rail_fence();
void decifrate_transposition_rail_fence();
void cifrate_transposition_rail_fence_key();
void decifrate_transposition_rail_fence_key();


int main()
{
	int option_menu = 0;
	char option_menu_intern = ' ', temp[10];
	do
	{
		printf("<<=========================TIPOS DE CIFRADO POR TRANSPOSICION =========================>>\n");
		printf("<<========================1.- TRANSPOSICION POR FILAS =================================>>\n");
		printf("<<========================2.- TRANSPOSICION POR RAIL FENCE ============================>>\n");
		printf("<<========================3.- TRANSPOSICION POR COLUMNAS CON CLAVE ====================>>\n");
		printf("<<========================4.- Salir ===================================================>>\n");
		printf("--->> Ingrese su opcion: ");
		fgets(temp,10,stdin);
		option_menu = atoi(temp);
		switch(option_menu){
			case 1: {
				printf("<<=======================  TRANSPOSICION POR FILAS =========================>>\n");
				printf("<<----------------------- a.- CIFRAR    ------------------------->>\n");
				printf("<<----------------------- b.- DESCIFRAR ------------------------->>\n");
				printf("--->> Ingrese su opcion: ");
				scanf("%s",&option_menu_intern);
				if (option_menu_intern == 'a')
				{
					printf("CIFRAR\n");
					cifrate_transposition_by_rows();

				}else if (option_menu_intern == 'b')
				{
					printf("DESCIFRAR\n");
					descifrate_transposition_by_rows();
				}else{
					printf("\n\n\tTU OPCION ES INCORRECTA\n\n\n");
				}
				return main();
				break;
			}
			case 2:{
				printf("<<=======================  TRANSPOSICION RAIL FENCE =======================>>\n");
				printf("<<----------------------------- a.- CIFRAR    ----------------------------->>\n");
				printf("<<----------------------------- b.- DESCIFRAR ----------------------------->>\n");
				printf("--->> Ingrese su opcion: ");
				scanf("%s",&option_menu_intern);
				if (option_menu_intern == 'a')
				{
					printf("CIFRAR\n");
					cifrate_transposition_rail_fence();
					
				}else if (option_menu_intern == 'b')
				{
					printf("DESCIFRAR\n");
					decifrate_transposition_rail_fence();				
				}
				break;
			}
			case 3:{
				printf("<<=====================  CIFRADO POR COLUMNAS CON CLAVE =======================>>\n");
				printf("<<----------------------- a.- CIFRAR    ------------------------->>\n");
				printf("<<----------------------- b.- DESCIFRAR ------------------------->>\n");
				printf("--->> Ingrese su opcion: ");
				scanf("%s",&option_menu_intern);
				if (option_menu_intern == 'a')
				{
					printf("CIFRAR\n");
					cifrate_transposition_rail_fence_key();
					
				}else if (option_menu_intern == 'b')
				{
					printf("DESCIFRAR\n");
					decifrate_transposition_rail_fence_key();					
				}
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
	} while (option_menu != 4);
	return 0;
}

void cifrate_transposition_rail_fence_key(){
	char string_input[100];
	int len_string_input = 0, row = 0, col = 0, count_pos = -1,llave = 0;
	printf("Ingrese su mensaje a cifrar: ");
	scanf("%s",&string_input);
	printf("Ingrese la llave: ");
	scanf("%d",&llave);
	len_string_input = strlen(string_input);
	char matriz_output[llave][len_string_input];
	for (int i = 0; i < llave; ++i)
	{
		for (int j = 0; j < len_string_input; ++j)
		{
			matriz_output[i][j] = '\n';
		}
	}
	for (int i = 0; i < len_string_input; ++i)
	{
		matriz_output[row][col++] = string_input[i];
		if (row == 0 || row == llave-1)
			count_pos = count_pos*(-1);
		row = row + count_pos;
	}

	printf("\n\tMensaje cifrado: [ ");
	for (int i = 0; i < llave; ++i)
	{
		for (int j = 0; j < len_string_input; ++j)
		{
			if (matriz_output[i][j]!='\n')
			{
				printf("%c",matriz_output[i][j]);
			}
		}
	}
	printf(" ]\n");
}

void decifrate_transposition_rail_fence_key(){
	char string_input[1000];
	int len_string_input = 0, row = 0, col = 0, count_pos = -1, count_position = 0, llave = 0;
	printf("Ingrese su mensaje a descifrar: ");
	scanf("%s",&string_input);
	printf("Ingrese la llave: ");
	scanf("%d",&llave);
	len_string_input = strlen(string_input);
	char matriz_output[llave][len_string_input];
	for (int i = 0; i < llave; ++i)
	{
		for (int j = 0; j < len_string_input; ++j)
		{
			matriz_output[i][j] = '\n';
		}
	}
	for (int i = 0; i < len_string_input; ++i)
	{
		matriz_output[row][col++]='*';
		if (row == 0 || row == llave-1)
			count_pos = count_pos * (-1);
		row = row + count_pos;
	}
	for (int i = 0; i < llave; ++i)
	{
		for (int j = 0; j < len_string_input; ++j)
		{
			if (matriz_output[i][j] == '*')
				matriz_output[i][j] = string_input[count_position++];
		}
	row = col = 0;
	count_pos = -1;
	}
	printf("Mensaje descifrado [ ");
	for (int i = 0; i < len_string_input; ++i)
	{
		printf("%c",matriz_output[row][col++]);
		if (row == 0 || row == llave-1)
			count_pos = count_pos * (-1);
		row = row + count_pos;
	}
	printf(" ]\n");
}

void cifrate_transposition_rail_fence(){
	char string_input[100];
	int len_string_input = 0, row = 0, col = 0, count_pos = -1;
	printf("Ingrese su mensaje a cifrar: ");
	scanf("%s",&string_input);
	len_string_input = strlen(string_input);
	char matriz_output[3][len_string_input];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < len_string_input; ++j)
		{
			matriz_output[i][j] = '\n';
		}
	}
	for (int i = 0; i < len_string_input; ++i)
	{
		matriz_output[row][col++] = string_input[i];
		if (row == 0 || row == 2)
			count_pos = count_pos*(-1);
		row = row + count_pos;
	}

	printf("\n\tMensaje cifrado: [ ");
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < len_string_input; ++j)
		{
			if (matriz_output[i][j]!='\n')
			{
				printf("%c",matriz_output[i][j]);
			}
		}
	}
	printf(" ]\n");
}

void decifrate_transposition_rail_fence(){
	char string_input[1000];
	int len_string_input = 0, row = 0, col = 0, count_pos = -1, count_position = 0;
	printf("Ingrese su mensaje a descifrar: ");
	scanf("%s",&string_input);
	len_string_input = strlen(string_input);
	char matriz_output[3][len_string_input];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < len_string_input; ++j)
		{
			matriz_output[i][j] = '\n';
		}
	}
	for (int i = 0; i < len_string_input; ++i)
	{
		matriz_output[row][col++]='*';
		if (row == 0 || row == 2)
			count_pos = count_pos * (-1);
		row = row + count_pos;
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < len_string_input; ++j)
		{
			if (matriz_output[i][j] == '*')
				matriz_output[i][j] = string_input[count_position++];
		}
	row = col = 0;
	count_pos = -1;
	}
	printf("Mensaje descifrado [ ");
	for (int i = 0; i < len_string_input; ++i)
	{
		printf("%c",matriz_output[row][col++]);
		if (row == 0 || row == 2)
			count_pos = count_pos * (-1);
		row = row + count_pos;
	}
	printf(" ]\n");
}

void cifrate_transposition_by_rows(){
	int len_string_input = 0, leng_matriz_output_j = 0;
	int count_pos = 0 , count_pos_j = 0, operation = 0;
	char string_input[500];
	if (DEBUG_)
	{
		printf("---> Tamano del contador j [ %d ]\n",leng_matriz_output_j);
	}
	printf("IGRESE MENSAJE: ");
	scanf("%s",&string_input);
	len_string_input = strlen(string_input);
	leng_matriz_output_j = calc_leng_matrix(len_string_input);
	char matriz_output[4][leng_matriz_output_j];
	if (DEBUG_)
	{  
		printf("---> Tamano del contador j [ %d ]\n",leng_matriz_output_j);
		printf("---> Tamano de input [ %d ] ---> [ %d ]\n",len_string_input,leng_matriz_output_j);
		operation = (leng_matriz_output_j*4) - len_string_input;
		printf("---> [ %d ] - [ %d ] = [ %d ]\n",(leng_matriz_output_j*4),len_string_input,operation);
	}
	for (int i = 0; i < leng_matriz_output_j; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j==0)
			{
				count_pos_j++;
			}
			printf("---> Iteration: [ %d ] Value Input[ %c ] --->> Position in matrix: [ %d ][ %d ]\n",count_pos,string_input[count_pos],j,count_pos_j-1);
			if (count_pos >= len_string_input)
			{
				matriz_output[j][count_pos_j-1] = '#';
			}else{
				matriz_output[j][count_pos_j-1] = string_input[count_pos];
			}
			count_pos++;
		}
	}
	printf("\tMatriz resultante\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < leng_matriz_output_j; j++)
		{
			printf("[ %c ]",matriz_output[i][j]);
		}
		printf("\n");
	}
	printf("\n\tMensaje cifrado final: [ ");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < leng_matriz_output_j; j++)
		{
			printf("%c",matriz_output[i][j]);
		}
	}
	printf(" ]\n\n");
	memset(string_input, 0, 50 * (sizeof string_input[0]));
	memset(matriz_output, 0, 50 * (sizeof matriz_output[0][0]));
}

void descifrate_transposition_by_rows(){
	char string_input[500], string_output[500];
	int leng_matriz_output_j = 0, len_string_input = 0, count_pos = 0, count_pos_j = 0;
	printf("Ingrese su mensaje cifrado: ");
	scanf("%s",&string_input);
	len_string_input = strlen(string_input);
	leng_matriz_output_j = find_leng_matrix(len_string_input);
	if (DEBUG_)
	{
		printf("---> Tamano de input [ %d ]\n",len_string_input);
		printf("---> Tamano de la matrix [ 4 ] [ %d ]\n",leng_matriz_output_j);
	}
	char matriz_output[4][leng_matriz_output_j];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < leng_matriz_output_j; j++)
		{
			if (j==0)
			{
				count_pos_j++;
			}
			printf("---> Iteration: [ %d ] Value Input[ %c ] --->> Position in matrix: [ %d ][ %d ]\n",count_pos,string_input[count_pos],i,j);
			matriz_output[i][j] = string_input[count_pos];
			count_pos++;
		}
	}
	printf("\tMatriz resultante\n");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < leng_matriz_output_j; j++)
		{
			printf("[ %c ]",matriz_output[i][j]);
			if (matriz_output[i][j] == '#')
			{
				matriz_output[i][j] = '\0';
			}
		}
		printf("\n");
	}
	printf("\tMatriz traspuesta\n");
	count_pos = 0;
	for (int i = 0; i < leng_matriz_output_j; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("[ %c ]",matriz_output[j][i]);
			string_output[count_pos] = matriz_output[j][i];
			count_pos++;
		}
		printf("\n");
	}
	printf("\tMensaje descifrado: [ %s ]\n",string_output);

}

int calc_leng_matrix(int len_string_input){
	int result = 0;
	for (int i = 0; i < 10000; i++)
	{
		result = 4 * i;
		if (DEBUG_)
		{
			printf("[ 4 ] * [ %d ] = [ %d ]\n",i,result);
		}
		if (len_string_input <= result)
		{
			return i;
		}
	}
}

int find_leng_matrix(int len_string_input){
	int result = 0;
	for (int i = 0; i < 1000; i++)
	{
		result = 4 * i;
		if (DEBUG_)
		{
			printf("[ 4 ] * [ %d ] = [ %d ]\n",i,result);
		}
		if (len_string_input == result)
		{
			return i;
		}
	}
}
