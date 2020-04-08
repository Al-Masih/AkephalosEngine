#include "AkephalosBody.h"

struct World //Aca se hacen todos los trabajos necesarios para la simulacion.
{
	//Cnstruccion, todo el SUNTRACS.
	World() : gravity(Vec2(0.0f, 9.81f)) {} //Bob el constructor defecto
	World(Vec2 gravity) : gravity(gravity) {}

	//Gravedad gravitacional gravitatoria gravitatoriense
	void setGravity(Vec2 v);

	//Creacion del cuerpo
	void addBody(Body* b);

	//Vivimos en una simulacion
	void Step(float dt);

private:
	Vec2 gravity;
	std::vector<Body*> bodies;
};
