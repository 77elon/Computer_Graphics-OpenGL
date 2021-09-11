#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <iostream> //exit(0);
#else
#include <GL/freeglut.h>
#endif


int Width = 800, Height = 800;

int l1 = 600, l2 = 500;

int rot1 = 20, rot2 = 40;

void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, Width / Height, 0.01, 20);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void MyDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    glPushMatrix();
    glColor3f(1.0f, 0.2f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.2f, 0.1f);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(0.2f, -0.1f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.0f, 0.2f, 0.7f);
    glTranslatef(0.0f, 0.2f, 0.0f);
    glPushMatrix();
    glScalef(0.5f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.1f, 0.0f);
    glRotatef((GLfloat)rot1, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.0f, -0.1f, 0.0f);

    glPushMatrix();
    glTranslatef((float)l1 * 0.001f, 0.0f, 0.0f);
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.1f, 0.0f);
    glutSolidSphere(0.06f, 30, 30);
    glPopMatrix();

    glColor3f(0.0f, 0.2f, 0.7f);
    glTranslatef(0.0f, 0.1f, 0.0f);
    glRotatef((GLfloat)rot2, 0.0f, 0.0f, 1.0f);
    glTranslatef(0.6f, 0.0f, 0.0f);

    glPushMatrix();
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-0.1f, 0.0f, 0.0f);
    glutSolidSphere(0.06f, 30, 30);
    glPopMatrix();

    glColor3f(0.0f, 0.4f, 0.3f);
    glRotatef(270.0, 0.0f, 0.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(0.03f, 0.1f);
    glVertex2f(0.03f, 0.03f);
    glVertex2f(-0.03f, 0.03f);
    glVertex2f(-0.03f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.35f, 0.0f, 0.0f);

    glPushMatrix();
    glColor3f(0.0f, 0.5f, 0.2f);
    glScalef((float)l2 * 0.005f, 0.5f, 5.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glEnd();
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(0.0f, 0.1f, 0.0f);
    glutSolidSphere(0.06f, 30, 30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.3f, 0.1f, 0.0f);
    glColor3f(0.0f, 0.8f, 0.2f);
    glScalef((float)l1 * 0.005f, 0.5f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glEnd();
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void MyReshape(int NewWidth, int NewHeight)
{
    Width = NewWidth;
    Height = NewHeight;
}

void MyKeyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q':
        if (rot1 >= 210)
        {
            break;
        }
        rot1 = (rot1 + 3) % 360;
        glutPostRedisplay();
        break;
    case 'a':
        if (rot1 <= -34)
        {
            break;
        }
        rot1 = (rot1 - 3) % 360;
        glutPostRedisplay();
        break;
    case 'w':
        if (rot2 >= 120)
        {
            break;
        }
        rot2 = (rot2 + 3) % 360;
        glutPostRedisplay();
        break;
    case 's':
        if (rot2 <= -120)
        {
            break;
        }
        rot2 = (rot2 - 3) % 360;
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}


int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(Width, Height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Creating Simple Robot Arm");
    init();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutKeyboardFunc(MyKeyboard);
    glutMainLoop();
    return 0;
}
