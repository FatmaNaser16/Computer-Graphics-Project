#include <GL/glut.h>
#include <Math.h>
#include<iostream>
using namespace std;
float movex = 0.0;
float movey = 0.0;
float dis = 0;
GLfloat angle = 45.0;
int refreshmill = 1;
float dx = 0.425;
float wood1 = 0.0;
float wood2 = 0.0;
float wood3 = 0.0;
bool alive = true;
float woodSpeed = 0.00025;

typedef struct tra {
	float x[3];
	float y[3];
}tra;

tra bbb;

void RenderStringLose(float x, float y, void* font)
{
	char gameover[10] = { 'G','A','M','E',' ','O','V','E','R','!' };
	int xa = x;
	glColor3f(1, 0, 0);
	glRasterPos2f(xa, y);
	for (int i = 0; i < 10; i++) {
		glutBitmapCharacter(font, gameover[i]);
		xa += 0.1;
	}
}

float RandomNumber(float x, float y) {
	return((float)rand() / RAND_MAX * (y - x) + x);
}

void keyboard(unsigned char key, int x, int y) {
	if (key == 'd') {
		movex += 0.2;
		glutPostRedisplay();
	}
	if (key == 'a') {
		movex -= 0.2;
		glutPostRedisplay();
	}
	if (key == 'w') {
		movey += 0.4;
		glutPostRedisplay();
	}
	if (key == 's') {
		movey -= 0.4;
		glutPostRedisplay();
	}
}

void timer(int value) {
	glutPostRedisplay();
	glutTimerFunc(refreshmill, timer, 0);
}

void draw_circle(float r, int i, int degree, float x, float y, float red, float green, float blue) {

	glColor3f(red, green, blue);
	for (i; i < degree; i++) {
		float theta = i * 3.14 / 180;
		glVertex2f(r * cos(theta) + x, r * sin(theta) + y);

	}

}

void circle(double radius, double x, double y) {
	double angle;
	for (int i = 0; i <= 360; i++) {
		angle = i * 3.14 / 180;
		glVertex2d(x + radius * cos(angle), y + radius * sin(angle));
	}
}

void upperSemiCircle(double radius, double x, double y) {
	double angle;
	for (int i = 0; i <= 180; i++) {
		angle = i * 3.14 / 180;
		glVertex2d(x + radius * cos(angle), y + radius * sin(angle));
	}
}

void lowerSemiCircle(double radius, double x, double y) {
	double angle;
	for (int i = 180; i <= 360; i++) {
		angle = i * 3.14 / 180;
		glVertex2d(x + radius * cos(angle), y + radius * sin(angle));
	}
}

void ground() {
	glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
	glColor3f(0.0f, 0.5f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-1, -0.5);
	glVertex2f(1, -0.5);
	glVertex2f(1, -7);
	glVertex2f(-1, -7);
	glEnd();
}

void ground2() {
	glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
	glColor3f(0.0f, 0.5f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-1, -0.1);
	glVertex2f(1, -0.1);
	glVertex2f(1, -0.5);
	glVertex2f(-1, -0.5);
	glEnd();
}

void sea() {
	glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
	glColor3f(0.0f, 0.5f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-1, 0.3);
	glVertex2f(1, 0.3);
	glVertex2f(1, -0.1);
	glVertex2f(-1, -0.1);
	glEnd();
}

void D() {
	//K to N to M to L
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-0.2 + dis, 0.3);
	glVertex2f(-0.2 + dis, -0.1);
	glVertex2f(0.2 + dis, -0.1);
	glVertex2f(0.2 + dis, 0.3);
	glEnd();

	//K1 to L1 to M1 to N1
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-0.14 + dis, 0.05);
	glVertex2f(-0.14 + dis, -0.05);
	glVertex2f(-0.17 + dis, -0.05);
	glVertex2f(-0.17 + dis, -0.05);
	glVertex2f(-0.17 + dis, 0.05);
	glVertex2f(-0.17 + dis, -0.05);
	glEnd();

	//R1 to O1 to P1 to Q1
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(0.14 + dis, 0.05);
	glVertex2f(0.14 + dis, -0.05);
	glVertex2f(0.17 + dis, -0.05);
	glVertex2f(0.17 + dis, -0.05);
	glVertex2f(0.17 + dis, 0.05);
	glVertex2f(0.17 + dis, -0.05);
	glEnd();

	//U to N to S0 to T
	glColor3f(0, 1, 0);//left bottom square
	glBegin(GL_POLYGON);
	glVertex2f(-0.2 + dis, 0);
	glVertex2f(-0.2 + dis, -0.1);
	glVertex2f(-0.25 + dis, -0.1);
	glVertex2f(-0.25 + dis, 0);
	glEnd();

	//R to Q to M to O
	glColor3f(0, 1, 0);//right bottom square
	glBegin(GL_POLYGON);
	glVertex2f(0.2 + dis, 0);
	glVertex2f(0.2 + dis, -0.1);
	glVertex2f(0.25 + dis, -0.1);
	glVertex2f(0.25 + dis, 0);
	glEnd();

	//left eye F
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	circle(0.05, -0.1 + dis, 0.2);
	glEnd();

	//left eye G
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	circle(0.02, -0.1 + dis, 0.2);
	glEnd();

	//right eye I
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	circle(0.05, 0.1 + dis, 0.2);
	glEnd();

	//right eye J
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	circle(0.02, 0.1 + dis, 0.2);
	glEnd();

	//left eyebrow
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	upperSemiCircle(0.1, -0.1 + dis, 0.3);
	glEnd();

	//right eyebrow
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	upperSemiCircle(0.1, 0.1 + dis, 0.3);
	glEnd();

	//mouth
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_STRIP);
	lowerSemiCircle(0.1, 0 + dis, 0.1);
	glEnd();
}

