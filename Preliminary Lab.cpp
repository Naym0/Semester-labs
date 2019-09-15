#include <Windows.h>	//for Windows
#include <GL/glut.h>	//for glut
#include <math.h>		//to draw circles
#define pi 3.142857		//DONE BY 102214 AND 101112

void init() {
	gluOrtho2D(-3.5, 3.5, -3.5, 3.5);		//define cartesian coordinates 
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	//set background color to black and opaque
}

//function to generate circle
void drawCircle(GLfloat x, GLfloat y, GLfloat r) {
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


void Lab() {
	glPointSize(8);

	//Square
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.7, 0.7);
	glVertex2f(0.7, 0.7);
	glVertex2f(0.7, -0.7);
	glVertex2f(-0.7, -0.7);
	glEnd();

	//Smaller Square
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.5, 0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(-0.5, -0.5);
	glEnd();

	//Star made with triangles
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLES);
	glVertex3f(1.5, 2, 0);
	glVertex3f(1, 1, 0);
	glVertex3f(2, 1, 0);
	glVertex3f(1.5, 0.8, 0);
	glVertex3f(2, 1.7, 0);
	glVertex3f(1, 1.7, 0);
	glEnd();

	//call function for the circles
	drawCircle(-2.5,2.5,0.5);
	drawCircle(-2, 2.5, 0.5);
	drawCircle(-2.2, 2, 0.5);

	//call function for the arc
	drawArc(-2, -1.5, 1);

	glFlush();						//render now
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);			//initialise glut
	glutCreateWindow("Lab");	//creates window with given name
	glutInitWindowSize(320, 320);	//window size
	glutInitWindowPosition(50, 50);	//positin window to top left corner
	init();
	glutDisplayFunc(Lab);
	glutMainLoop();					//enter event processing loop
}