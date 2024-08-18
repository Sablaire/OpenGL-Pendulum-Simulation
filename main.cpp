#include<windows.h>
#include <GL/glut.h>
#include<math.h>
#include<iostream>
#include <stdlib.h>
using namespace std;

void initRendering() { glEnable(GL_DEPTH_TEST); }

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0;
float _cameraangle = 30.0;
float i = 0.0, j = 0.0, k = 1.0, alpha = sin(0.3*0.1);

void drawScene()
{
	glClearColor(0.70, 0.70, 0.7, 0.7);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	//glRotatef(_cameraangle, 0.0f, 0.0f, 0.0f); 
	glTranslatef(-7, 0, -20.0f);


#pragma region Podstavka2
	glPushMatrix();
	glTranslatef(0, 3.5, 0);
	glLineWidth(10);
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex3f(2, 1.5, 0);
	glVertex3f(12, 1.5, 0);
	glEnd();

	glLineWidth(6);
	glBegin(GL_LINES);
	glVertex3f(2, 1.5, 0);
	glVertex3f(4, 2.5, 0);
	glVertex3f(4, 1.5, 0);
	glVertex3f(6, 2.5, 0);
	glVertex3f(6, 1.5, 0);
	glVertex3f(8, 2.5, 0);
	glVertex3f(8, 1.5, 0);
	glVertex3f(10, 2.5, 0);
	glVertex3f(10, 1.5, 0);
	glVertex3f(12, 2.5, 0);
	glEnd();

	glPopMatrix();
#pragma endregion
#pragma region PolozhenieVrashenie2
	glPushMatrix();
	glTranslatef(7, 20, -20.0f);
	glRotatef(90, 0, 0, -1);
	glTranslatef(30 * cos(alpha), 30 * sin(alpha), 0);
	glPushMatrix();
	//glRotatef(_cameraangle, 0.0f, 0.0f, 1.0f); 
	glScalef(0.5f, 0.5f, 0.5f);
	//glRotatef(_angle, 0.0f, 0.0f, 1.0f); 

	glLineWidth(1);
	glColor3f(1, 1, 0.8);
	glutWireSphere(6, 30, 30);

	glPopMatrix();
#pragma endregion

#pragma region Liniya2
	glPushMatrix();
	glTranslatef(7, 20, -20.0f);
	glRotatef(90, 0, 0, -1);
	glLineWidth(4);
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex3f(10, 0, 0);
	glVertex3f(30 * cos(alpha), 30 * sin(alpha), 0);
	glEnd();
	glPopMatrix();
#pragma endregion


	alpha = sin(0.3*i);
	i += 0.1*k;
	j += 0.05;
	glutSwapBuffers();
	glutPostRedisplay();

}

void update(int value)
{
	_angle += 2.0f;
	if (_angle>360.f)
	{
		_angle -= 360;
	}
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1500, 800);
	glutCreateWindow("Work #2");
	initRendering();
	glutDisplayFunc(drawScene);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);
	glutMainLoop();

	return 0;
}
