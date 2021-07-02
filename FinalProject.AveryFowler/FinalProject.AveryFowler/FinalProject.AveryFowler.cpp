//
//  main.cpp
//  Final Project
//
//  Created by Avery J Fowler on 5/1/21.
//  Copyright © 2021 Avery J Fowler. All rights reserved.
//


/*

		PRESS P TO START THE ANIMATION

*/
#define GL_SILENCE_DEPRECATION
#include <GLUT/GLUT.h>
#include <iostream>
#include <math.h>
#define PI 3.14159265

bool lookUp;
bool lookDown;
bool lookLeft;
bool lookRight;
bool walkForward;
bool walkBackward;
bool strafeLeft;
bool strafeRight;
float xCameraLocation = 0;
//float xCameraLocation;
float yCameraLocation;
float zCameraLocation = 17;
//float zCameraLocation;
float yRotationAngle;
float zRotationAngle;
float xRotationAngle;
float forwardMovement = 1.0f;

//snowman control
float xSnowman = 10.0;
float ySnowman = 5.0;
float zSnowman = 0.0;
float angleYSnowman = 0;
float angleZSnowman = 0;
float angleXSnowman = 0;

//ship controll
float xShip = -10.0;
float yShip = 5.0;
float zShip = 0.0;
float angleYShip = 0;
float angleZShip = 0;
float angleXShip = 0;
bool animation = false;

//materials
GLfloat snow_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat snow_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat snow_shiny[] = { 30 };

GLfloat coal_ambient[] = { 0.0, 0.0, 0.0, 0.0 };
GLfloat coal_diffuse[] = { 0.0, 0.0, 0.0, 0.0 };
GLfloat coal_shiny[] = { 20 };

GLfloat wood_ambient[] = { 0.545, 0.271, 0.075, 1.0 };
GLfloat wood_diffuse[] = { 0.545, 0.271, 0.075, 1.0 };
GLfloat wood_shiny[] = { 5 };

GLfloat carrot_ambient[] = { 1.0, 0.498, 0.0, 1.0 };
GLfloat carrot_diffuse[] = { 1.0, 0.498, 0.0, 1.0 };
GLfloat carrot_shiny[] = { 5 };

GLfloat teapot_ambient[] = { 0.824, 0.412, 0.118, 1.0 };
GLfloat teapot_diffuse[] = { 0.824, 0.412, 0.118, 1.0 };
GLfloat teapot_shiny[] = { 50 };

GLfloat hull_ambient[] = { 0.780, 0.780, 0.780, 1.0 };
GLfloat hull_diffuse[] = { 0.780, 0.780, 0.780, 1.0 };
GLfloat hull_shiny[] = { 30 };

GLfloat glass_ambient[] = { 0.517, 0.843, 0.823, 1.0 };
GLfloat glass_diffuse[] = { 0.517, 0.843, 0.823, 1.0 };
GLfloat glass_shiny[] = { 50 };

GLfloat frame_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
GLfloat frame_diffuse[] = { 0.1, 0.1, 0.1, 1.0 };
GLfloat frame_shiny[] = { 0 };

GLfloat bow_ambient[] = { 0.019, 0.050, 1, 1.0 };
GLfloat bow_diffuse[] = { 0.019, 0.050, 1, 1.0 };
GLfloat bow_shiny[] = { 40 };

GLfloat jet_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
GLfloat jet_diffuse[] = { 0.4, 0.4, 0.4, 1.0 };
GLfloat jet_shiny[] = { 10 };

GLfloat flame_ambient[] = { 0.988, 0.431, 0.192, 1.0 };
GLfloat flame_diffuse[] = { 0.988, 0.431, 0.192, 1.0 };
GLfloat flame_shiny[] = { 0 };

