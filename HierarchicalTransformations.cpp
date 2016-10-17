#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

// Declaração de variáveis globais
GLfloat tx = 0;
GLfloat ang1 = -15, ang2 = -45, ang3 = -15;
GLfloat win = 25;

// Função para desenhar um "braço" do objeto
void DesenhaBraco()
{
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glVertex2f(1.0, 4.6);
	glVertex2f(1.0, -0.8);
	glVertex2f(-1.0, -0.8);
	glVertex2f(-1.0, 4.6);
	glEnd();
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2i(0, 0);
	glEnd();
}

// Função para desenhar a base do objeto           
void DesenhaBase()
{
	glLineWidth(2);
	glBegin(GL_LINE_LOOP);
	glVertex2f(1.0, 4.6);
	glVertex2f(1.0, -2.7);
	glVertex2f(-1.0, -2.7);
	glVertex2f(-1.0, 4.6);
	glEnd();
}

// Função callback de redesenho da janela de visualização
void Desenha(void)
{
	// Muda para o sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa a matriz de transformação corrente
	glLoadIdentity();

	// Limpa a janela de visualização com a cor  
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT);

	// Desenha o "chão"
	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(4);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-win, -3.9);
	glVertex2f(win, -3.9);
	glEnd();

	// Desenha os objetos e modela com transformações hierárquicas

	glPushMatrix();

	glTranslatef(tx, 0.0f, 0.0f);

	glPushMatrix();

	glScalef(1.4f, 1.4f, 1.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	DesenhaBase();

	glPopMatrix();

	glTranslatef(0.0f, 5.0f, 0.0f);
	glRotatef(ang1, 0.0f, 0.0f, 1.0f);
	glScalef(1.4f, 1.4f, 1.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	DesenhaBraco();

	glTranslatef(0.4f, 3.6f, 0.0f);
	glRotatef(ang2, 0.0f, 0.0f, 1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	DesenhaBraco();

	glTranslatef(0.0f, 4.25f, 0.0f);
	glRotatef(ang3, 0.0f, 0.0f, 1.0f);
	glScalef(0.4f, 0.7f, 0.0f);
	glColor3f(1.0f, 0.0f, 1.0f);
	DesenhaBraco();

	glPopMatrix();

	// Executa os comandos OpenGL 
	glFlush();
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	GLsizei largura, altura;

	// Evita a divisao por zero
	if (h == 0) h = 1;

	// Atualiza as variáveis
	largura = w;
	altura = h;

	// Especifica as dimensões da Viewport
	glViewport(0, 0, largura, altura);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (esquerda, direita, inferior, 
	// superior) mantendo a proporção com a janela de visualização
	if (largura <= altura)
	{
		gluOrtho2D(-25.0f, 25.0f, -25.0f*altura / largura, 25.0f*altura / largura);
		win = 25.0f;
	}
	else
	{
		gluOrtho2D(-25.0f*largura / altura, 25.0f*largura / altura, -25.0f, 25.0f);
		win = 25.0f*largura / altura;
	}
}

// Função callback chamada para gerenciar eventos de teclas especiais(F1,PgDn,...)
void TeclasEspeciais(int key, int x, int y)
{
	// Move a base
	if (key == GLUT_KEY_LEFT)
	{
		tx -= 2;
		if (tx < -win)
			tx = -win;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		tx += 2;
		if (tx > win)
			tx = win;
	}

	// Rotaciona braco1
	if (key == GLUT_KEY_END)
		ang1 -= 5;
	if (key == GLUT_KEY_HOME)
		ang1 += 5;

	// Rotaciona braco2
	if (key == GLUT_KEY_PAGE_DOWN)
		ang2 -= 5;
	if (key == GLUT_KEY_PAGE_UP)
		ang2 += 5;

	// Rotaciona braco3
	if (key == GLUT_KEY_DOWN)
		ang3 -= 5;
	if (key == GLUT_KEY_UP)
		ang3 += 5;

	glutPostRedisplay();
}

// Função callback chamada para gerenciar eventos de teclas
void Teclado(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

// Função responsável por inicializar parâmetros e variáveis
void Inicializa(void)
{
	// Define a cor de fundo da janela de visualização como branca
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	
}

// Programa Principal 
int main(int argc, char** argv) {

	glutInit(&argc, argv);                              // inicializa o glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);           // especifica o uso de cores e buffers
	glutInitWindowSize(800, 600);                          // especifica as dimensoes da janela
	glutInitWindowPosition(283, 64);                      // especifica aonde a janela aparece na tela
	glutCreateWindow("Transformações Hierárquicas");              // cria a janela
	
	glutDisplayFunc(Desenha);                               // funcao que sera redesenhada pelo GLUT
	// Registra a função callback de redimensionamento da janela de visualização
	glutReshapeFunc(AlteraTamanhoJanela);

	glutSpecialFunc(TeclasEspeciais);
	// Registra a função callback para tratamento das teclas ASCII
	glutKeyboardFunc(Teclado);

	Inicializa();

	glutMainLoop();                                         // mostra todas as janelas criadas
	return 0;
}
