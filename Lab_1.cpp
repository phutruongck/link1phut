#include "stdafx.h"
#include <math.h>
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"


const int screenWidth = 640;
const int screenHeight = 480;
const double R = 150;
const int OPTION = 12;
const double pi = 3.14;

static GLfloat spin = 0.0;

#define STEPS 40
#define MAX_STARS 300
#define PI 3.1415926535897923846

struct GLdoublePoint {
	GLdouble x;
	GLdouble y;
};

typedef struct star {
	GLint x, y;
	GLint radius;
	GLint velocity;
	GLfloat intensity;
} STAR;
STAR sky[MAX_STARS];

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void spinDisplay(void) {
	spin = spin + 2.0;
}

void bai1() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(5.0);

	glBegin(GL_POINTS);
		glVertex3f(200.0, 120.0, 0.0);
		glVertex3f(440.0, 120.0, 0.0);
		glVertex3f(440.0, 360.0, 0.0);
		glVertex3f(200.0, 360.0, 0.0);
	glEnd();

	glFlush();
}

void bai2() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex2i(160, 80);
		glVertex2i(480, 80);
		glVertex2i(320, 400);
	glEnd();

	glFlush();
}

void bai3() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(50, 50);
		glVertex2i(250, 50);
		glVertex2i(150, 250);
	glEnd();

	glFlush();
}

void bai4() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(160, 80);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(480, 80);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(320, 400);
	glEnd();

	glFlush();
}

void bai5() {
	GLint size = 200;
	GLint x = (screenWidth - size) / 2;
	GLint y = (screenHeight - size) / 2;

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
		glVertex2i(x, y);
		glVertex2i(x + size, y);
		glVertex2i(x + size, y + size);
		glVertex2i(x, y + size);
	glEnd();

	glFlush();
}

void bai6() {
	GLint w = 400, h = 200;
	GLint x = (screenWidth - w) / 2;
	GLint y = (screenHeight - h) / 2;

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
		glVertex2i(x, y);
		glVertex2i(x + w, y);
		glVertex2i(x + w, y + h);
		glVertex2i(x, y + h);
	glEnd();

	glFlush();
}

void bai7() {
	GLint w = 400, h = 200;
	GLint x = (screenWidth - w) / 2;
	GLint y = (screenHeight - h) / 2;

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex2i(x, y);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex2i(x + w, y);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2i(x + w, y + h);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2i(x, y + h);
	glEnd();

	glFlush();
}

void bai8() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_TRIANGLES);
		glVertex2i(50, 50);
		glVertex2i(200, 50);
		glVertex2i(100, 150);

		glVertex2i(300, 100);
		glVertex2i(450, 150);
		glVertex2i(350, 250);
	glEnd();

	glFlush();
}

void bai9() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
		GLdoublePoint V1, V2, V3, V4, V5, V0;
		V0.x = screenWidth / 2;
		V0.y = screenHeight / 2;
		V1.x = V0.x;
		V1.y = V0.y + R;
		V2.x = V0.x + R*sin(2 * pi / 5);
		V2.y = V0.y + R*cos(2 * pi / 5);
		V3.x = V0.x + R*sin(pi / 5);
		V3.y = V0.y - R*cos(pi / 5);
		V4.x = V0.x - R*sin(pi / 5);
		V4.y = V0.y - R*cos(pi / 5);
		V5.x = V0.x - R*sin(2 * pi / 5);
		V5.y = V0.y + R*cos(2 * pi / 5);

		glVertex2d(V1.x, V1.y);
		glVertex2d(V2.x, V2.y);
		glVertex2d(V3.x, V3.y);
		glVertex2d(V4.x, V4.y);
		glVertex2d(V5.x, V5.y);
	glEnd();

	glFlush();
}

void glCircle(GLint x, GLint y, GLint radius) {
	GLfloat twicePi = (GLfloat) 2.0f * pi;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(x, y);
	for (int i = 0; i <= STEPS; i++) {
		glVertex2i((GLint)(x + (radius * cos(i * twicePi / STEPS)) + 0.5), (GLint)(y + (radius * sin(i * twicePi / STEPS)) + 0.5));
	}
}

void bai10() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glCircle(320, 240, 150);
	glFlush();
}

void bai11() {
	glClear(GL_COLOR_BUFFER_BIT);

	GLfloat red = 1.0f;
	GLfloat green = 1.0f;
	GLfloat blue = 1.0f;

	for (int r = 200; r > 0; r -= 30) {
		glColor3f(red, green, blue);
		glCircle(320, 240, r);
		red -= 0.1f;
		green -= 0.2f;
		blue -= 0.3f;
	}

	glFlush();
}

void glCircle_2(GLint x, GLint y, GLint radius) {
	GLfloat twicePi = (GLfloat) 2.0f * pi;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(x, y);
	for (int i = 0; i <= STEPS; i++) {
		glVertex2i((GLint)(x + (radius*cos(i*twicePi / STEPS)) + 0.5),
			(GLint)(y + (radius*sin(i*twicePi / STEPS)) + 0.5));
	}
	glEnd();
}
void skyInit() {
	for (int i = 0; i < MAX_STARS; i++) {
		sky[i].x = rand() % screenWidth;
		sky[i].y = rand() % screenHeight;
		sky[i].radius = 1 + rand() % 3;
		sky[i].intensity = sky[i].radius / 3.0f;
		sky[i].velocity = sky[i].radius * 2 + rand() % 3;
	}
}
void skyDraw() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < MAX_STARS; i++) {
		glColor3f(sky[i].intensity, sky[i].intensity, sky[i].intensity);
		glCircle_2(sky[i].x, sky[i].y, sky[i].radius);
	}
}

void update() {
	for (int i = 0; i < MAX_STARS; i++) {
		sky[i].x += sky[i].velocity;
		if (sky[i].x >= screenWidth) {
			sky[i].x = 0;
			sky[i].y = rand() % screenHeight;
			sky[i].radius = 1 + rand() % 3;
			sky[i].intensity = sky[i].radius / 3.0f;
			sky[i].velocity = sky[i].radius * 2 + rand() % 3;
		}
	}
	Sleep(50);
	glutPostRedisplay();
}

void bai12() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	skyInit();
	glPushMatrix();
	skyDraw();
	glPopMatrix();
	glutSwapBuffers();
	glutIdleFunc(update);
}

void bai13() {

}

void display()
{
	switch (OPTION)
	{
		case 1: 
			bai1();
			break;
		case 2:
			bai2();
			break;
		case 3:
			bai3();
			break;
		case 4: 
			bai4();
			break;
		case 5:
			bai5();
			break;
		case 6:
			bai6();
			break;
		case 7:
			bai7();
			break;
		case 8:
			bai8();
			break;
		case 9: 
			bai9();
			break;
		case 10:
			bai10();
			break;
		case 11:
			bai11();
			break;
		case 12:
			bai12();
			break;
		case 13:
			bai13();
			break;
		default:
		break;
	}
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}


