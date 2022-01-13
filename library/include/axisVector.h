#ifndef AXIS_VECTOR
#define AXIS_VECTOR

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<vector>
#include <memory>
#include<math.h>


#define PI 3.1415926535
#define EPSILON  1e-9

typedef struct axisVector
{
private:

public:
	float x;
	float y;

	axisVector() :x(0), y(0) {};
	axisVector(float x, float y) :x(x), y(y) {};

	bool operator ==(const axisVector& point) const { return point.x == this->x && point.y == this->y; }
	bool operator !=(const axisVector& point) const { return point.x != this->x || point.y != this->y; }
	axisVector operator =(axisVector& point) const {
		return axisVector(point.x = this->x, point.y = this->y);
	}
	axisVector operator +(const axisVector& point) const {
		return axisVector(point.x + this->x, point.y + this->y);
	}
	axisVector operator -(const axisVector& point) const {
		return axisVector(point.x - this->x, point.y - this->y);
	}

	axisVector operator *(const axisVector& point) const {
		return axisVector(point.x * this->x, point.y * this->y);
	}

	axisVector operator /(const axisVector& point) const {
		return axisVector(point.x / this->x, point.y / this->y);
	}

	//----------------------------------------------------------------

	axisVector operator +(const float val) const {
		return axisVector(val + this->x, val + this->y);
	}
	axisVector operator -(const float val) const {
		return axisVector(val - this->x, val - this->y);
	}

	axisVector operator *(const float val) const {
		return axisVector(val * this->x, val * this->y);
	}

	axisVector operator /(const float val) const {
		return axisVector(val / this->x, val / this->y);
	}

	//----------------------------------------------------------------

	float max() const { return this->x > this->y ? this->x : this->y; }

	void operator = (axisVector& point) {
		this->x = point.x;
		this->y = point.y;
	}

	double norm() {

		return sqrt((double)this->x * this->x + this->y * this->y);
	}

	axisVector normal() { return  axisVector(this->x * (1 / sqrtf(this->x * this->x + this->y * this->y)), this->y * (1 / sqrtf(this->x * this->x + this->y * this->y))); }

	float dot(const axisVector& b) const { return this->x * b.x + this->y * b.y; }


};

double normalize(axisVector pointA, axisVector pointB);
float angleAxisTan(axisVector v1, axisVector v2);
float distAxis(axisVector v1, axisVector v2);



#endif