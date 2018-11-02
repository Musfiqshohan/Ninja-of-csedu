#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include<time.h>
#include<stdio.h>
#include<string>

//#include "scoreboard.h"

using namespace std;
using namespace sf;

//RenderWindow window(VideoMode(800, 600), "The Game!");

String sentenceh;
Font fonth;
Text texth1(sentenceh, fonth, 40);

void high_scores(string name, int score)
{

	char str[100];
	
	strcpy(str, name.c_str());

	window.setFramerateLimit(50);
	
	FILE *fp;

	char *input_file = "highscore.txt";
	fp = fopen(input_file, "a");

	fprintf(fp, "%d %s \n", score, str);
	fclose(fp);
	scoreboard_func(window);

}

void savehigh_func(RenderWindow &window,int count)
{
	Texture bk;
	Sprite bk2;

	bk.loadFromFile("scoreboard.png");
	bk2.setTexture(bk);

	String high_text;
	Clock high_clock;
	int high_flag = 0;
	fonth.loadFromFile("naruto.ttf");
	texth1.setStyle(Text::Bold);
	

	


	
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


			case Event::TextEntered:
				if (e.text.unicode >= 32 && e.text.unicode <= 126)
					high_text += (char)e.text.unicode;
				else if (e.text.unicode == 8 && high_text.getSize() > 0)
					high_text.erase(high_text.getSize() - 1, high_text.getSize());

				texth1.setString(high_text);
				break;

			}
		}
		window.draw(bk2);

		if (Keyboard::isKeyPressed(Keyboard::Return))
		{
			high_scores(high_text, count);
			return;
			
		}
		


		window.draw(texth1);
		window.display();
		window.clear();
	}

	
}