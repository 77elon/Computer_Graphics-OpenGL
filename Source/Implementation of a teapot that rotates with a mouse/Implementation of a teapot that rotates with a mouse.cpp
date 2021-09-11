#include <gl\freeglut.h>

#define INIT_WIN_X 600
#define INIT_WIN_Y 600

GLint Moved_X, Moved_Y;
GLint Init_X, Init_Y;
GLfloat WIN_X = 0, WIN_Y = 0;
GLfloat Tan_Result_X = 0, Tan_Result_Y = 0;

void MyDisplay()
{
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 0.5, 0.0, 0.0, 0.0, -1.0, 0.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
	glRotatef(Tan_Result_X, 0.0, 1.0, 0.0);
	glRotatef(Tan_Result_Y, 1.0, 0.0, 0.0);
	glutSolidTeapot(0.5);
	glutSwapBuffers();
}

void MyReshape(int NewWidth, int NewHeight)
{
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)INIT_WIN_X;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)INIT_WIN_Y;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
	WIN_X = WidthFactor * INIT_WIN_X;
	WIN_Y = HeightFactor * INIT_WIN_Y;
}

void MyMouse(GLint mouse, GLint state, GLint x, GLint y)
{
	if (mouse == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		Init_X = x;
		Init_Y = y;
	}

}
void MyMotion(GLint x, GLint y)
{
	Moved_X = x;
	Moved_Y = y;

	int tempx = (Moved_X - Init_X);
	int tempy = (Moved_Y - Init_Y);

	Tan_Result_X = tempx / WIN_X * 180;
	Tan_Result_Y = tempy / WIN_Y * 180;
	glutPostRedisplay();
}



int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(INIT_WIN_X, INIT_WIN_Y);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Using TrackBall Rotate to TeaPot");
	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMouseFunc(MyMouse);
	glutMotionFunc(MyMotion);

	glutMainLoop();
	return 0;
}