#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define DEBUG_ 1

int calc_leng_matrix(int len_string_input);
void cifrate_transposition_by_rows();
void descifrate_transposition_by_rows();

int main()
{
	int option_menu = 0;
	char option_menu_intern = ' ';
	do
	{
		printf("<<=========================TIPOS DE CIFRADO POR TRANSPOSICION =========================>>\n");
		printf("<<========================1.- TRANSPOSICION POR FILAS =================================>>\n");
		printf("<<========================2.- TRANSPOSICION POR ======================>>\n");
		printf("<<========================3.- TRANSPOSICION POR ====================>>\n");
		printf("<<========================4.- Salir=================================>>\n");
		printf("--->> Ingrese su opcion: ");
		scanf("%d", &option_menu);
		if (option_menu >= 1 && option_menu <= 4)
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
					//descifrate_transposition_by_rows();
				}
				break;
			}
			case 2:{
				printf("<<=======================  CIFRADO POLYBIUS =======================>>\n");
				printf("<<----------------------- a.- CIFRAR    ------------------------->>\n");
				printf("<<----------------------- b.- DESCIFRAR ------------------------->>\n");
				printf("--->> Ingrese su opcion: ");
				scanf("%s",&option_menu_intern);
				if (option_menu_intern == 'a')
				{
					printf("CIFRAR\n");
					
					
				}else if (option_menu_intern == 'b')
				{
					printf("DESCIFRAR\n");
					
					
				}
				break;
			}
			case 3:{
				printf("<<=====================  CIFRADO TRITHEMIUS =======================>>\n");
				printf("<<----------------------- a.- CIFRAR    ------------------------->>\n");
				printf("<<----------------------- b.- DESCIFRAR ------------------------->>\n");
				printf("--->> Ingrese su opcion: ");
				scanf("%s",&option_menu_intern);
				if (option_menu_intern == 'a')
				{
					printf("CIFRAR\n");
					
					
				}else if (option_menu_intern == 'b')
				{
					printf("DESCIFRAR\n");
					
					
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
