#pragma once
#include <SFML/Graphics.hpp>
#include"library/include/auxiliary.h"


using namespace sf;


class Unit {
public:
	Unit() {};
	Unit(axisVector windowSize, axisVector pos, axisVector dir,float sector,float distance);
	bool patrol_of_area(RenderWindow& window, axisVector Intersects);
	void setPosition(axisVector pos);
	void update(RenderWindow& window);
	axisVector getposition() { return position; }
	
private:
	axisVector position;
	axisVector direction;
	CircleShape triangle;
	RectangleShape line;
	RenderWindow window;
	Color yellow = Color(200, 200, 0);
	Color red = Color(200, 0, 0, 100);
	Color green = Color(0, 255, 0);
	float windowHeight;
	float windowWidth;
	float angleDir;
	float radius;
	float widthLine;
	CircleShape check;
	float sector;
	float distance;
};
