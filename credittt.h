#include <SFML/Graphics.hpp>
#include<time.h>
#include<iostream>
#include <SFML/Graphics.hpp>
#include<time.h>
#include<iostream>
#include<stdio.h>
#include<string>



using namespace std;
using namespace sf;


Event main_event_3;
//RenderWindow window(VideoMode(1200, 600), "The Game!");




void creditt(RenderWindow &window)
{
	Texture credittex,pic;
	Sprite credit,pici;

	Text credit1, creditm, credit3, credit4, credit5, credit6, credit7, credit8, credit9, credit10, credit11, credit12, credit13, credit14;
	Font m, n, o, p, q, r, s, t, u, v, w, x, y, z;


	credittex.loadFromFile("credit_board2.jpg");
	credit.setTexture(credittex);
	pic.loadFromFile("pic.jpg");
	pici.setTexture(pic);

	credit.setPosition(0, 0);

	q.loadFromFile("font.TTF");
	credit5.setColor(Color::Red);
	credit5.setPosition(170, 240);
	credit5.setString("Special thanks to our honourable teachers:");
	credit5.setCharacterSize(35);
	credit5.setFont(q);

	m.loadFromFile("font.TTF");
	credit1.setColor(Color::Black);
	credit1.setPosition(170, 290);
	credit1.setString("Asma Enayet,Lecturer,Department of CSEDU");
	credit1.setCharacterSize(20);
	credit1.setFont(m);

	n.loadFromFile("font.TTF");
	creditm.setColor(Color::Black);
	creditm.setPosition(170, 320);
	creditm.setString("Mr. Hasnain Heickal,Lecturer,Department of CSEDU");
	creditm.setCharacterSize(20);
	creditm.setFont(n);


	o.loadFromFile("font.TTF");
	credit3.setColor(Color::Black);
	credit3.setPosition(170, 350);
	credit3.setString("Iffat Anjum,Lecturer,Department of CSEDU");
	credit3.setCharacterSize(20);
	credit3.setFont(o);


	p.loadFromFile("font.TTF");
	credit4.setColor(Color::Black);
	credit4.setPosition(170, 380);
	credit4.setString("Mrs. Ismat Rahman,Assistant Professor,Department of CSEDU");
	credit4.setCharacterSize(20);
	credit4.setFont(p);


	r.loadFromFile("font.TTF");
	credit6.setColor(Color::Black);
	credit6.setPosition(170, 410);
	credit6.setString("Mr. Mahmood Jasim,Lecturer,Department of CSEDU");
	credit6.setCharacterSize(20);
	credit6.setFont(r);


	s.loadFromFile("font.TTF");
	credit7.setColor(Color::Black);
	credit7.setPosition(170, 440);
	credit7.setString("Dr. Moinul Islam Zaber,Assistant Professor,Department of CSEDU");
	credit7.setCharacterSize(20);
	credit7.setFont(s);


	t.loadFromFile("font.TTF");
	credit8.setColor(Color::Black);
	credit8.setPosition(170, 470);
	credit8.setString("Mr. Md. Shiplu Hawlader,Lecturer,Department of CSEDU");
	credit8.setCharacterSize(20);
	credit8.setFont(t);

	z.loadFromFile("font.TTF");
	credit14.setColor(Color::Black);
	credit14.setPosition(170, 500);
	credit14.setString("Tamal Adhikary,Lecturer,Department of CSEDU");
	credit14.setCharacterSize(20);
	credit14.setFont(z);

	u.loadFromFile("font.TTF");
	credit9.setColor(Color::Red);
	credit9.setPosition(500, 40);
	credit9.setString("CREDITS");
	credit9.setCharacterSize(35);
	credit9.setFont(u);

	v.loadFromFile("font.TTF");
	credit10.setColor(Color::Black);
	credit10.setPosition(170, 150);
	credit10.setString("Md. Musfiqur Rahman");
	credit10.setCharacterSize(20);
	credit10.setFont(v);

	w.loadFromFile("font.TTF");
	credit11.setColor(Color::Black);
	credit11.setPosition(170, 180);
	credit11.setString("Roll: 05");
	credit11.setCharacterSize(20);
	credit11.setFont(w);

	pici.setPosition((170 + 780) / 2-30 , 105);

	x.loadFromFile("font.TTF");
	credit12.setColor(Color::Black);
	credit12.setPosition(780, 150);
	credit12.setString("Fairuz Nawer Meem");
	credit12.setCharacterSize(20);
	credit12.setFont(x);

	y.loadFromFile("font.TTF");
	credit13.setColor(Color::Black);
	credit13.setPosition(780, 180);
	credit13.setString("Roll: 17");
	credit13.setCharacterSize(20);
	credit13.setFont(y);




	window.setFramerateLimit(24 + 6);
	int i = 0;
	Clock faifai;
	faifai.restart();
	while (faifai.getElapsedTime().asMilliseconds() < 250);
	while (window.isOpen())
	{
		while (window.pollEvent(main_event_3))
		{
			if (main_event_3.type == sf::Event::Closed)window.close();
		}
		//i++;



		window.clear();
		window.draw(credit);
		window.draw(pici);
		window.draw(credit1);
		window.draw(creditm);
		window.draw(credit3);
		window.draw(credit4);
		window.draw(credit5);
		window.draw(credit6);
		window.draw(credit7);
		window.draw(credit8);
		window.draw(credit9);
		window.draw(credit10);
		window.draw(credit11);
		window.draw(credit12);
		window.draw(credit13);
		window.draw(credit14);
		window.display();

		if (Keyboard::isKeyPressed(Keyboard::Escape))
			return;
	}

}