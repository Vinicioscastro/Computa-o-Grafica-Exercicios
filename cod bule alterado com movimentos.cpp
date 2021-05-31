#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

GLfloat angle = 45;
GLfloat fAspect = 0;
GLfloat posX, posY, posZ = 0;

void display(void) {
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0f, 0.0f, 1.0f);

	glutWireTeapot(50.0f);

	glutSwapBuffers();
}

void configProjection(void) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(angle, fAspect, 0.5, 500);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(posX, posY, posZ, 0, 0, 0, 0, 1, 0);
}

void resize(GLsizei w, GLsizei h) {
	if (h == 0)
		h = 1;

	fAspect = (GLfloat)w / (GLfloat)h;

	configProjection();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10)
				angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130)
				angle += 5;
		}
	configProjection();
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 27:
		exit(0);
		break;
	case 'w':
		posZ += 50;
		break;
	case 's':
		posZ -= 50;
		break;
	case 'a':
		posX += 10;
		break;
	case 'd':
		posX -= 10;
		break;
	default:
		break;
	}

	configProjection();
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Perspectiva");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}