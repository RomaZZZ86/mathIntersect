#include"../include/auxiliary.h"



void swap(float& a, float& b) {
	a = b;
	b = a;
}


float down(const float x) {
	return (x > 0 ? 1 : x == 0 ? 0 : -1);
	
}


inline float area(axisVector a, axisVector b, axisVector c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool between(float a, float b, double c) {
	return std::min(a, b) <= c + EPSILON && c <= std::max(a, b) + EPSILON;
}

inline bool intersect_1(float a, float  b, float c, float d) {
	if (a > b)  swap(a, b);
	if (c > d)  swap(c, d);
	return std::max(a, c) <= std::min(b, d);
}
inline int det(int a, int b, int c, int d) {
	return a * d - b * c;
}




bool intersect(axisVector a, axisVector b, axisVector c, axisVector d) {
	int A1 = a.y - b.y, B1 = b.x - a.x, C1 = -A1 * a.x - B1 * a.y;
	int A2 = c.y - d.y, B2 = d.x - c.x, C2 = -A2 * c.x - B2 * c.y;
	int zn = det(A1, B1, A2, B2);
	//std::cout <<"DET" << zn << "\n";
	if (zn != 0) {
		double x = -det(C1, B1, C2, B2) * 1. / zn;
		double y = -det(A1, C1, A2, C2) * 1. / zn;
		return between(a.x, b.x, x) && between(a.y, b.y, y)
			&& between(c.x, d.x, x) && between(c.y, d.y, y);
	}
	else
		return det(A1, C1, A2, C2) == 0 && det(B1, C1, B2, C2) == 0
		&& intersect_1(a.x, b.x, c.x, d.x)
		&& intersect_1(a.y, b.y, c.y, d.y);
}

int random(int min, int max) {
	return min + rand() % (max - min);
}

std::string format(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	std::vector<char> v(1024);
	while (true)
	{
		va_list args2;
		va_copy(args2, args);
		int res = vsnprintf(v.data(), v.size(), fmt, args2);
		if ((res >= 0) && (res < static_cast<int>(v.size())))
		{
			va_end(args);
			va_end(args2);
			return std::string(v.data());
		}
		size_t size;
		if (res < 0)
			size = v.size() * 2;
		else
			size = static_cast<size_t>(res) + 1;
		v.clear();
		v.resize(size);
		va_end(args2);
	}
}

