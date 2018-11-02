#include <SFML/Graphics.hpp>
#include<time.h>
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
using namespace sf;

int max_count = 0;

Text newgame, levels, help, scoreboard, credit, quit;
Font a, b, c, d, e, f;




void main_menu(RenderWindow &window)
{
	Texture fairuztex;
	Sprite fairuz;


	

	fairuztex.loadFromFile("menu.jpg");
	fairuz.setTexture(fairuztex);

	fairuz.setPosition(0, 0);

	a.loadFromFile("font.TTF");
	newgame.setColor(Color::Black);
	newgame.setPosition(100, 100);
	newgame.setString("NEW GAME");
	newgame.setCharacterSize(40);
	newgame.setFont(a);


	b.loadFromFile("font.TTF");
	levels.setColor(Color::Black);
	levels.setPosition(100, 175);
	levels.setString("LEVELS");
	levels.setCharacterSize(40);
	levels.setFont(b);


	c.loadFromFile("font.TTF");
	help.setColor(Color::Black);
	help.setPosition(100, 250);
	help.setString("HELP");
	help.setCharacterSize(40);
	help.setFont(c);


	d.loadFromFile("font.TTF");
	scoreboard.setColor(Color::Black);
	scoreboard.setPosition(100, 325);
	scoreboard.setString("SCOREBOARD");
	scoreboard.setCharacterSize(40);
	scoreboard.setFont(d);


	e.loadFromFile("font.TTF");
	credit.setColor(Color::Black);
	credit.setPosition(100, 400);
	credit.setString("CREDIT");
	credit.setCharacterSize(40);
	credit.setFont(e);


	f.loadFromFile("font.TTF");
	quit.setFont(f);
	quit.setColor(Color::Black);
	quit.setPosition(100, 475);
	quit.setString("QUIT");
	quit.setCharacterSize(40);



	//music3.play();
	int i = 0;
	while (window.isOpen())
	{

		while (window.pollEvent(main_event_1))
		{
			if (main_event_1.type == sf::Event::Closed)window.close();
		}
		//i++;

		if (newgame.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
		{
			//cout << newgame.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y);
			newgame.setColor(sf::Color::Cyan);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
			
				if (level1(window, max_count))
					level2(window,max_count);
			
			}


		}
		else
			newgame.setColor(sf::Color::Black);

		if (levels.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
		{
			//cout << newgame.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y);
			levels.setColor(sf::Color::Cyan);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				level_menu(window,max_count);

		}
		else
			levels.setColor(sf::Color::Black);

		if (help.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
		{
			//cout << newgame.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y);
			help.setColor(sf::Color::Cyan);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				help_func(window);
		}
		else
			help.setColor(sf::Color::Black);

		if (scoreboard.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
		{
			//cout << newgame.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y);
			scoreboard.setColor(sf::Color::Cyan);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				//music3.pause();
				scoreboard_func(window);
				//music3.play();

			}
		}
		else
			scoreboard.setColor(sf::Color::Black);

		if (credit.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
		{
			//cout << newgame.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y);
			credit.setColor(sf::Color::Cyan);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				creditt(window);
		}
		else
			credit.setColor(sf::Color::Black);

		if (quit.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
		{
			//cout << newgame.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y);
			quit.setColor(sf::Color::Cyan);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				window.close();
		}
		else
			quit.setColor(sf::Color::Black);


		//i %= 30;
		window.clear();
		window.draw(fairuz);
		window.draw(newgame);
		window.draw(levels);
		window.draw(help);
		window.draw(scoreboard);
		window.draw(credit);
		window.draw(quit);
		window.display();
	}
	//return 0;
}