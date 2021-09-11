#include <gl\freeglut.h>
#define _USE_MATH_DEFINES
#include <math.h>

#define FPS 240

int Init_X = 900, Init_Y = 900;

GLfloat xpos = 0, ypos = 5, zpos = 0, xrot = 0, yrot = 0;

int Moved_X = 0, Moved_Y = 0;

bool Walk_Through = false;

void Init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutWarpPointer(Init_X / 2, Init_Y / 2);
}

void ypos_movement() 
{
	if (Walk_Through == true)
	{
		if (ypos < 10)
		{
			ypos += 3;
		}
	}
	else if (Walk_Through == false)
	{
		ypos = 5;
	}
}

void Draw_Cube()
{
	glPushAttrib(GL_CURRENT_BIT);

	glColor3f(1.0, 0.0, 1.0);

	GLfloat num1 = 0, num2 = 0;
	num1 = 49.0;
	num2 = 49.0;

	glPushMatrix();
		glTranslatef(0.0, -4.0, 0.0);
		glutSolidCube(2.0);
		glTranslatef(num1, 0.0, 0.0);
		glutSolidCube(2.0);
		glTranslatef(0.0, 0.0, num2);
		glutSolidCube(2.0);
		glTranslatef(0.0, 0.0, -2 * num2);
		glutSolidCube(2.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, -4.0, num2);
		glutSolidCube(2.0);
		glTranslatef(0.0, 0.0, -2 * num2);
		glutSolidCube(2.0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-num1, -4.0, 0.0);
		glutSolidCube(2.0);
		glTranslatef(0.0, 0.0, num2);
		glutSolidCube(2.0);
		glTranslatef(0.0, 0.0, -2 * num2);
		glutSolidCube(2.0);
	glPopMatrix();

	glPopAttrib();
}

void Texture_Chess() // blinking problem...
{
	glEnable(GL_TEXTURE_2D);

	unsigned char Texture_Matrix[2][2][4] =
	{
		0,0,0,255,
		255,255,255,255,

		255,255,255,255,
		0,0,0,255
	};

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, Texture_Matrix);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);  glVertex3f(-50.0, -5.0, -50.0);
		glTexCoord2f(25.0, 0.0);  glVertex3f(50.0, -5.0, -50.0);
		glTexCoord2f(25.0, 25.0);  glVertex3f(50.0, -5.0, 50.0);
		glTexCoord2f(0.0, 25.0);  glVertex3f(-50.0, -5.0, 50.0);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}


void MyDisplay()
{
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(30, Init_X/Init_Y, 10.0, 200.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, -10.0, 0.0, 0.0, 0.0, -1.0, 0.0, 1.0, 0.0); //Initialize Viewpoint

	glRotatef(xrot, 1.0, 0.0, 0.0);
	glRotatef(yrot, 0.0, 1.0, 0.0);

	glTranslatef(-xpos, -ypos, -zpos);

	glPushMatrix();
		Texture_Chess();
		Draw_Cube();
	glPopMatrix();

	ypos_movement();

	glDisable(GL_DEPTH_TEST);

	glutSwapBuffers();
}

void MyReshape(int w, int h)
{
	Init_X = w;
	Init_Y = h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30, w / h, 10.0, 200.0);

	glMatrixMode(GL_MODELVIEW);
}

void MyKeyboard(unsigned char key, int x, int y)
{
	if (key == 'w')
	{
		double Rotated_X, Rotated_Y;
		Rotated_Y = (yrot / 180 * M_PI);
		Rotated_X = (xrot / 180 * M_PI);
		xpos += GLfloat(sin(Rotated_Y));
		zpos -= GLfloat(cos(Rotated_Y));
		Walk_Through = true;
	}

	if (key == 'a')
	{
		double Rotated_Y;
		Rotated_Y = (yrot / 180 * M_PI);
		xpos -= GLfloat(cos(Rotated_Y));
		zpos -= GLfloat(sin(Rotated_Y));
		Walk_Through = true;
	}

	if (key == 's')
	{
		double Rotated_X, Rotated_Y;
		Rotated_Y = (yrot / 180 * M_PI);
		Rotated_X = (xrot / 180 * M_PI);
		xpos -= GLfloat(sin(Rotated_Y));
		zpos += GLfloat(cos(Rotated_Y));
		Walk_Through = true;
	}

	if (key == 'd')
	{
		double Rotated_Y;
		Rotated_Y = (yrot / 180 * M_PI);
		xpos += GLfloat(cos(Rotated_Y));
		zpos += GLfloat(sin(Rotated_Y));
		Walk_Through = true;
	}

	if (key == 27)
	{
		exit(0);
	}

}

void MyMotion(int x, int y)
{
	int Movement_X = x - Moved_X;
	int Movement_Y = y - Moved_Y;
	Moved_X = x;
	Moved_Y = y;
	xrot += (GLfloat)Movement_Y / (Init_X / 180);
	yrot += (GLfloat)Movement_X / (Init_Y / 180); 
}


void Timer(int) //flickering fix
{
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, Timer, 0);
}

void MyUpKeyboard(unsigned char key, int x, int y) //walk-through
{
	if (key == 'w' || key == 'a' || key == 's' || key == 'd')
	{
		Walk_Through = false;
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(1, 1);
	glutInitWindowSize(Init_X, Init_Y);
	glutCreateWindow("Create Moving VCS");
	Init();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);
	glutKeyboardUpFunc(MyUpKeyboard);
	glutPassiveMotionFunc(MyMotion);
	glutTimerFunc(0, Timer, 0);
	glutMainLoop();
	return 0;
}