void drawSnowman(void) {
	glColor3f(1.0f, 1.0f, 1.0f);

	glMaterialfv(GL_FRONT, GL_AMBIENT, snow_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, snow_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, snow_shiny);

	glPushMatrix();
	glTranslatef(0.0, -3.5, 0.0);
	glutSolidSphere(1.5, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.8, 0.0);
	glutSolidSphere(1.2, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 1.3, 0.0);
	glutSolidSphere(0.9, 20, 20);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_AMBIENT, teapot_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, teapot_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, teapot_shiny);

	glColor3f(0.824f, 0.412f, 0.118f);
	glPushMatrix();
	glTranslatef(0.0, 2.7, 0.0);
	glutSolidTeapot(0.9);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_AMBIENT, carrot_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, carrot_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, carrot_shiny);

	glColor3f(1.0f, 0.498f, 0.0f);
	glPushMatrix();
	glTranslatef(0.0, 1.3, 0.9);
	glutSolidCone(0.2, 0.5, 20, 20);
	glPopMatrix();

	glColor3f(0.0f, 0.0f, 0.0f);

	glMaterialfv(GL_FRONT, GL_AMBIENT, coal_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, coal_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, coal_shiny);

	glPushMatrix();
	glTranslatef(0.5, 1.7, 0.75);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 1.7, 0.75);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 1.0, 0.75);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 1.0, 0.75);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.4, 0.90, 0.75);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.3, 0.80, 0.75);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.2, 0.7, 0.75);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.1, 0.7, 0.75);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.4, 0.90, 0.75);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.3, 0.80, 0.75);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.2, 0.7, 0.75);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.1, 0.7, 0.75);
	glutSolidSphere(0.1, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -3.5, 1.5);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -2.75, 1.25);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -4.25, 1.25);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.8, 1.2);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -0.1, 1.0);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, -1.5, 1.0);
	glutSolidSphere(0.2, 20, 20);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_AMBIENT, wood_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, wood_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, wood_shiny);

	glColor3f(0.545f, 0.271f, 0.075f);
	glPushMatrix();
	glTranslatef(2.2, -0.8, 0.0);
	glRotatef(-90, 0.0, 1.0, 0.0);
	glutSolidCone(0.4, 1.0, 20, 20);
	//glTranslatef(1.0, 0.0, -1.0);
	glRotatef(180, 0.0, 1.0, 0.0);
	glutSolidCone(0.4, 1.0, 20, 20);
	glPopMatrix();

	//glColor3f(0.545f, 0.271f, 0.075f);
	glPushMatrix();
	glTranslatef(-2.2, -0.8, 0.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidCone(0.4, 1.0, 20, 20);
	//glTranslatef(-1.0, 0.0, .0);
	glRotatef(180, 0.0, 1.0, 0.0);
	glutSolidCone(0.4, 1.0, 20, 20);
	glPopMatrix();
}

