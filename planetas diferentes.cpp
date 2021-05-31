#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

static int ano = 0, dia = 0;
float rot = 0;
float rot1 = 0;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glRotatef(rot1, 0, 0, 1);

    // //Referencia
    glPushMatrix();
    glRotatef(rot, 1, 0, 0);
    glTranslatef(2, 0, 0);
    glColor3f(0.5, 0.5, 0.0);
    glutWireSphere(0.25, 20, 16);

    glPopMatrix();

    glPushMatrix();

    //
    
    
    
    glColor3f(0.5, 0.5, 0.0);
    glutWireSphere(1.0, 20, 16);

    glColor3f(0.0, 0.0, 0.5);
    glutWireSphere(0.2, 10, 8);
  
    glPopMatrix();
   
  
  

      //  glColor3f(1.0f, 0.0f, 0.0f);
       // glutSolidSphere(0.2, 10, 8);

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, w / (h * 1.0), 1.0, 20.0);
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'a':
        dia = (dia + 10) % 360;
        glutPostRedisplay();
        break;
    case 'd':
        dia = (dia - 10) % 360;
        glutPostRedisplay();
        break;
    case 's':
        ano = (ano + 5) % 360;
        glutPostRedisplay();
        break;
    case 'w':
        ano = (ano - 5) % 360;
        glutPostRedisplay();
    case 'k':
        rot+=10;
        glutPostRedisplay();
        break;
    case 'l':
        rot += 10;
        glutPostRedisplay();
        break;
    case 'i':
        rot1 += 1;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
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