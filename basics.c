
// - מגיש אוראל סבש
#include <stdio.h>

/* Include the GLUT library. This file (glut.h) contains gl.h and glu.h */
#include <GL/glut.h>

/* This is a debug file */
FILE *infofile;

/* 
 * The rountine display() gets called each time the window is redrawn.
 */
void display()
{
	fprintf(infofile,"display: Entered \n");
	fflush(infofile);

	/* clear the screen*/
	glClear(GL_COLOR_BUFFER_BIT);


	// - מרובע אדום
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.0f, 0.0f); // - שינוי לצבע אדום
		glVertex2f(-0.5, -0.5);
		glVertex2f( 0.5, -0.5);
		glVertex2f( 0.5,  0.5);
		glVertex2f(-0.5,  0.5);
	glEnd();
	
	// - משולש ירוק
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.0f); // - שינוי לצבע ירוק
	glVertex2f(-2.0, -0.5);
	glVertex2f(-1.0, -0.5);
	glVertex2f(-1.5, 0.5);
	glEnd();

	// - משושה צהוב
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f); // - שינוי לצבע צהוב
	glVertex2f(1.5, -0.5);
	glVertex2f(2.0, -0.5);
	glVertex2f(2.25, 0.0);
	glVertex2f(2.0, 0.5);
	glVertex2f(1.5, 0.5);
	glVertex2f(1.25, 0.0);


	glEnd();

	/* draw a fancy line -- red to blue variation in color */
	/* variation is created with linear interpolation */
	glBegin(GL_LINES);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(-0.75, -0.75);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(0.75, -0.75);
	glEnd();


	/* ready to draw now! forces buffered OGL commands to execute */
	glFlush();

	fprintf(infofile,"display: Exit \n");
	fflush(infofile);
}

/* Initialize states -- called before */

void init()
{
	fprintf(infofile,"init: Entered \n");
	fflush(infofile);


	/* set background clear color to black */
	glClearColor(0.0, 0.0, 0.0, 0.0);
	/* set current color to white */
	glColor3f(1.0, 1.0, 1.0);

	/* identify the projection matrix that we would like to alter */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* the window will correspond to these world coorinates */
	gluOrtho2D(-5.0, 5.0, -5.0, 5.0); // - שינוי מיקום החלון 

	/* we can play ... see what happens if we swap out this one with that above */
	//gluOrtho2D(-10.0, 10.0, -10.0, 10.0);

	/* identify the modeling and viewing matrix that can be modified from here on */
	/* we leave the routine in this mode in case we want to move the object around */
	/* or specify the camera */
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	fprintf(infofile,"init: Exit \n");
	fflush(infofile);
}

/* The main program */

int main(int argc, char** argv)
{
	/* Always a good idea to create a file to help you understand the program flow */
	/* Graphics programs can crash, so fflush is a good idea -- even if it slows things */
	infofile = fopen("infofile.txt", "w");
	fprintf(infofile,"basics.c -- a basic OpenGL program\n");
	fflush(infofile);

	/* create a window, position it, and name it */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(750, 750); // - שינוי גודל חלון
	glutInitWindowPosition(400, 250); // - שינוי מיקום חלון
	glutCreateWindow("basics");

	fprintf(infofile,"Created windows\n");
	fflush(infofile);

	/* create a callback routine for (re-)display */
	glutDisplayFunc(display);

	/* init some states */
	init();

	/* entering the event loop */
	glutMainLoop();

	/* code here will not be executed */
}
