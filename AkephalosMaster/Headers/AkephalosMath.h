#include <iostream>
#include <math.h>
#include <vector>

struct Vec2
{
public:
	//Construccion
	Vec2() : x(0.0f), y(0.0f) {} //Bob el constructor defecto
	Vec2(float x, float y) : x(x), y(y) {}

	//Meterle valores a los componentes de vectores
	void Set(float x_, float y_);

	//Info-datos del vector 
	float Length();
	float LengthSquared();
	void Display();

	//Pedir los datos del vector
	float getX();
	float getY();

	//math con vectores
	void operator += (Vec2 v);
	void operator -= (Vec2 v);
	float Dot(Vec2 a, Vec2 b);
	float Cross(Vec2 a, Vec2 b);

private:
	float x, y;
};