void drawShip(void) {

	glMaterialfv(GL_FRONT, GL_AMBIENT, hull_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, hull_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, hull_shiny);

	glPushMatrix();
	glutSolidCube(2.0);
	glTranslatef(0.0, -2.0, 0.0);
	glutSolidCube(2.0);
	glPopMatrix();


	glMaterialfv(GL_FRONT, GL_AMBIENT, glass_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, glass_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, glass_shiny);

	glPushMatrix();
	glutSolidSphere(1.1, 20, 20);
	glPopMatrix();


	glMaterialfv(GL_FRONT, GL_AMBIENT, frame_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, frame_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, frame_shiny);

	glPushMatrix();
	glTranslatef(0.9, 0.0, 0.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidTorus(0.2, 0.6, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 0.9);
	glutSolidTorus(0.2, 0.6, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.9);
	glutSolidTorus(0.2, 0.6, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.9, 0.0, 0.0);
	glRotatef(90, 0.0, 1.0, 0.0);
	glutSolidTorus(0.2, 0.6, 20, 20);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_AMBIENT, bow_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, bow_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, bow_shiny);

	glPushMatrix();
	glTranslatef(0.0, 1.0, 0.0);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glutSolidCone(1.1, 3.0, 20, 20);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_AMBIENT, jet_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, jet_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, jet_shiny);

	glPushMatrix();
	glTranslatef(0.5, -3.5, 0.5);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glutSolidCone(0.3, 0.5, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, -3.5, 0.5);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glutSolidCone(0.3, 0.5, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, -3.5, -0.5);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glutSolidCone(0.3, 0.5, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, -3.5, -0.5);
	glRotatef(-90, 1.0, 0.0, 0.0);
	glutSolidCone(0.3, 0.5, 20, 20);
	glPopMatrix();

	glMaterialfv(GL_FRONT, GL_AMBIENT, flame_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, flame_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, flame_shiny);

	glPushMatrix();
	glTranslatef(0.5, -3.5, 0.5);
	glRotatef(90, 1.0, 0.0, 0.0);
	glutSolidCone(0.2, 0.4, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, -3.5, 0.5);
	glRotatef(90, 1.0, 0.0, 0.0);
	glutSolidCone(0.2, 0.4, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, -3.5, -0.5);
	glRotatef(90, 1.0, 0.0, 0.0);
	glutSolidCone(0.2, 0.4, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, -3.5, -0.5);
	glRotatef(90, 1.0, 0.0, 0.0);
	glutSolidCone(0.2, 0.4, 20, 20);
	glPopMatrix();

}
void display(void)
{
	GLUquadricObj *pObj; // Quadric Object
	pObj = gluNewQuadric();
	gluQuadricNormals(pObj, GLU_SMOOTH);
	GLfloat horizontalMovement = 1;
	GLfloat verticalMovement = 0;
	horizontalMovement = cos(xRotationAngle*PI / 180);
	verticalMovement = -sin(xRotationAngle*PI / 180);
	
	GLfloat light_color[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_color);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	// Reset Model view matrix stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-xRotationAngle, 1, 0, 0);
	glRotatef(yRotationAngle, 0, 1, 0);
	glTranslatef(-xCameraLocation, -yCameraLocation, -zCameraLocation);
	glTranslatef(0, -0.50, -10);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(0, 100, 0);
	glColor3f(1, 0.8, 0);
	glutSolidSphere(10, 20, 20);
	glPopMatrix();
	glColor3f(0, 0, 0);
	glLineWidth(2);
	glBegin(GL_LINES);

	//x
	glColor3f(1, 0, 0);
	glVertex3f(-10, 0, 0);
	glVertex3f(10, 0, 0);

	

	//z
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, -10);
	glVertex3f(0, 0, 10);
	glEnd();

	//desert
	glColor3ub(10, 255, 10);
	glBegin(GL_QUADS);
	for (int i = -100;i <= 100;i += 10)
		for (int j = -100;j <= 100;j += 10)
		{
			glVertex3f(i + 10, 0, j);
			glVertex3f(i, 0, j);
			glVertex3f(i, 0, j + 10);
			glVertex3f(i + 10, 0, j + 10);
		}
	glEnd();

	//snowman idisplay
	glPushMatrix();
	glTranslatef(xSnowman, ySnowman, zSnowman);
	glRotatef(angleYSnowman, 0.0, 1.0, 0.0);
	glRotatef(angleZSnowman, 0.0, 0.0, 1.0);
	glRotatef(angleXSnowman, 1.0, 0.0, 0.0);
	drawSnowman();
	glPopMatrix();

	//ship display
	glPushMatrix();
	glTranslatef(xShip, yShip, zShip);
	glRotatef(angleZShip, 0.0, 0.0, 1.0);
	glRotatef(angleYShip, 0.0, 1.0, 0.0);
	glRotatef(angleXShip, 1.0, 0.0, 0.0);
	drawShip();
	glPopMatrix();

	
	glEnd();
	glutSwapBuffers();
}
void timer(int value)
{
	// Redraw the scene with new coordinates
	glutPostRedisplay();
	glutTimerFunc(16, timer, 1);
}
void init(void)
{
	lookUp = false;
	lookDown = false;
	lookLeft = false;
	lookRight = false;
	walkForward = false;
	walkBackward = false;
	strafeLeft = false;
	strafeRight = false;
	yRotationAngle = 0;
	xRotationAngle = 0;
	zRotationAngle = 0;
	//turn culling on
	//glEnable(GL_CULL_FACE);
	//turn depth test on
	glEnable(GL_DEPTH_TEST);
	// White background
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// Set drawing color to green
	glColor3f(0.0f, 1.0f, 0.0f);
	// Set color shading model to flat
	glShadeModel(GL_SMOOTH);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
void resize(int w, int h)
{
	//GLfloat nRange = 100.0f;
	// Prevent a divide by zero
	if (h == 0)
		h = 1;
	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);
	// Reset projection matrix stack
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Establish clipping volume (left, right, bottom, top, near, far)
	GLfloat fAspect = (GLfloat)w / (GLfloat)h;
	gluPerspective(45, fAspect, 0.1, 1000);
	// Reset Model view matrix stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
// Respond to arrow keys by moving the camera frame of reference
void special(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		xRotationAngle--;
		break;
	case GLUT_KEY_DOWN:
		xRotationAngle++;
		break;
	case GLUT_KEY_LEFT:
		yRotationAngle--;
		break;
	case GLUT_KEY_RIGHT:
		yRotationAngle++;
		break;
	default:
		break;
	}
	// Refresh the Window
	glutPostRedisplay();
}
void keyboardFunc(unsigned char key, int x, int y)
{
	//float VM = (sin(xRotationAngle*PI / 180.0)*forwardMovement);
	float HM = (cos(xRotationAngle*PI / 180.0)*forwardMovement);
	float dX = sin(yRotationAngle*PI / 180.0) * HM;
	float dZ = -cos(yRotationAngle * PI / 180.0) * HM;
	//float dY = VM;
	float dXSide = 0;
	float dZSide = 0;
	float dYSide = 0;
	switch (key)
	{
	case 'w':
		xCameraLocation += dX;
		//yCameraLocation += dY;
		zCameraLocation += dZ;
		break;
	case 's':
		xCameraLocation -= dX;
		//yCameraLocation -= dY;
		zCameraLocation -= dZ;
		break;
	case 'a':
		dXSide = sin((yRotationAngle - 90)*PI / 180.0) * 1;
		dZSide = -cos((yRotationAngle - 90) * PI / 180.0) * 1;
		dYSide = 0;
		xCameraLocation += dXSide;
		//yCameraLocation += dYSide;
		zCameraLocation += dZSide;
		break;
	case 'd':
		dXSide = sin((yRotationAngle + 90)*PI / 180.0) * 1;
		dZSide = -cos((yRotationAngle + 90) * PI / 180.0) * 1;
		dYSide = 0;
		xCameraLocation += dXSide;
		//yCameraLocation += dYSide;
		zCameraLocation += dZSide;
		break;
	case 'p':
		animation = true;
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}

}
//variables used for the animation
int count = 0;
bool turn = true;
bool rush = false;
bool daze = false;
bool fall = false;

