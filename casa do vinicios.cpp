#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>

void display(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //Define a cor de fundo da cena (cor usada para limpar o buffer de cor)
	glClear(GL_COLOR_BUFFER_BIT);//Inicializa o buffer de cores antes de ele ser alterado

	glMatrixMode(GL_MODELVIEW); //Informa que as operações seguintes serão executadas na matrix modelview
	glLoadIdentity(); //Carrega a matriz identidade


	// QUADRADO
		glPointSize(7); //Define quantos pixels representarão um vértice na tela
		glLineWidth(5);
		glBegin(GL_QUADS); //Indica que serão desenhados somente pontos

		glColor3f(1.0f, 0.0f, 0.0f); //Define a cor do desenho em formato RGB
		glVertex2f(-0.7, -0.2); //Especifica pontos no espaço bidimensional (pixels)

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.3, -0.2);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.3, 0.3);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.7, 0.3);


		glEnd();//Encerra a criação de pontos

		// RETANGULO DA PORTA
		glPointSize(7); //Define quantos pixels representarão um vértice na tela
		glLineWidth(5);
		glBegin(GL_QUADS); //Indica que serão desenhados somente pontos

		glColor3f(1, 0.7961, 0.8588);
		glVertex2f(-0.6, -0.2);

		glColor3f(1, 0.7961, 0.8588);
		glVertex2f(-0.45, -0.2);

		glColor3f(1, 0.7961, 0.8588);
		glVertex2f(-0.45, 0.1);

		glColor3f(1, 0.7961, 0.8588);
		glVertex2f(-0.6, 0.1);

		glEnd();//Encerra a criação de pontos

		// RETANGULO TRINCO DA PORTA
		glPointSize(7); //Define quantos pixels representarão um vértice na tela
		glLineWidth(5);
		glBegin(GL_POINTS); //Indica que serão desenhados somente pontos

		glColor3f(0, 0, 2.55);
		glVertex2f(-0.58, -0.05);

		glEnd();//Encerra a criação de pontos

		// RETANGULO DA SOMBRA DA PORTA
		glPointSize(7); //Define quantos pixels representarão um vértice na tela
		glLineWidth(5);
		glBegin(GL_QUADS); //Indica que serão desenhados somente pontos

		glColor3f(0, 0, 2.55);
		glVertex2f(-0.6, -0.2);

		glColor3f(0, 0, 2.55);
		glVertex2f(-0.45, -0.2);

		glColor3f(0, 0, 2.55);
		glVertex2f(-0.55, -0.4);

		glColor3f(0, 0, 2.55);
		glVertex2f(-0.7, -0.4);

		glEnd();//Encerra a criação de pontos


		//TRIANGOLO


		glPointSize(7); //Define quantos pixels representarão um vértice na tela
		glLineWidth(5);
		glBegin(GL_TRIANGLES); //Indica que serão desenhados somente pontos

		
		glColor3f(0, 1.28, 0);
		glVertex2f(-0.5, 0.6);

		glColor3f(0, 1.28, 0);
		glVertex2f(-0.3, 0.3);

		glColor3f(0, 1.28, 0);
		glVertex2f(-0.7, 0.3);


		glEnd();//Encerra a criação de pontos

		// RETANGULO
		glPointSize(7); //Define quantos pixels representarão um vértice na tela
		glLineWidth(5);
		glBegin(GL_QUADS); //Indica que serão desenhados somente pontos

		glColor3f(0, 1.28, 0);
		glVertex2f(-0.3, -0.2);

		glColor3f(0, 1.28, 0);
		glVertex2f(-0.3, 0.3);

		glColor3f(0, 1.28, 0);
		glVertex2f(0.4, 0.3);

		glColor3f(0, 1.28, 0);
		glVertex2f(0.4, -0.2);

		glEnd();//Encerra a criação de pontos


		// RETANGULO da janela
		glPointSize(7); //Define quantos pixels representarão um vértice na tela
		glLineWidth(5);
		glBegin(GL_QUADS); //Indica que serão desenhados somente pontos

		glColor3f(0, 0, 2.55);
		glVertex2f(-0.1, 0);

		glColor3f(0, 0, 2.55);
		glVertex2f(0.18, 0);

		glColor3f(0, 0, 2.55);
		glVertex2f(0.18, 0.2);

		glColor3f(0, 0, 2.55);
		glVertex2f(-0.1, 0.2);

		glEnd();//Encerra a criação de pontos

		// LINHAS DA JANELA
		glPointSize(7); //Define quantos pixels representarão um vértice na tela
		glLineWidth(5);
		glBegin(GL_LINES); //Indica que serão desenhados somente pontos

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.04, 0);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.04, 0.2);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(0.18, 0.1);

		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2f(-0.1, 0.1);

		glEnd();//Encerra a criação de pontos

			// RETANGULO DO TETO
		glPointSize(7); //Define quantos pixels representarão um vértice na tela
		glLineWidth(5);
		glBegin(GL_QUADS); //Indica que serão desenhados somente pontos


		glColor3f(0, 0, 2.55);
		glVertex2f(-0.3, 0.3);

		glColor3f(0, 0, 2.55);
		glVertex2f(0.4, 0.3);

		glColor3f(0, 0, 2.55);
		glVertex2f(0.3, 0.6);

		glColor3f(0, 0, 2.55);
		glVertex2f(-0.5, 0.6);



		glEnd();//Encerra a criação de pontos



	glFlush(); //Informa que as operações devem ser processadas imediatamente e exibidas na tela
}


/*Recebe um o comprimento (width) e altura (height) da janela em pixels.*/
void resize(GLsizei w, GLsizei h) {
	if (h == 0)
		h = 1;

	printf("Tam. janela: (%i,%i)\n", w, h);
}

/*Recebe um código para cada tecla (ASCII) e as coordenadas do mouse.*/
void keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 27:
		exit(0);
		break;
	case 32:
		glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //Define a cor de fundo da cena (cor usada para limpar o buffer de cor)
		break;
	default:
		printf("Código tecla: %i. Mouse em (%i,%i)\n", key, x, y);
		break;
	}
	glutPostRedisplay(); //Informa que a janela atual deve ser redesenhada
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv); //Inicializa a OpenGL
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Configura os modos de exibição (mais detalhes no futuro)
	glutInitWindowSize(800,500); //Define o tamanho da janela em pixels
	glutInitWindowPosition(0, 0); //Define a posição inicial da janela
	glutCreateWindow("Primeiro Exemplo"); //Cria a janela especificando seu título
	glutDisplayFunc(display); //Especifica a função de rendering (exibe a cena no loop)
	glutReshapeFunc(resize); //Especifica função a ser executada quando a janela é redimensionada
	glutKeyboardFunc(keyboard); //Especifica função a ser executada quando uma tecla é pressionada

	glutMainLoop(); //Executa o loop de renderização
	return 0;
}