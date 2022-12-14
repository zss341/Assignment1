#pragma once

#include "ObjLibrary/Vector2.h"
using namespace ObjLibrary;

class Sparkle {

public:

	void update();
	void display();
	bool isAlive();
	void init(Vector2);
	Sparkle();
	void Rplus();
	void Gplus();
	void Bplus();
	void Rminus();
	void Gminus();
	void Bminus();
private:

	Vector2 pos;
	double age;
	float red;
	float green;
	float blue;
	float size;
	float transparency;
	float rotation;
	float random0to1();

};