//each part triggers the next when finished
void idle() {
	if (animation) {
		//turns objects to face each other
		if (turn) {
			angleZShip += -1;
			angleYSnowman += -1;
			if (angleZShip == -90) {
				turn = false;
				rush = true;
			}
		}
		//moves objects closer to each other
		if (rush) {
			xShip += 0.1;
			xSnowman -= 0.1;
			count++;
			if (count == 77) {
				rush = false;
				daze = true;
				count = 0;
			}
		}
		//spins around after colliding
		if (daze) {
			angleXShip += -10;
			angleYSnowman += 8;
			xShip += -0.01;
			xSnowman += 0.01;
			count++;
			if (count == 360) {
				daze = false;
				fall = true;
				count = 0;
			}	
		}
		//has them fall into the ground
		if(fall){
			angleZShip += -3;
			yShip += -0.18;
			angleXSnowman += -3.1;
			ySnowman += -0.11;
			xSnowman += 0.11;
			count++;
			if (count == 30) {
				fall = false;
			}
		}
		glutPostRedisplay();
	}
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("First Person View");
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutSpecialFunc(special);
	glutKeyboardFunc(keyboardFunc);
	glutIdleFunc(idle);
	glutTimerFunc(16, timer, 1);
	init();
	glutMainLoop();
	return 0;
}


