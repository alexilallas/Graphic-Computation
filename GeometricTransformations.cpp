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
	glutCreateWindow("Transformações Geométricas");              // cria a janela
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
	// Muda o sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa a matrix de transformação corrente
	//glLoadIdentity();

	// Limpa a jaela de visualização com a cor
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT);

	// Aplica uma rotação sobre a casinha que será desenhada
	glRotatef(90.0f, 0.0f, 0.0f, 1.0f);

	// Aplica uma translação sobre a casinha que será desenhada
	glTranslatef(15.0f, 0.0f, 0.0f);

	// Aplica uma escala sobre a casinha que será desenhada
	glScalef(1.5f, 1.5f, 1.0f);

	// Desenha uma casinha composta de um quadrada e um triângulo

	// Altera a cor do desenho para azul
	glColor3f(0.0f, 0.0f, 1.0f);
	// Desenha a casa
	glBegin(GL_QUADS);
		glVertex2f(-15.0f, -15.0f);
		glVertex2f(-15.0f, 5.0f);
		glVertex2f(15.0f, 5.0f);
		glVertex2f(15.0f, -15.0f);
	glEnd();
	
	// Altera a cor do desenho para branco
	glColor3f(1.0f, 1.0f, 1.0f);
	// Desenha a Porta e a janela
	glBegin(GL_QUADS);
		glVertex2f(-4.0f, -14.5f);
		glVertex2f(-4.0f, 0.0f);
		glVertex2f(4.0f, 0.0f);
		glVertex2f(4.0f, -14.5f);

		glVertex2f(7.0f, -5.0f);
		glVertex2f(7.0f, -1.0f);
		glVertex2f(13.0f, -1.0f);
		glVertex2f(13.0f, -5.0f);
	glEnd();

	// Altera a cor do desenho para azul
	glColor3f(0.0f, 0.0f, 1.0f);
	// Desenha as "linhas" da janela
	glBegin(GL_LINES);
		glVertex2f(7.0f, -3.0f);
		glVertex2f(13.0f, -3.0f);
		glVertex2f(10.0f, -1.0f);
		glVertex2f(10.0f, -5.0f);
	glEnd();

	// Altera a cor do desenho para vermelho
	glColor3f(1.0f, 0.0f, 0.0f);
	// Desenha o telhado
	glBegin(GL_TRIANGLES);
		glVertex2f(-15.0f, 5.0f);
		glVertex2f(0.0f, 17.0f);
		glVertex2f(15.0f, 5.0f);
	glEnd();
	
	// Executa os comandos OpenGL
	glFlush();
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

