#include "../include/Units.h"


Unit::Unit(axisVector windowSize, axisVector pos, axisVector dir,float sector, float distance)
{
	this->direction = dir;
	this->position = pos;

	windowHeight = windowSize.y;
	windowWidth = windowSize.x;

	this->sector = sector;
	this->distance = distance;

	axisVector reference(0.5, 0);
	float angle = angleAxisTan(this->direction, reference);
	angleDir = angle * -1;
	radius = 10.f;
	widthLine = radius;

	triangle.setPosition(windowWidth / 2 + this->position.x, windowHeight / 2 - this->position.y);
	triangle.setRadius(radius);
	triangle.setFillColor(yellow);

	line.setSize(Vector2f(0, 0));
	line.setRotation(angleDir);
	line.setFillColor(red);

	line.setPosition(Vector2f(windowWidth / 2 + this->position.x + radius, windowHeight / 2 - this->position.y + radius));
}

bool Unit::patrol_of_area(RenderWindow& window, axisVector intersec)
{
	bool state = false;

	float fov = sector / 2;
	float fovLine = fov;
	line.setSize(Vector2f(distance, 2));
	for (int i = 0; i < sector; i++) {
		line.setRotation(fov - angleDir);

		fovLine++;
		fov--;


		float xline = sin((fov - angleDir) / 180 * PI) * distance + this->position.x + radius;
		float liney = cos((fov - angleDir) / 180 * PI) * distance + this->position.y - radius;


		float d = distAxis(this->position, intersec);
		axisVector ds(xline, liney);
		float d1 = distAxis(ds, intersec);

		if (d <= distance) {
			axisVector P1(intersec.x - widthLine / 2, intersec.y);
			axisVector P2(intersec.x + widthLine * 2, intersec.y);
			axisVector P3(intersec.x - widthLine / 2, intersec.y - widthLine * 2);
			axisVector P4(intersec.x + widthLine * 2, intersec.y - widthLine * 2);

		
			

			axisVector point;
		
			bool in[4] = { 0, };
			axisVector line[4][2] = { { P1,P3 },{ P3,P4 },{ P4,P2},{ P1,P2 } };

			for (int i = 0; i < 4; i++) {
				in[i] = intersect(this->position, ds, line[i][0], line[i][1]);
				if (in[i]) {
					state = true;
					break;
				}
			}

		}
		

		window.draw(line);
	}

	

	return state;
	
}

void Unit::setPosition(axisVector pos)
{
	this->position = pos;

}



void Unit::update(RenderWindow& window)
{
	window.draw(triangle);
	window.draw(line);
}
