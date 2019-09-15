#include <Windows.h>	//for Windows
#include <GL/glut.h>	//for glut
#include <math.h>		//to draw circles
#define pi 3.142857
static int radius = 2;

void init() {
	gluOrtho2D(-1.5, 1.5, -1.5, 1.5);		//define cartesian coordinates 
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	//set background color to black and opaque
}

void SquareUp(){
	glPointSize(8);

	//Square
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);	//color red
	glVertex2f(-0.5f, -0.5f);		//x, y coordinates for lower left corner
	glVertex2f(0.5f, -0.5f);		//lower right corner
	glVertex2f(0.5f, 0.5f);			//upper right corner
	glVertex2f(-0.5f, 0.5f);		//upper left corner
	glEnd();

	//Triangle				
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 0.0f);	//color yellow
	glVertex2f(-0.5f, -0.25f);		//bottom left corner
	glVertex2f(0.5f, -0.25f);		//bottom rigt corner
	glVertex2f(0.0f, 0.75f);		//apex
	glEnd();

	//Points
	glBegin(GL_POINTS);
	glPointSize(8);
	glColor3f(0.0f, 0.0f, 0.0f);	//color black
	glVertex2f(0.0f, 0.15f);	
	glEnd();

	//Hexagon
	glBegin(GL_POLYGON);            // These vertices form a closed polygon
	glColor3f(1.0f, 1.0f, 1.0f);	// White
	glVertex2f(0.4f, 0.2f);
	glVertex2f(0.6f, 0.2f);
	glVertex2f(0.7f, 0.4f);
	glVertex2f(0.6f, 0.6f);
	glVertex2f(0.4f, 0.6f);
	glVertex2f(0.3f, 0.4f);
	glEnd();

	//Circle
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0f, 0.0f, 1.0f);  // Blue
	glVertex2f(0.0f, 0.0f);       // Center of circle
	int numSegments = 100;
	GLfloat angle;
	for (int i = 0; i <= numSegments; i++) { // Last vertex same as first vertex
		angle = i * 2.0f * pi / numSegments;  // 360 deg for all segments
		glVertex2f(cos(angle) * radius, sin(angle) * radius);
	}


	glFlush();						//render now
}

int main(int argc, char**argv) {
	glutInit(&argc,argv);			//initialise glut
	glutCreateWindow("SquareUp");	//creates window with given name
	glutInitWindowSize(320, 320);	//window size
	glutInitWindowPosition(50, 50);	//positin window to top left corner
	init();
	glutDisplayFunc(SquareUp);
	glutMainLoop();					//enter event processing loop
}
