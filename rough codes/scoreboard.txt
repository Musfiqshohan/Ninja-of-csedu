#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include<time.h>
#include<stdio.h>
#include<string>


using namespace std;
using namespace sf;



String sentenceb;
Font fontb;
Text textt(sentenceb, fontb, 40);


struct Player{
	int score;
	char name[100];
};

void high_scores()
{

	window.setFramerateLimit(50);

	Player player[100];
	int score;
	char name[100];
	FILE *fp;

	char *input_file = "highscore.txt";

	int i = 0, j;
	fp = fopen(input_file, "r");
	
	
	while (fscanf(fp,"%d %s", &score, &name) == 2)
	{
		player[i].score = score;
		strcpy(player[i].name, name);
		i++;
	}

	fclose(fp);
	int n = i;
	
	for (i = 0; i<n - 1; i++)  //// new code of highscore written by me
	{
		for (j = 0; j<n - i - 1; j++)
		{
			if (player[j].score>player[j + 1].score)
			{
				Player temp = player[j];
				player[j] = player[j + 1];
				player[j + 1] = temp;
			}
		}

	}

	for (i = n-1; i >=0; i--) printf("%d\n", player[i].score);

	

	textt.setString("HIGH SCORES");
	textt.setPosition(500, 50);
	window.draw(textt);

	j = 0;

	for (i = n-1 ; i >=n-1-5; i--)
	{
		int count1 = player[i].score;

		string str;
		while (count1 > 0)
		{
			int a;
			a = count1 % 10;
			count1 = count1 / 10;
			a = a + 48;
			char b = a;
			str = str + b;
		}

		reverse(str.begin(), str.end());
		textt.setString(player[i].name);
		textt.setPosition(400, 200 + (j) * 80);
		window.draw(textt);

		textt.setString(str);
		textt.setPosition(800, 200 + (j) * 80);
		window.draw(textt);
		j++;
	}

}

void scoreboard_func(RenderWindow & window)
{
	Texture bk;
	Sprite bk2;
	Clock scoreboard_clock;
	scoreboard_clock.restart();
	bk.loadFromFile("scoreboard.png");
	bk2.setTexture(bk);

	String high_text;
	Clock high_clock;
	int count = 29, high_flag = 0;
	fontb.loadFromFile("naruto.ttf");
	textt.setStyle(Text::Bold);


	Music music3;

	if (!music3.openFromFile("music3.ogg"));
	cout << "cant open music" << endl;


	music3.play();
	music3.setVolume(30);
	
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

		window.draw(bk2);
		cout << scoreboard_clock.getElapsedTime().asSeconds() << endl;
		//if (scoreboard_clock.getElapsedTime().asSeconds()<5)
			high_scores();


			if (Keyboard::isKeyPressed(Keyboard::Escape))
				return;

		window.draw(textt);
		window.display();
		window.clear();
	}

}