void woods() {
	glColor3f(0.1f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(0.4 + wood1, -0.1);
	glVertex2f(0.9 + wood1, -0.1);
	glVertex2f(0.9 + wood1, -0.5);
	glVertex2f(0.4 + wood1, -0.5);
	glEnd();

	glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
	glColor3f(0.1f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.25 + wood2, -0.1);
	glVertex2f(0.25 + wood2, -0.1);
	glVertex2f(0.25 + wood2, -0.5);
	glVertex2f(-0.25 + wood2, -0.5);
	glEnd();

	glClearColor(0.0f, 0.5f, 0.0f, 1.0f);
	glColor3f(0.1f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.4 + wood3, -0.1);
	glVertex2f(-0.9 + wood3, -0.1);
	glVertex2f(-0.9 + wood3, -0.5);
	glVertex2f(-0.4 + wood3, -0.5);
	glEnd();

	wood1 += woodSpeed;
	wood2 += woodSpeed;
	wood3 += woodSpeed;
	if (wood1 >= 1) {
		wood1 = -1.6;
	}
	if (wood2 >= 1.4) {
		wood2 = -1.6;
	}
	if (wood3 >= 1.8) {
		wood3 = -1.6;
	}

	if ((-0.1 + movey) * 0.5 >= -0.5 && (0.4 + movey) * 0.5 <= -0.1) {
		alive = false;
		if ((-0.20 + movex) * 0.5 >= wood1 + 0.4 && (-0.20 + movex) * 0.5 <= wood1 + 0.9 && (0.20 + movex) * 0.5 >= wood1 + 0.4 && (0.20 + movex) * 0.5 <= wood1 + 0.9) {
			alive = true;
			cout << "you're in wood 1" << endl;
		}
		else if ((-0.20 + movex) * 0.5 >= wood2 - 0.25 && (-0.20 + movex) * 0.5 <= wood2 + 0.25 && (0.20 + movex) * 0.5 >= wood2 - 0.25 && (0.20 + movex) * 0.5 <= wood2 + 0.25) {
			alive = true;
			cout << "you're in wood 2" << endl;
		}
		else if ((-0.20 + movex) * 0.5 >= wood3 - 0.9 && (-0.20 + movex) * 0.5 <= wood3 - 0.4 && (0.20 + movex) * 0.5 >= wood3 - 0.9 && (0.20 + movex) * 0.5 <= wood3 - 0.4) {
			alive = true;
			cout << "you're in wood 3" << endl;
		}
		else if (alive == false) {
			woodSpeed = 0;
			RenderStringLose(-0.4f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24);
			dis = 100;
		}
	}

}

void sun(float x, float y) {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(x, y, 0);
	glPushMatrix();
	glTranslatef(0.5, 0, 0);
	glRotatef(angle, 0, 0, 1);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.5, 0.8);
	glVertex2f(0.7, 0.9);
	glVertex2f(0.6, 0.7);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.6, 0.7);
	glVertex2f(0.7, 0.7);
	glVertex2f(0.6, 0.7);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.6, 0.7);
	glVertex2f(0.7, 0.5);
	glVertex2f(0.5, 0.6);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.5, 0.6);
	glVertex2f(0.3, 0.5);
	glVertex2f(0.4, 0.7);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.4, 0.7);
	glVertex2f(0.3, 0.7);
	glVertex2f(0.4, 0.7);
	glEnd();

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0.4, 0.7);
	glVertex2f(0.3, 0.9);
	glVertex2f(0.5, 0.8);
	glEnd();

	glBegin(GL_POLYGON);
	draw_circle(0.1, 0, 360, 0.5, 0.7, 0.8, 0.8, 0.8);
	glEnd();

	glPopMatrix();
	glPopMatrix();
	angle += 0.1;
	glFlush();
}



void display() {
	glClearColor(0.0f, 1.0, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	sea();
	ground2();
	woods();
	ground();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glScalef(0.5f, 0.5f, 0);
	glTranslatef(movex, movey, 0);
	D();
	glPopMatrix();
	sun(0.9, 0.9);
	glColor3f(1, 0, 0);
	glPointSize(4);
	glBegin(GL_POINTS);
	glVertex2f((0.25 + movex) * 0.5, -0.5);
	glEnd();
	glFlush();
	glutPostRedisplay();

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(" Task ");
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}