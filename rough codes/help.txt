#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include<time.h>
#include<stdio.h>
#include<string>


using namespace std;
using namespace sf;




void help_func(RenderWindow &window)
{
	Texture bl;
	Sprite block;
	bl.loadFromFile("demo2.png");
	block.setTexture(bl);


	while (window.isOpen())
	{

		Event e;
		while (window.pollEvent(e))
		{

			switch (e.type)
			{
			case Event::Closed:
				window.close();
				break;

			}
		}



		if (Keyboard::isKeyPressed(Keyboard::Escape))
			return;

		window.draw(block);
		window.display();
		window.clear();
	}


}