#include <SFML/Graphics.hpp>
#include<time.h>
#include<iostream>
#include<stdio.h>
#include<string>
#include<String>
#include<SFML/Audio.hpp>
using namespace std;
using namespace sf;
RenderWindow window(VideoMode(1200, 600), "The Game!");

#include "scoreboard.h"
#include "help.h"
#include "credittt.h"
#include "savehigh.h"

#include "level_menu.h"
#include "mainmenu.h"

//String sentence;




void main()
{
	int y = 0, l1 = 0, l2 = 0, c = 0, s = 0;
	window.setFramerateLimit(50);
	window.setKeyRepeatEnabled(false);



	main_menu(window);


}