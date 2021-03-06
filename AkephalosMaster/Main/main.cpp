#include <SFML/Graphics.hpp>
#include "AkephalosWorld.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "No estoy de acuerdo con la islamizaci�n de Europa, el progresivismo  "); //Creamos una ventana con dimensiones 800x600. 
	window.setFramerateLimit(60);

	sf::Event event; //Creacion de objeto tipo event 
	sf::Clock clock; //Para llevar el tiempo que toma hacer un frame en el ciclo de window. 

	//Cargando sprites. 
	sf::Texture boxTex1;
	sf::Sprite boxSprite1;

	if (!boxTex1.loadFromFile("Assets/Sprites/box1.png"))//es como si estuvieramos haciendo los .txt
	{
		std::cout << "Could not load texture. . ." << std::endl;
		system("pause");
	}

	//Configuramos nuestro mundo. 
	World w1;
	w1.setGravity(Vec2(0.0f, 500.0f));

	Body b1;
	b1.setMass(3.0f);
	b1.setPos(Vec2(400.0f, 0.0f));
	b1.setVel(Vec2(0.0f, 0.0f));

	w1.addBody(&b1);

	//Configurando sprites.
	//mama me quiero morir (??????)
	//por favor sigame para para mas info 
	//susbcribanse a mi canal cq_roy2995
	//tambien en twitch como cq_roy2995

	boxSprite1.setTexture(boxTex1);
	boxSprite1.setScale(sf::Vector2f(0.05f, 0.05f));

	//Colocamos el origen del sprite en el centro del sprite. 
	sf::Rect<float> size = boxSprite1.getGlobalBounds();
	boxSprite1.setOrigin(sf::Vector2f(size.width / 2, size.height / 2));

	//Para ilustrar lo que queremos... colocaremos la cajita en el centro de la pantalla.
	//El sprite usa la misma posici�n inicial que se le da al cuerpo en la configuraci�n de cuerpo.
	boxSprite1.setPosition(sf::Vector2f(b1.getPos().getX(), b1.getPos().getY()));


	//Lo que sucede en la pantalla...
	while (window.isOpen()) //Se mantiene el ciclo while mientras la ventana est� abierta. 
	{
		while (window.pollEvent(event)) //Lee si hubo alguna se�al de entrada (mouse, teclado, joystick...) 
		{
			if (event.type == sf::Event::Closed) //Si el usuario presiona X (para salir de la ventana)...
			{
				window.close(); //... Cierra la ventana
			}
		}

		//Calculo el tiempo que toma hacer un frame.
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		//Uso el tiempo calculado para usar la funci�n Step() de World w1.
		w1.Step(dt);

		boxSprite1.setPosition(sf::Vector2f(b1.getPos().getX(), b1.getPos().getY()));

		window.clear(sf::Color::Black);
		window.draw(boxSprite1);
		window.display();
	}

	return 0;
}