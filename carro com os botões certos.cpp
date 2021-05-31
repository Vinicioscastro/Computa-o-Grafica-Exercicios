#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

GLdouble pos_carro = 0;
GLdouble rot_rodas = 0;
int cam_view = 0;
float irprafrente = 0;
float girarpneu = 0;

void render_floor() {
	glColor3f(0.5, 0.8, 0.5);
	glBegin(GL_LINES);
	for (GLfloat i = -100; i <= 100; i += 10) {
		glVertex3f(i, -5, 100);
		glVertex3f(i, -5, -100);
		glVertex3f(100, -5, i);
		glVertex3f(-100, -5, i);
	}
	glEnd();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	render_floor();
	
	//ir pra frente/Trás
	//glPushMatrix();
	glTranslatef(pos_carro, 0.0, 0.0);
	//glPopMatrix();

	glPushMatrix();


	// ref
	glColor3f(0.0f, 0.0f, 1.0f);
	glutSolidSphere(1.5, 10, 8);

	//prancha do carro
	glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glScalef(40, 1, 20);
	glutSolidCube(1);



	glPopMatrix();
	
	//pneu do centro
	//glColor3f(0.25f, 0.25f, 0.25f);
	//glutSolidTorus(1.0, 3, 15, 30);
	//glPopMatrix();
	
	// pneus trás
	glPushMatrix();
	//
	glTranslated(-10, 0, -10);      // leva pra prosição e cria o pneu
	glColor3f(0.0f, 0.0f, 1.0f);	// em azul são os freios ABS
	glutSolidSphere(1.5, 10, 8);
	glColor3f(0.25f, 0.25f, 0.25f); 
	glutSolidTorus(1.0, 3, 15, 30);
	//
	glTranslated(10, 0, 10);	// translação que volta pro centro
	//
	glTranslated(-10, 0, 10);		// leva pra prosição e cria o pneu
	glColor3f(0.0f, 0.0f, 1.0f);	// em azul são os freios ABS 
	glutSolidSphere(1.5, 10, 8);
	glColor3f(0.25f, 0.25f, 0.25f);
	glutSolidTorus(1.0, 3, 15, 30);

	glPopMatrix();

	// pneu frente esquerdo
	glPushMatrix();

	// girar pneu esquerdo
	glTranslated(10, 0, -10);
	glRotatef(-rot_rodas, 0, 1, 0);
	glColor3f(0.0f, 1.0f, 0.0f);
	//glutSolidSphere(2.5, 10, 8);
	glTranslated(-10, 0, 10);
	//
	glTranslated(10, 0, -10);   
	glColor3f(0.0f, 0.0f, 1.0f);	// em azul são os freios ABS
	glutSolidSphere(1.5, 10, 8);
	glColor3f(0.25f, 0.25f, 0.25f); // leva pra prosição e cria o pneu
	glutSolidTorus(1.0, 3, 15, 30);
	glPopMatrix();
	//
	
		// pneu frente direito
	glPushMatrix();

	// girar pneu direito
	glTranslated(10, 0, 10);
	glRotatef(-rot_rodas, 0, 1, 0);
	glColor3f(0.0f, 1.0f, 0.0f);
	//glutSolidSphere(2.5, 10, 8);
	glTranslated(-10, 0, -10);
	//
	//
	glTranslated(10, 0, 10);
	glColor3f(0.0f, 0.0f, 1.0f);	// em azul são os freios ABS
	glutSolidSphere(1.5, 10, 8);
	glColor3f(0.25f, 0.25f, 0.25f); // leva pra prosição e cria o pneu
	glutSolidTorus(1.0, 3, 15, 30);
	glPopMatrix();

	//
	glutSwapBuffers();
}

void change_cam_view() {
	switch (cam_view) {
	case 0:
		gluLookAt(100, 0, 0, 0, 0, 0, 0, 1, 0);
		break;
	case 1:
		gluLookAt(0, 250, 0, 0, 0, 0, 1, 0, 0);
		break;
	case 2:
		gluLookAt(0, 0, 100, 0, 0, 0, 0, 1, 0);
		break;
	}
}

void configView() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glViewport(0, 0, 800, 600);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45, 800 / 600.0, 0.5, 500);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	change_cam_view();

}

void resize(GLsizei w, GLsizei h) {
	if (h == 0)
		h = 1;
}

void specialkeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		pos_carro += 2;
		configView();
		break;
	case GLUT_KEY_DOWN:
		pos_carro -= 2;
		configView();
		break;
	case GLUT_KEY_LEFT:
		rot_rodas -= 5;
		rot_rodas = (rot_rodas < -30) ? -30 : rot_rodas;
		configView();
		break;
	case GLUT_KEY_RIGHT:
		rot_rodas += 5;
		rot_rodas = (rot_rodas > 30) ? 30 : rot_rodas;
		configView();
		break;
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 27:
		exit(0);
		break;
	case 32:
		cam_view = (++cam_view % 3);
		pos_carro = 0;
		rot_rodas = 0;
		configView();
		break;
	default:
		break;
	}
	
	glutPostRedisplay();
}

void init(void) {
	GLfloat luzAmbiente[4] = { 0.5,0.5,0.5,1.0 };
	GLfloat luzDifusa[4] = { 0.7,0.7,0.7,1.0 };		  // "cor"
	GLfloat luzEspecular[4] = { 1.0, 1.0, 1.0, 1.0 }; // "brilho"

	GLfloat especularidade[4] = { 1.0,1.0,1.0,1.0 };
	GLint especMaterial = 60;

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);

	glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);

	glEnable(GL_DEPTH_TEST);

}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkeys);
	configView();
	init();
	glutMainLoop();
	return 0;
}
