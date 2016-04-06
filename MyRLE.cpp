#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

FILE *entrada_cod;
FILE *saida_cod;
FILE *entrada_decod;
FILE *saida_decod;
void decodifica();
void codifica(char x[]);

int main() {
	
	char x[] = "AAAAAAAAAAABBBBBBBCCCCC";
	
	//codification funtion
	printf("\n");
	codifica(x);
			
	printf("\n");
	system("PAUSE\n\n");
	
	//decodification function
	decodifica();
	
	printf("\n");
	system("PAUSE\n");
	return 0;
}

void codifica(char x[]) {
	// archive manipulation
	entrada_cod = fopen("entrada_cod.txt", "w");
	fprintf(entrada_cod, x);
	fclose(entrada_cod);
	printf("Codificacao - Entrada: %s\n", x);
	saida_cod = fopen("saida_cod.txt", "w");
	saida_cod = fopen("saida_cod.txt", "a");
	// string manipulation
	char string1[MAX];
	char ocorrencia[MAX];
	int tamanho = strlen(x);
	for (int i = 0; i < tamanho; i++) {
		string1[i] = x[i];
	}
	string1[tamanho] = '\0';
	printf("Codificacao - Saida: ");
	// here's the codification 
	for (int i = 0; i < tamanho; i++) {
		ocorrencia[0] = x[i];
		ocorrencia[1] = '\0';
		fprintf(saida_cod, ocorrencia);
		//print the letter
		printf(ocorrencia);
		int cont = 1, j = 0;
		while (string1[i] == string1[i + 1]) {
			cont++;
			i++;
		}

		char qnt[3];
		if (cont < 10) {
			qnt[0] = cont + '0';
			qnt[1] = '\0';
		}
		else {
			
			itoa(cont,qnt,10);
		}
		
		if (cont >= 2) {
			fprintf(saida_cod, qnt);
			//print the number
			printf(qnt);
		}
		else {
			strcat(ocorrencia, "");

		}

	}

	fclose(saida_cod);
}

void decodifica() {
	char caracter[MAX];
	char caracter_aux[3];
	entrada_decod = fopen("saida_cod.txt", "r");
	saida_decod = fopen("saida_decod.txt", "w");
	saida_decod = fopen("saida_decod.txt", "a");
	fscanf(entrada_decod, "%s", &caracter);
	int tamanho = strlen(caracter);

	printf("Decodificacao - Entrada: %s\n",caracter);
	printf("Decodificacao - Saida: ");
	for (int i = 0; i < tamanho; i++) {
		if ((caracter[i] > 'A' && caracter[i] < 'Z') || (caracter[i] == 'A' || caracter[i] == 'Z')) {
			//if the next char is a digit, is write in the txt how many times it was happen
			caracter_aux[0] = caracter[i];
			caracter_aux[1] = '\0';
			//below if different of 0 , mean that is a character
			if (isdigit(caracter[i + 1]) != 0) {
				// manipulation for convert string to int
				caracter_aux[0] = caracter[i + 1];
				caracter_aux[1] = '\0';
				// case the number have 2 digits
				if (isdigit(caracter[i + 2]) != 0) {
					caracter_aux[0] = caracter[i + 1];
					caracter_aux[1] = caracter[i + 2];
					caracter_aux[2] = '\0';
				}
								
				int vezes = atoi(caracter_aux);
				// below thr caracter_aux recovery the value of the char that repeat "vezes" times								
				caracter_aux[0] = caracter[i];
				caracter_aux[1] = '\0';
				// print the char that repeat "vezes" times
				for (int j = 0; j < vezes; j++) {
					fprintf(saida_decod, caracter_aux);
					printf(caracter_aux);
				}
				i++;

			}
			else {
				fprintf(saida_decod, caracter);
				printf(caracter);
			}
		}
		
	}
	
	fclose(entrada_decod);
	fclose(saida_decod);
}