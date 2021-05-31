#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

int ombro = 0, cotovelo = 0;
float rotZ1 = 0;
float rotZ = 0;


void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    // ref
    
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidSphere(0.2, 10, 8);

    glRotatef(rotZ1, 0, 0, 1);

    glPushMatrix();
    glColor3f(0.5, 0.0, 0.0);
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();


    // //Referencia
   
    glPushMatrix();
    glTranslatef(1, 0, 0);
   
    glRotatef(rotZ, 0, 0, 1);
    
    glPushMatrix();
    glTranslatef(1.0, 0.0,0.0);
    glColor3f(0.0, 0.0, 0.5);
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();



    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(75.0, w / (h * 1.0), 1.0, 20.0);
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'a':
        ombro = (ombro + 5) % 360;
        glutPostRedisplay();
        break;
    case 'd':
        ombro = (ombro - 5) % 360;
        glutPostRedisplay();
        break;
    case 's':
        cotovelo = (cotovelo + 5) % 360;
        glutPostRedisplay();
        break;
    case 'w':
        cotovelo = (cotovelo - 5) % 360;
        glutPostRedisplay();
        break;
    case 'k':
        rotZ +=15;
        glutPostRedisplay();
        break;
    case 'l':
        rotZ -= 15;
        glutPostRedisplay();
        break;
    case 'i':
        rotZ1 += 15;
        glutPostRedisplay();
        break;
    case 'o':
        rotZ1 -= 15;
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }

    if (rotZ > 50) rotZ = 50;
    if (rotZ < -50) rotZ = -50;

    if (rotZ1 > 45) rotZ1 = -45;
    if (rotZ1 < -45) rotZ1 = 45;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glClearColor(1, 1, 1, 1);
    glutMainLoop();
    return 0;
}