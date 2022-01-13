#include"../include/axisVector.h"

axisVector operator +=(axisVector& pointA, axisVector& pointB) {
	pointA.x += pointB.x;
	pointA.y += pointB.y;
	return pointA;
}
axisVector operator -=(axisVector& pointA, axisVector& pointB) {
	pointA.x -= pointB.x;
	pointA.y -= pointB.y;
	return pointA;
}

axisVector operator *=(axisVector& pointA, axisVector& pointB) {
	pointA.x *= pointB.x;
	pointA.y *= pointB.y;
	return pointA;
}

axisVector operator /=(axisVector& pointA, axisVector& pointB) {
	pointA.x /= pointB.x;
	pointA.y /= pointB.y;
	return pointA;
}

axisVector operator +=(axisVector& point, float val) {
	point.x += val;
	point.y += val;
	return point;
}
axisVector operator -=(axisVector& point, float val) {
	point.x -= val;
	point.y -= val;
	return point;
}

axisVector operator *=(axisVector& point, float val) {
	point.x *= val;
	point.y *= val;
	return point;
}

axisVector operator /(axisVector& point, float val) {
	point.x /= val;
	point.y /= val;
	return point;
}


double normalize(axisVector pointA, axisVector pointB) {
	return (double)pointA.x * pointB.x + pointA.y * pointB.y;
}


float angleAxisTan(axisVector v1, axisVector v2) {
	return atan2f((v2.y - v1.y), (v1.x - v2.x)) * 180.0 / PI;

}

float distAxis(axisVector v1, axisVector v2) {
	return sqrt((v2.x - v1.x) * (v2.x - v1.x) + (v2.y - v1.y) * (v2.y - v1.y));
}