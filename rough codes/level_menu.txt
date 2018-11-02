#include <SFML/Graphics.hpp>
#include<time.h>
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
using namespace sf;

#include "1st_year.h"
#include "2nd_year.h"

//#include "scoreboard.h"
//#include "savehigh.h"

Event main_event_1;
Text levelt1, year1, levelt2, year2;
Font g, h, i, j, k, l;
void level_menu(RenderWindow &window,int &max_count)
{
	Texture shohantex;
	Sprite shohan;

	shohantex.loadFromFile("ninjachup.png");
	shohan.setTexture(shohantex);

	shohan.setPosition(0, 0);

	g.loadFromFile("font.TTF");
	levelt1.setColor(Color::Black);
	levelt1.setPosition(570, 100);
	levelt1.setString("LEVEL-1:");
	levelt1.setCharacterSize(40);
	levelt1.setFont(g);


	h.loadFromFile("font.TTF");
	year1.setColor(Color::Red);
	year1.setPosition(620, 175);
	year1.setString("1st Year");
	year1.setCharacterSize(40);
	year1.setFont(h);


	i.loadFromFile("font.TTF");
	levelt2.setColor(Color::Black);
	levelt2.setPosition(570, 250);
	levelt2.setString("LEVEL-2:");
	levelt2.setCharacterSize(40);
	levelt2.setFont(i);


	j.loadFromFile("font.TTF");
	year2.setColor(Color::Red);
	year2.setPosition(620, 325);
	year2.setString("2nd Year");
	year2.setCharacterSize(40);
	year2.setFont(j);



	window.setFramerateLimit(24 + 6);
	int i = 0;
	Clock faifai;
	faifai.restart();
	while (faifai.getElapsedTime().asMilliseconds() < 250);
	while (window.isOpen())
	{
		while (window.pollEvent(main_event_1))
		{
			if (main_event_1.type == sf::Event::Closed)window.close();
		}
		//i++;



		if (year1.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
		{
			//cout << levelt1.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y);
			year1.setColor(sf::Color::Cyan);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (level1(window,max_count))
				{
					level2(window,max_count);
					return;
				}
				else
					return;
				//else
					//savehigh_func(window, 1999);
			}
		}
		else
			year1.setColor(sf::Color::Red);



		if (year2.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y))
		{
			//cout << levelt1.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y);
			year2.setColor(sf::Color::Cyan);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				level2(window,max_count);
				return;
			}
		}
		else
			year2.setColor(sf::Color::Red);


		if (Keyboard::isKeyPressed(Keyboard::Escape))
			return ;

		//i %= 30;
		window.clear();
		window.draw(shohan);
		window.draw(levelt1);
		window.draw(year1);
		window.draw(levelt2);
		window.draw(year2);

		window.display();
	}

}