#include <string>

#include "GetGlut.h"
#include "Sleep.h"
#include "Square.h"
#include "Fountain.h"
#include "Sparkle.h"

using namespace std;
using namespace ObjLibrary;

// prototypes
void initDisplay();
void keyboard(unsigned char key, int x, int y);
void update();
void reshape(int w, int h);
void display();

// Globals
const unsigned int SQUARE_COUNT = 100;
//Square squares_S[SQUARE_COUNT];
//Fountain squares_F[SQUARE_COUNT];
Sparkle squares[SQUARE_COUNT];
//Please manully change the shape here, unable to complete the keyboard function
unsigned int next_square = 0;
bool emitter_on = true;
Vector2 emitter_position;
int inp=-1;

int main(int argc, char** argv)
{
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
	glutCreateWindow("Particles");
	glutKeyboardFunc(keyboard);
	glutIdleFunc(update);
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	initDisplay();

	glutMainLoop();

	return 1;
}

void initDisplay()
{
	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// Blue background
	// glClearColor(0.0f, 0.0f, 0.5f, 0.0f);

	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: // on [ESC]
		exit(0); // normal exit
		break;
	case ' ': // on [SPACEBAR]
		emitter_on = !emitter_on;
		break;
	case 'w':
		emitter_position += Vector2(0.0, 5.0);
		break;
	case 's':
		emitter_position += Vector2(0.0, -5.0);
		break;
	case 'a':
		emitter_position += Vector2(-5.0, 0.0);
		break;
	case 'd':
		emitter_position += Vector2(5.0, 0.0);
		break;
	case 'R':
		inp = 0;	
		break;
	case 'r':
		inp = 1;
		break;
	case 'G':
		inp = 2;
		break;
	case 'g':
		inp = 3;
		break;
	case 'B':
		inp = 4;
		break;
	case 'b':
		inp = 5;
		break;
	}
}

void update()
{
	next_square = (next_square + 1) % SQUARE_COUNT;
	if (emitter_on) {
		squares[next_square].init(emitter_position);
	}
	if (inp != -1) {
		if (inp == 0) {
			squares[next_square].Rplus();
			inp = -1;
		}
		if (inp == 1) {
			squares[next_square].Rminus();
			inp = -1;
		}
		if (inp == 2) {
			squares[next_square].Gplus();
			inp = -1;
		}
		if (inp == 3) {
			squares[next_square].Gminus();
			inp = -1;
		}
		if (inp == 4) {
			squares[next_square].Bplus();
			inp = -1;
		}
		if (inp == 5) {
			squares[next_square].Bminus();
			inp = -1;
		}
	}
	for (int i = 0; i < SQUARE_COUNT; i++) {
		squares[i].update();
	}

	sleep(1.0 / 60.0);
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	int x_center = w / 2;
	int y_center = h / 2;

	// set up a 2D view
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-x_center, w - x_center, -y_center, h - y_center);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutPostRedisplay();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// clear the screen - any drawing before here will not display

	// Draw squares
	for (int i = 0; i < SQUARE_COUNT; i++) {
		if (squares[i].isAlive()) {
			squares[i].display();
		}
	}

	// send the current image to the screen - any drawing after here will not display
	glutSwapBuffers();
}


