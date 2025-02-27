#include <Windows.h>	//for Windows
#include <GL/glut.h>	//for glut
#include <math.h>		//to draw circles
#define pi 3.142857		//DONE BY 102214 AND 101112

void init() {
	gluOrtho2D(-14, 14, -14, 14);		//define cartesian coordinates 
	glClearColor(1.0f, 0.74f, 0.01f, 1.0f);	//set background color to black and opaque
}

//function for the circle
void drawCircle(GLfloat x, GLfloat y, GLfloat r) {
	glColor3f(0.0f, 0.0f, 1.0f);	//Blue
	static const double inc = pi / 12;
	static const double max = 2 * pi;
	glBegin(GL_LINE_LOOP);
	for (double d = 0; d < max; d += inc) {
		glVertex2f(cos(d) * r + x, sin(d) * r + y);
	}
	glEnd();
}

//function for the arc
void drawArc(GLfloat x, GLfloat y, GLfloat radius) {
	int i;
	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	//GLfloat pi = 2.0f * pi;

	glBegin(GL_LINE_STRIP);
	for (i = 0; i <= lineAmount;i++) {
		glVertex2f(
			x + (radius * cos(i * pi / lineAmount)),
			y + (radius * sin(i * pi / lineAmount))
		);
	}
	glEnd();
}


void House() {
	glPointSize(5);
	glLineWidth(1.5);

	//Windows
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);	//yellow
	glVertex2f(-8, 0);
	glVertex2f(-4, 0);
	glVertex2f(-4, -4);
	glVertex2f(-8, -4);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);	//yellow
	glVertex2f(4, 0);
	glVertex2f(8, 0);
	glVertex2f(8, -4);
	glVertex2f(4, -4);
	glEnd();

	//Vertical lines in Windows
	glBegin(GL_LINE_LOOP);
	glColor3f(0.05f, 0.78f, 0.96f);  // Blue
	glVertex2f(-6, 0);
	glVertex2f(-6, -4);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(6, 0);
	glVertex2f(6, -4);
	glEnd();

	//Horizontal lines in Windows
	glBegin(GL_LINE_LOOP);
	glColor3f(0.05f, 0.78f, 0.96f);  // Blue
	glVertex2f(-8, -2);
	glVertex2f(-4, -2);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(4, -2);
	glVertex2f(8, -2);
	glEnd();

	//Door outline
	glBegin(GL_LINE_LOOP);
	glColor3f(0.05f, 0.78f, 0.96f);  // Blue
	glVertex2f(-2, 0);
	glVertex2f(2, 0);
	glVertex2f(2, -8);
	glVertex2f(-2, -8);
	glEnd();

	//Door
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);  // White
	glVertex2f(-2, 0);
	glVertex2f(2, 0);
	glVertex2f(2, -8);
	glVertex2f(-2, -8);
	glEnd();

	//House Outline
	glBegin(GL_LINE_LOOP);
	glColor3f(0.05f, 0.78f, 0.96f);  // Blue
	glVertex2f(-12, 4);
	glVertex2f(12, 4);
	glVertex2f(12, 1);
	glVertex2f(10, 1);
	glVertex2f(10, -8);
	glVertex2f(-10, -8);
	glVertex2f(-10, 1);
	glVertex2f(-12, 1);
	glEnd();

	//call function for the arc
	drawArc(0, 4, 6);

	//Doorknob
	glBegin(GL_POINTS);
	glPointSize(8);
	glColor3f(0.05f, 0.78f, 0.96f);  // Blue
	glVertex2f(1.5f, -4.0f);
	glEnd();

	//Doorknob outline
	drawCircle(1.5, -4.0, 0.1);

	//Moon

	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);			//initialise glut
	glutCreateWindow("House");	//creates window with given name
	glutInitWindowSize(500, 500);	//window size
	glutInitWindowPosition(50, 50);	//positin window to top left corner
	init();
	glutDisplayFunc(House);
	glutMainLoop();					//enter event processing loop
}