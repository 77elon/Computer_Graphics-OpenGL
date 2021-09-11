#include <freeglut.h>

#define INIT_WIN_X 600
#define INIT_WIN_Y 600



GLfloat Inner_radius = 0.2f;
GLfloat Outer_radius = 0.4f;
GLfloat Scale_factor = 0.001f;
GLint Donut_sides = 12;
GLint Donut_rings = 24;

void dec_TimeMotion(int value);

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glutWireTorus(Inner_radius, Outer_radius, Donut_sides, Donut_rings);
	glFlush();
}
void MyReshape(int NewWidth, int NewHeight)
{
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)INIT_WIN_X;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)INIT_WIN_Y;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
	glRotated(70, 0.3, 0.3, 0.3);

}

void add_TimeMotion(int value)
{

	Outer_radius += (GLfloat)Scale_factor * value;
	glutPostRedisplay();
	glFlush();

	glutTimerFunc(1000, dec_TimeMotion, 100);

}
void dec_TimeMotion(int value)
{
	Outer_radius -= (GLfloat)Scale_factor * value;
	glutPostRedisplay();
	glFlush();

	glutTimerFunc(1000, add_TimeMotion, 100);

}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(INIT_WIN_X, INIT_WIN_Y);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("HeartBeat Donut");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutTimerFunc(1000, add_TimeMotion, 100);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
}