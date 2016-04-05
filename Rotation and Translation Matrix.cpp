#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	float TETA;
	//translation to 0,0
	int MAT1[3][3] = { 1,0,-2, 0,1,-2, 0,0,1 };
	// rotation of x graus
	int MAT2[3][3] = {cos(TETA),-sin(TETA),0, sin(TETA), cos(TETA),0, 0,0,1};
	//translation to back
	int MAT3[3][3] = { 1,0,2, 0,1,2, 0,0,1 };
	//matrix concatened
	int mat_concat[3][3];
	//inicial points
	int pontosX1_Y1[3][1] = {3,5,1};
	//new points
	int pontosX2_Y2[3][1];
	// product of MAT1 * MAT2
	int MAT1xMAT2[3][3];
	
	// here's calculate the Concatened Matrix
	int loop = 3;
	int aux;
	for (int i = 0; i < loop; i++) {
		for (int j = 0; j < loop; j++) {
			aux = 0;
			for (int k = 0; k < loop; k++) {
				aux += MAT1[i][k] * MAT2[k][j];
				MAT1xMAT2[i][j] = aux;
			}

		}

	for (int i = 0; i < loop; i++) {
		for (int j = 0; j < loop; j++) {
			aux = 0;
			for (int k = 0; k < loop; k++) {
				aux += MAT1xMAT2[i][k] * MAT3[k][j];
				mat_concat[i][j] = aux;
			}

		}
	}

	// here's calculate the new points X2 and Y2
	for (int i = 0; i < loop; i++) {
		for (int j = 0; j < 1; j++) {
			aux = 0;
			for (int k = 0; k < 1; k++) {
				aux += mat_concat[i][k] * pontosX1_Y1[k][j];
				mat_concat[i][j] = aux;
			}

		}
	}

}
