#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include "graphics.h"
#define pi 3.1415

// prototipos das funcoes
void init(void);
void draw(void);
void keyboard(unsigned char key, int x, int y);

// funcao principal
int main(int argc, char** argv) {

	glutInit(&argc, argv);                              // inicializa o glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);           // especifica o uso de cores e buffers
	glutInitWindowSize(800, 600);                          // especifica as dimensoes da janela
	glutInitWindowPosition(283, 64);                      // especifica aonde a janela aparece na tela
	glutCreateWindow("Desenhando um Gráfico");              // cria a janela
	init();
	glutDisplayFunc(draw);                               // funcao que sera redesenhada pelo GLUT
	glutKeyboardFunc(keyboard);                             // funcoes de teclado
	glutMainLoop();                                         // mostra todas as janelas criadas
	return 0;
}

// definicao de cada funcao

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);    // cor de fundo
	gluOrtho2D(-100, 100, -100, 100);     // modo de projecao ortogonal
}


void draw(void) {
	glClear(GL_COLOR_BUFFER_BIT);               // limpa a janela
	glColor3f(1.0, 0.0, 0.0);                  // cor da linha
	glBegin(GL_POINTS);
	
	int ponto1[2] = { 0, 100 };
	int ponto2[2] = { 100, 0 };

	float x;
	float y;
	
	for (x = -100; x <= 100; x+=0.0001) {
		y = 1/(x);
		glVertex2f(x, y);
	}
			
	glEnd();
	glFlush();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 27:                                         // tecla Esc (encerra o programa)
		exit(0);
		break;
	}
}
