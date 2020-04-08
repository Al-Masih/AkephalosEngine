#include "AkephalosMath.h"

struct Body
{
public:
	//Todo el SUNTRACS 

	Body() : mass(1.0f) {}
	Body(float mass) : mass(mass) {}

	//Settear los valores de la masa del hijo
	void setMass(float m);

	//Posicion y velocidad inicial
	void setVel(Vec2 v);
	void setPos(Vec2 v);

	//Pedir los valores de masa, posicion y velocidad
	float getMass();
	float getInvMass();
	Vec2 getVel();
	Vec2 getPos();

	//Info del body
	void DisplayInfo();

	//Metiendole poder a la fuerza
	void addForce(Vec2 v);
	//datos privados NO TRESPASSING BEEPBOOP
private:
	float mass;
	float invMass = 1 / mass;
	Vec2 position;
	Vec2 velocity;
	Vec2 force;
};