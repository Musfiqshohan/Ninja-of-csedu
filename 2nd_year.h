#include <SFML/Graphics.hpp>
#include<time.h>
#include<iostream>
#include<stdio.h>
#include<string>
//#include "savehigh.h"


using namespace std;
using namespace sf;
//////////////////////////////level1 2/////////////////////////////////////

int livesxx = 5, flagxx = 0, mxdistance, mj, mmove = 0, sup1ff = 0, sup1fff = 0, flags1 = 0, ups1 = 0, sup0ff = 0, sup0fff = 0, mummy_attack_count = 0,
devil_livesxx = 3, superpowercount = 0, swordcount = 0, javacount[5], transcount[13], gm_overx=0;
int java_distance[10], tdistance[14], t1distance[14], train_distance[5];
Sprite  AnifeImgae[5], playerImage2, ninja_starx[60], sobstaclexx[20], transistor[12], java_Image[8], fire_ball2[4], pausedx, sgame_overx, icpc, mummy, hit_imagex, strike_image, sup1f, sup0f, sword;
String sentencexx, count_beginxx;

Font Font2x;
Text textxx(sentencexx, Font2x, 40);
Text textxx_begin(count_beginxx, Font2x, 40);   ///declarations
Clock game_over_clock2;
bool isCollide2(Sprite  s1, Sprite s2)
{
	return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
}
int coin_sectx[50];
int txx[20];
void knife2()
{

	AnifeImgae[0].setPosition(50, 300);
	AnifeImgae[1].setPosition(55, 320);
	AnifeImgae[2].setPosition(40, 290);
	AnifeImgae[3].setPosition(45, 330);
	AnifeImgae[4].setPosition(60, 340);
	printf("doom\n");
}


int  attack2(Sprite star)
{
	int cj;
	for (cj = 0; cj <= 4; cj++)
	{
		if (isCollide2(java_Image[cj], star))
		{
			javacount[cj]++;
			if (javacount[cj] >= 2)
				java_distance[cj] = -1000;
			return 1;
		}

	}

	for (cj = 0; cj <= 11; cj++)
	{
		if (isCollide2(transistor[cj], star))
		{
			transcount[cj]++;
			if (transcount[cj] >= 2)
				tdistance[cj] = -1000;

			return 1;
		}

	}

	for (cj = 0; cj < 16; cj++)
	{
		if (isCollide2(sobstaclexx[cj], star))
			return 1;

	}

	if (isCollide2(mummy, star)){
		strike_image.setPosition(mummy.getPosition().x, mummy.getPosition().y);
		window.draw(strike_image);
		mummy_attack_count++;
		if (mummy_attack_count>15 && devil_livesxx == 1) devil_livesxx--;
		//cout << mummy_attack_count << endl;
		return 1;
	}

	return 0;

}

void print_score2(int count4, int count5)
{
	textxx.setCharacterSize(24);
	int countx = count4;


	string str;

	while (countx > 0)
	{
		int a;
		a = countx % 10;
		countx = countx / 10;
		a = a + 48;
		char b = a;
		str = str + b;
	}

	reverse(str.begin(), str.end());

	if (gm_over == 0){
		sentence += str;
		if (count4 == 0) sentencexx += '0';
		gm_over = 1;
	}

	str = sentencexx + str;
	//cout << str << endl;
	textxx.setString(str);
	textxx.setPosition(450, 10);
	window.draw(textxx);

	str = ' ';
	countx = count5;
	while (countx > 0)
	{
		int a;
		a = countx % 10;
		countx = countx / 10;
		a = a + 48;
		char b = a;
		str = str + b;
	}

	reverse(str.begin(), str.end());

	str = "You have only  " + str + "  knives";
	//cout << str << endl;
	textxx.setString(str);
	textxx.setPosition(450, 40);
	window.draw(textxx);
	textxx.setCharacterSize(40);

}

int county = 0,flga=0;
void GAME_OVER2(int count)
{


	county = count;
	if (flga == 0)
	{
		game_over_clock2.restart();
		flga = 1;
	}

	string str;
	str = ' ';
	while (county > 0)
	{
		int a;
		a = county % 10;
		county = county / 10;
		a = a + 48;
		char b = a;
		str = str + b;

	}

	reverse(str.begin(), str.end());


	if (gm_overx == 0){
		//sentencexx += str;
		if (count == 0) sentencexx += '0';
		gm_overx = 1;
	}

	str = sentencexx + str;
	textxx.setString(str);
	textxx.setPosition(450, 70);
	window.draw(textxx);

	if (mummy.getPosition().y <= 600){
		textxx.setString("Re Admission :(");
		textxx.setPosition(450, 150);
		window.draw(textxx);
	}

	
}


void level2(RenderWindow &window, int &max_count)
{

	window.setKeyRepeatEnabled(false);
	count1 = 0;
	count_knife = 60;
	int i, xod = 2000, upward = 200, j, s, posx = 0, posy = 0, flag2 = 1, up = 0, fl = 0, ninja_starxflag = 0, total_trans = 11, life_flag = 0, sobstaclexx_index = 0,
		nsf = 0, ns = 0, star_num = 60, js = 0, ts = 0, flagjump = 0, player_height = 300, jump_flag = 0, Anife_flag = 0, hole_flag = 0, holedex = 6
		, flag3 = 1, flag4 = 0, up1 = 0;

	enum Task  { Run, Jump, Slide };
	int distance[16];
	distance[0] = 0;
	int count = max_count;

	Music music2;

	if (!music2.openFromFile("music2.ogg"));
	cout << "cant open music" << endl;



	//////Positioning everything on the co ordinates///////
	j = 2;
	for (i = 1; i < 16; i++)
	{
		if (i <= 10)
		{
			distance[i] = distance[i - 1] + 1100 + rand() % 100;
			train_distance[i] = distance[i - 1] + 1100 + rand() % 100;
		}

		else
		{
			distance[i] = distance[i - 1] + 1600 + rand() % 100;
			train_distance[i] = distance[i - 1] + 1600 + rand() % 100;
		}

		if (i == 1)

			java_distance[0] = distance[i] - 300;

		if (i == 2)
		{
			java_distance[1] = distance[i] - 400;
			java_distance[2] = distance[i] - 200;
		}

		else if (i == 3)
		{
			tdistance[0] = distance[i] - 200;
			t1distance[0] = distance[i] - 200;
		}
		else if (i == 4)
		{
			tdistance[1] = distance[i] - 200;
			t1distance[1] = distance[i] - 200;

		}


		if (i == 7 || i == 8)
		{
			tdistance[j] = distance[i] - 300;
			t1distance[j] = distance[i] - 300;
			j++;
			tdistance[j] = distance[i] - 100;
			t1distance[j] = distance[i] - 100;
			j++;


		}


		if (i == 9)
		{
			java_distance[3] = distance[i] + 700;
			java_distance[4] = distance[i] + 900;

		}

		if (i == 11 || i == 12)
		{
			tdistance[j] = distance[i] - 400;
			t1distance[j] = distance[i] - 400;
			j++;
			tdistance[j] = distance[i] - 100;
			t1distance[j] = distance[i] - 100;
			j++;

		}


		if (i == 13)
		{
			tdistance[j] = distance[i] - 400;
			t1distance[j] = distance[i] - 400;
			j++;
			tdistance[j] = distance[i] - 100;
			t1distance[j] = distance[i] - 100;
			j++;
		}

		if (i == 14)
		{
			mxdistance = distance[i] - 100;
		}


	}




	Clock clock, clock2, mummy_clock, begin_clock;

	float timer = 0, delay = 0.1, timer2 = 0, mummy_timer = 0;
	float frameCounter = 0, switchFrame = 100, frameSpeed = 500;


	window.setFramerateLimit(10);
	Vector2i source(0, Run);

	Texture pTexture, bart, tground, tobstacle, game_over, pcoins, b1Texture, java_Texture, ic, bm, paus, pstar, fire2, swrd, dheart, knifetx, strike, sp1f, s1, sp0f, s2, trantexture, mball, heart, mumy, tball, trainTexture, Anife, Aknife_flag, hole, hit;
	Sprite bars, sground, b1Image, b2Image, Aknife_flagImage, hole_image, boom, player_heart, knife_effect, mummy_ball, superpower1, devil_heart;
	Sprite coins[100], trainImage[2], trans_ball[12];


	if (!b1Texture.loadFromFile("bg.png"))
		cout << "Error could not load player image" << endl;

	b1Image.setTexture(b1Texture);
	b2Image.setTexture(b1Texture);

	knifetx.loadFromFile("knife_effct.png");
	knife_effect.setTexture(knifetx);

	paus.loadFromFile("Paused.jpg");
	pausedx.setTexture(paus);

	bm.loadFromFile("boom.png");
	boom.setTexture(bm);

	Aknife_flag.loadFromFile("knife_flag.png");
	Aknife_flagImage.setTexture(Aknife_flag);
	Aknife_flagImage.setPosition(distance[10], 252);

	hole.loadFromFile("black_hole.png");
	hole_image.setTexture(hole);

	dheart.loadFromFile("devil_heart.png");
	devil_heart.setTexture(dheart);

	strike.loadFromFile("strike.png");
	strike_image.setTexture(strike);

	sp0f.loadFromFile("sp0.png");
	sup0f.setTexture(sp0f);
	sup0f.setPosition(50, 10000);

	ic.loadFromFile("icpc.png");
	icpc.setTexture(ic);

	swrd.loadFromFile("shieldsword.png");
	sword.setTexture(swrd);

	sp1f.loadFromFile("sp1.png");
	sup1f.setTexture(sp1f);

	s1.loadFromFile("superpower1.png");
	superpower1.setTexture(s1);



	mumy.loadFromFile("mummy.png");
	mummy.setTexture(mumy);
	mummy.setPosition(-100, -100);

	mball.loadFromFile("mummy_ball.png");
	mummy_ball.setTexture(mball);

	hit.loadFromFile("got_hit.png");
	hit_imagex.setTexture(hit);

	heart.loadFromFile("player_heart.png");
	player_heart.setTexture(heart);

	trainTexture.loadFromFile("train.png");
	for (i = 0; i < 2; i++)
		trainImage[i].setTexture(trainTexture);

	tball.loadFromFile("transistor ball.png");
	for (i = 0; i <= 11; i++)
		trans_ball[i].setTexture(tball);



	Anife.loadFromFile("angled knives.png");
	for (i = 0; i < 5; i++)

		AnifeImgae[i].setTexture(Anife);

	fire2.loadFromFile("fire_ball2.png");
	for (i = 0; i < 3; i++) fire_ball2[i].setTexture(fire2);

	java_Texture.loadFromFile("javax.png");
	for (i = 0; i < 8; i++)
		java_Image[i].setTexture(java_Texture);

	trantexture.loadFromFile("trransistors.png");
	for (i = 0; i <= 11; i++)
		transistor[i].setTexture(trantexture);




	pstar.loadFromFile("knife.png");
	for (i = 0; i < 60; i++)
	{
		ninja_starx[i].setTexture(pstar);
		ninja_starx[i].setPosition(550, -50);
	}


	b2Image.setPosition(800, 0);


	if (!pTexture.loadFromFile("xyz.png"))
		cout << "Error could not load player image" << endl;
	playerImage2.setTexture(pTexture);
	playerImage2.setPosition(50 + mmove, 300);

	game_over.loadFromFile("GAME_OVER.png");
	sgame_overx.setTexture(game_over);
	sgame_overx.setPosition(0, 0);
	tground.loadFromFile("ground.png");
	sground.setTexture(tground);



	tobstacle.loadFromFile("obstacle1-Copy - Copy.png");

	int t = 0;
	while (t < 16){
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				sobstaclexx[t].setTexture(tobstacle);
				sobstaclexx[t].setTextureRect(IntRect(4 + j * 194, 4 + i * 109, 195, 109));
				t++;
			}
		}
	}


	pcoins.loadFromFile("coin.png");
	for (i = 0; i < 50; i++)
		coins[i].setTexture(pcoins);



	Font2x.loadFromFile("naruto.ttf");


	text.setColor(Color(44, 127, 255));
	text.setStyle(Text::Bold);

	sentencexx = "Your score is:   ";


	long long int wait = 1;

	////THE REAL GAME START FROM HERE with rocking musics B)  /////
	music2.play();
	music2.setVolume(30);

	while (window.isOpen())
	{

		if (Keyboard::isKeyPressed(Keyboard::Escape))
			wait++;

		if (wait % 2 == 0)
		{
			pausedx.setPosition(500, 200);
			window.draw(pausedx);
			window.display();
			window.clear();
			if (Keyboard::isKeyPressed(Keyboard::BackSpace))
				return;
		}


		if (wait % 2 == 1){


			if (flagxx == 0){


				window.draw(b1Image);
				b1Image.move(-10, 0);

				window.draw(b2Image);
				b2Image.move(-10, 0);

				//////features///////
				///// blackhole////
				if (hole_flag == 0){
					hole_image.setPosition(xod + distance[holedex + 1] - 800, 210);
					window.draw(hole_image);
				}

				if (b1Image.getPosition().x + 800 < 0) b1Image.setPosition(800, 0);
				if (b2Image.getPosition().x + 800 < 0) b2Image.setPosition(800, 0);



				float time = clock.getElapsedTime().asMilliseconds();
				clock.restart();
				timer += time;

				timer2 = clock2.getElapsedTime().asMilliseconds();




				if (life_flag == 1 && timer2 > 500)
				{

					timer2 = 0;
					life_flag = 0;
					distance[sobstaclexx_index] = -1000;
					livesxx--;
					if (livesxx <= 0)
						life_flag = 1;
				}

				if (life_flag == 1)
				{


					if (livesxx <= 0)
					{

						if (flag3 == 1)
							up1 = up1 - 30;
						if (up1 <= -60) {
							flag4 = 1; flag3 = 0;
						}

						if (flag4 == 1)
							up1 = up1 + 50;

						hit_imagex.setPosition(playerImage2.getPosition().x, 220 + up1);
						window.draw(hit_imagex);
						
						GAME_OVER2(count);

						//if (livesxx == 0)
							//game_over_clock2.restart();

						cout << game_over_clock2.getElapsedTime().asSeconds() << endl;
						if (livesxx <= 0)
							if (game_over_clock2.getElapsedTime().asSeconds() > 3 && livesxx <= 0)
							{
								music2.stop();
								savehigh_func(window, count);
								return;


							}




						livesxx--;

					}
					else
					{
						hit_imagex.setPosition(playerImage2.getPosition().x - 20, playerImage2.getPosition().y - 10);
						window.draw(hit_imagex);
					}

				}


				player_heart.setTextureRect(IntRect(2, 2, livesxx * 65, 60));
				window.draw(player_heart);


				Event e;
				while (window.pollEvent(e))
				{

					switch (e.type)
					{
					case Event::Closed:
						window.close();
						break;
					case Event::KeyPressed:
						if (e.key.code == Keyboard::Up)
						{
							source.y = Jump;  j = 0;
						}
						else if (e.key.code == Keyboard::Down)
						{
							source.y = Slide; s = 0;
						}
						break;

					}
				}




				///JUMP////
				if (life_flag == 0)
				{


					if (source.y == Jump)
					{
						int  dif = 50;

						playerImage2.setTextureRect(IntRect(j * 135, 136, 135, 115));
						if (j == 0) playerImage2.setPosition(50 + mmove, player_height - dif * 1);
						else if (j == 1) playerImage2.setPosition(50 + mmove, player_height - dif * 2);
						else if (j == 2) playerImage2.setPosition(50 + mmove, player_height - dif * 3);
						else if (j == 3) playerImage2.setPosition(50 + mmove, player_height - dif * 2);
						else if (j == 4) playerImage2.setPosition(50 + mmove, player_height - dif * 1);
						else if (j == 5)
							playerImage2.setPosition(50 + mmove, player_height - dif * 0);
						xod -= 10;

						window.draw(playerImage2);
						j++;

						if (j >= 6)
						{

							source.x = 0;  source.y = Run;
						}



					}

					/////SLIDE//////
					else if (source.y == Slide)
					{
						playerImage2.move(0, 2);
						int x1;
						if (s == 0)
							x1 = 50;
						if (s == 0)
						{
							playerImage2.setTextureRect(IntRect(s * 145, 2 * 136, 145, 115));
							playerImage2.setPosition(x1 + mmove, playerImage2.getPosition().y - 20);
						}

						else if (s == 4 || s == 5)
						{
							playerImage2.setTextureRect(IntRect(s * 145, (2 * 136 + 30), 145, 80));
							playerImage2.setPosition(x1 + mmove, playerImage2.getPosition().y + 20);
						}


						else{
							playerImage2.setTextureRect(IntRect(s * 145, (2 * 136 + 55), 145, 60));
							playerImage2.setPosition(x1 + mmove, playerImage2.getPosition().y + 35);
						}

						xod -= 30;
						window.draw(playerImage2);
						s++;
						if (s >= 6)
						{
							source.x = 0;  source.y = Run;
						}
						playerImage2.move(0, -2);

					}
					/////RUN////
					else if (source.y == Run){
						source.x++;
						if (source.x >= 6)
							source.x = 0;

						playerImage2.setTextureRect(IntRect(source.x * 95, source.y, 95, 90));
						window.draw(playerImage2);


					}
					///RUN END////
				}

				////Obstacles moving ////
				if (timer > 50 && !life_flag)
				{
					xod -= 25;
					timer = 0;
				}

				int c = 0;
				for (t = 0; t < 16; t++)
				{
					if (t % 2 == 0)
						sobstaclexx[t].setPosition(xod + distance[t], 292);
					else
						sobstaclexx[t].setPosition(xod + distance[t], 220);
					window.draw(sobstaclexx[t]);

					for (i = 0; i < 3; i++)
					{
						if (t % 2 == 0)
							coins[c].setPosition(xod + distance[t] + i * 65, 220 + coin_sectx[c]);
						if (t % 2 == 1)
							coins[c].setPosition(xod + distance[t] + i * 65, 339 + coin_sectx[c]);

						window.draw(coins[c]);

						c++;

					}



				}
				sground.setPosition(0, 400);
				//if (sobstaclexx[15].getPosition().x + 196 <= 0)  xod = 600;



				//// Throwing Ninja star/////
				if (Keyboard::isKeyPressed(Keyboard::Space) && ns<60 && life_flag == 0)
				{
					count_knife--;
					ninja_starxflag = 1;
					nsf = 0;
					ninja_starx[ns].setPosition(playerImage2.getPosition().x, playerImage2.getPosition().y);
					ns++;


					if (ns > star_num) ninja_starxflag = 0;
				}


				for (i = 0; i < ns && ninja_starxflag == 1; i++)
				{

					if (ninja_starx[i].getPosition().x - playerImage2.getPosition().x < 20 && ninja_starx[i].getPosition().x>0 && ninja_starx[i].getPosition().y == playerImage2.getPosition().y)
					{

						knife_effect.setPosition(playerImage2.getPosition().x + 15, playerImage2.getPosition().y - 10);
						window.draw(knife_effect);
					}

					if (ninja_starx[ns - 1].getPosition().x <= 1000)
					{
						//ninja_starx[i].setTextureRect(IntRect(nsf * 60, 0, 60, 50));
						ninja_starx[i].move(40, 0);

						window.draw(ninja_starx[i]);
					}

				}


				///throwing super Anives////

				int knife1;
				Aknife_flagImage.setPosition(xod + distance[10] + 80, 150);
				if (isCollide2(playerImage2, Aknife_flagImage) == 1)
				{
					Anife_flag = 1;
					knife1 = 0;

				}



				if (Anife_flag == 1)
				{

					if (Keyboard::isKeyPressed(Keyboard::S))
					{
						knife1 = 1;
						knife2();
					}
					for (i = 0; i < 5 && knife1 == 1; i++)
					{

						AnifeImgae[i].move(50 - i * 5, 0);
						window.draw(AnifeImgae[i]);



						if (AnifeImgae[4].getPosition().x > 900)
							knife1 = 0;


					}

					for (i = 0; i < 5; i++)
					{
						if (AnifeImgae[i].getPosition().x > 900)
							AnifeImgae[i].setPosition(-20, -20);

					}


				}




				// java is Moving  and transistor also////
				for (i = 0; i <= 4; i++)
				{

					if (flag2 == 1)
						up = up - 30;
					if (up <= -60) flag2 = 0;

					if (flag2 == 0)
						up = up + 30;
					if (up >= 0) flag2 = 1;


					java_Image[i].setTextureRect(IntRect(js * 112 + 4, 4, 112, 162));

					java_Image[i].setPosition(xod + java_distance[i], 240);
					//java_Image[i].move(-80  * 20, 0);
					window.draw(java_Image[i]);


				}

				for (i = 0; i <= total_trans; i++)
				{
					transistor[i].setTextureRect(IntRect(ts * 112 + 4, 4, 112, 108));

					transistor[i].setPosition(xod + tdistance[i], 292);
					//transistor[i].move(-80 - i * 20, 0);
					window.draw(transistor[i]);


					if (transistor[i].getPosition().x > 0 && transistor[i].getPosition().x < 1200 + 50 || trans_ball[i].getPosition().x>0)
					{

						trans_ball[i].setPosition(xod + t1distance[i] - tx[i] * 20, 285);
						window.draw(trans_ball[i]);
						tx[i]++;
					}
				}
				js++;
				js = js % 4;
				ts++;
				ts = ts % 3;

				//if (mummy.getPosition().x - playerImage2.getPosition().x < 600)
				//mj = 1;



				////mummy from here////

				if (sobstaclexx[13].getPosition().x + 200 < 0 && sobstaclexx[13].getPosition().x + 200 > -50)
				{
					mummy_clock.restart();
					livesxx = 3;
				}

				if (sobstaclexx[13].getPosition().x + 200 < 0)
				{

					Anife_flag = 0;
					mummy_timer = mummy_clock.getElapsedTime().asMilliseconds();

					if (Keyboard::isKeyPressed(Keyboard::Right))
					{
						if (playerImage2.getPosition().x<400)
							mmove += 20;
					}

					if (Keyboard::isKeyPressed(Keyboard::Left))
					{
						if (playerImage2.getPosition().x>50)
							mmove += -20;

						if (playerImage2.getPosition().x < 50) playerImage2.setPosition(50, playerImage2.getPosition().y);

					}



					if (mummy_timer < 5000)
					{
						if (mummy_timer>4800 && mummy_timer<5000) mj = 1;

						mummy.setTextureRect(IntRect(109 * mj, 2, 109, 162));
						mummy.setPosition(1000, 230);
						mummy.move(-20, 0);
						mj++;
						mj = mj % 6;

					}
					// 1st rotation ans left right

					if (mummy_timer > 2000)
					{
						mummy_ball.move(-50, 0);
						window.draw(mummy_ball);
					}
				
					
						if (playerImage2.getPosition().x > mummy_ball.getPosition().x + 5
							&& playerImage2.getPosition().x < mummy_ball.getPosition().x + 90
							&& playerImage2.getPosition().y < mummy_ball.getPosition().y + 80){
							cout << "mummyball" << endl;
							life_flag = 1;
							clock2.restart();
							mummy_ball.setPosition(-100, -80);
						}
					

					if (mummy_timer > 1500 && mummy_timer < 2000)	mummy_ball.setPosition(mummy.getPosition().x - 40, mummy.getPosition().y+10);
					if (mummy_timer>6500 && mummy_timer < 6600) mummy_ball.setPosition(mummy.getPosition().x - 40, mummy.getPosition().y+10); //ball moving


					///mummy moving towards me
					if ((mummy_timer > 11000 && mummy_timer < 17000) || (mummy_timer>28000 && mummy_timer < 31000))
					{
						if (fabs(playerImage2.getPosition().x - mummy.getPosition().x) > 30)
							mummy.move(-20, 0);
					}


					///sword shield sign is coming and attacking the mummy//
					if (mummy_timer > 8000 && mummy_timer < 8500) sup0f.setPosition(1200, sground.getPosition().y - 80);
					if (mummy_timer > 8500)
					{
						sup0f.move(-20, 0);
						window.draw(sup0f);
						if (isCollide2(sup0f, playerImage2))
						{
							sup0f.setPosition(-100, -100);
							sup0ff = 1;
							sword.setPosition(playerImage2.getPosition().x + 50, playerImage2.getPosition().y - 100);


						}
					}

					if (sup0ff == 1)
					{

						if (Keyboard::isKeyPressed(Keyboard::S))
						{
							sup0fff = 1;
							sup0ff = 0;
						}

					}

					if (sup0fff == 1)
					{
						sword.move(50, 0);
						window.draw(sword);
					}


					if (isCollide2(sword, mummy) && mummy.getPosition().x < 1000)
						mummy.setPosition(sword.getPosition().x + 100, mummy.getPosition().y);

					if (sword.getPosition().x>1000) sword.setPosition(-888, 9999);


					////mummy is going back
					if (mummy_timer > 17000 && mummy_timer < 19000)
					{
						if (mummy.getPosition().x < 1000) mummy.move(30, 0);
					}

					///1st part done in 19 sec


					if (mummy_timer>18500 && mummy_timer < 19000)
					{
						for (i = 1; i < 3; i++)
						{
							fire_ball2[i - 1].setPosition(200 * i - 150, -300 * i);
						}

						fire_ball2[2].setPosition(150, -300 * i);

					}

					if (mummy_timer > 19000)
					{
						for (i = 0; i < 3; i++)
						{
							fire_ball2[i].move(0, 20);
							window.draw(fire_ball2[i]);
						}

					}


					// ///super power 1 is coming////
					if (mummy_timer>24000 && mummy_timer < 24500) sup1f.setPosition(1200, sground.getPosition().y - 80);
					if (mummy_timer > 24500)
					{
						sup1f.move(-20, 0);
						window.draw(sup1f);
						if (isCollide2(sup1f, playerImage2))
						{
							sup1f.setPosition(-100, -100);
							sup1ff = 1;
						}
					}

					if (sup1ff == 1)
					{

						if (Keyboard::isKeyPressed(Keyboard::S))
						{
							sup1fff = 1;
							sup1ff = 0;
							superpower1.setPosition(playerImage2.getPosition().x, playerImage2.getPosition().y - 50);

						}
						else
						{
							if (flags1 == 1)
								ups1 = ups1 - 20;
							if (ups1 <= -80) flags1 = 0;

							if (flags1 == 0)
								ups1 = ups1 + 20;
							if (ups1 >= 0) flags1 = 1;

							superpower1.setPosition(playerImage2.getPosition().x, playerImage2.getPosition().y - 180 + ups1);

							window.draw(superpower1);
						}
					}

					if (sup1fff == 1)
					{
						superpower1.move(40, 0);
						window.draw(superpower1);
					}

					if (isCollide2(superpower1, mummy) && mummy.getPosition().x < 1000)
					{
						mummy.setPosition(superpower1.getPosition().x + 200, mummy.getPosition().y);
						if (superpower1.getPosition().x>1000)  superpower1.setPosition(-6666, -6666);
					}



					for (i = 0; i < 3; i++)
					{
						if (isCollide2(fire_ball2[i], playerImage2))
						{
							cout << "fireball" << endl;
							life_flag = 1;
							clock2.restart();
							fire_ball2[i].setPosition(-100, -80);
						}

					}


					///mummy is getting attack///

					if (isCollide2(superpower1, mummy) && superpowercount == 0)
					{
						devil_livesxx--;
						superpowercount = 1;
					}

					if (isCollide2(sword, mummy) && swordcount == 0)
					{
						devil_livesxx--;
						swordcount = 1;
					}

					devil_heart.setPosition(1000, 0);
					devil_heart.setTextureRect(IntRect(2, 2, 51 * devil_livesxx, 104));




					if (devil_livesxx == 0)
					{


						boom.setPosition(mummy.getPosition().x, mummy.getPosition().y);
						mummy.move(-10, 20);
						window.draw(boom);

					}


					//cout << xod << endl;
					if (mummy.getPosition().y > 600)
					{
						//cout << mummy.getPosition().y << endl;
						xod += 25;
						playerImage2.move(55, 0);
						if (playerImage2.getPosition().x > 1300)
							window.close();
					}






					window.draw(devil_heart);
					icpc.setPosition(mummy.getPosition().x - 20, mummy.getPosition().y - 100);
					window.draw(icpc);
					window.draw(mummy);





				}







				///// java , transistor , obstacles are getting attacked ////

				int stari, cj;

				for (i = 0; i < 60; i++)
				{

					cj = attack2(ninja_starx[i]);
					if (cj == 1)
						ninja_starx[i].setPosition(-400, -100);


				}

				for (i = 0; i < 5; i++)
				{
					int aj = attack2(AnifeImgae[i]);
					if (aj == 1)
						AnifeImgae[i].setPosition(-400, -100);

				}




				///Ground and train checking  and game over////
				int k, x1, y1, r1, r2, m1;
				for (k = 0; k < 16; k++)
				{
					x1 = playerImage2.getPosition().x + 95;
					y1 = playerImage2.getPosition().y;
					r1 = sobstaclexx[k].getPosition().x;
					r2 = sobstaclexx[k].getPosition().x + 130;
					m1 = sobstaclexx[k].getPosition().y;




					if (x1 >= r1 - 10 && playerImage2.getPosition().x <= r2 && m1 - y1 >= 88)// here i have debugged from game over
					{
						if (jump_flag == 0){
							playerImage2.setPosition(50 + mmove, m1 - 95);
							source.y = Run;
							jump_flag = 1;
						}

						player_height = 300 - 100;
						break;

					}


				
					if (x1 >= r1 + 15 && playerImage2.getPosition().x <= r2 && (m1 + 100 > y1) && life_flag == 0)
					{


						cout << "obstacles" << endl;
						life_flag = 1;
						clock2.restart();
						sobstaclexx_index = k;


					}


				}

				if (isCollide2(playerImage2, mummy) && sobstaclexx[15].getPosition().x<0)
				{
					life_flag = 1;
					clock2.restart();
				}

				for (i = 0; i <= 11; i++)
				{
					if (isCollide2(playerImage2, trans_ball[i]))
					{
						cout << "transball" << endl;
						trans_ball[i].setPosition(-10000, -10000);
						t1distance[i] = -5000;
						life_flag = 1;
						clock2.restart();
					}

					if (isCollide2(transistor[i], playerImage2))
					{
						cout << "transist" << endl;
						transistor[i].setPosition(-99999, 1000);
						tdistance[i] = -25000;
						life_flag = 1;
						clock2.restart();
					}
				}


				for (i = 0; i < 5; i++)
				{
					if (isCollide2(playerImage2, java_Image[i]))
					{
						java_distance[i] = -5000;
						life_flag = 1;
						clock2.restart();

					}

				}






				for (i = 0; i < 2; i++)
				{
					trainImage[i].setPosition(xod + train_distance[4 + i] + 400, 310);
					window.draw(trainImage[i]);
				}

				for (i = 0; i < 2; i++){
					m1 = trainImage[i].getPosition().y;
					if (x1 >= trainImage[i].getPosition().x  && x1 <= trainImage[i].getPosition().x + 444)// here i have debugged from game over
					{
						if (m1 - y1 >= 50)
						{
							if (jump_flag == 0){

								playerImage2.setPosition(50 + mmove, player_height - 70);
								source.y = Run;
								jump_flag = 1;
							}
							k = 17;
							player_height = 300 - 70;
							break;
						}
						else
						{
							train_distance[4 + i] = -1000;
							life_flag = 1;
							clock2.restart();

						}

					}

				}

				if (k == 16) {
					jump_flag = 0;
					playerImage2.setPosition(playerImage2.getPosition().x, sground.getPosition().y - 90);
					player_height = 300;
				}
				if (playerImage2.getPosition().x > 50) playerImage2.move(-15, 0);





				//// Intersection checking with player and good things happen////
				for (i = 0; i < 50; i++)
				{
					if (isCollide2(playerImage2, coins[i]) == 1)
					{
						coin_sectx[i] = -1000;
						count++;
						int count1 = count;


					}

				}
				print_score2(count, count_knife);


				if (hole_image.getPosition().x - playerImage2.getPosition().x <= 20)
				{

					playerImage2.setPosition(-1500, -11000);
					hole_image.setPosition(-2050, 1500);
					hole_flag = 1;
				}

				if (xod + distance[8] + 290 < 0)
				{

					playerImage2.setPosition(50 + mmove, player_height);
					hole_image.setPosition(50, 210);
					hole_flag = 0;
					holedex = 8;

				}

				if (hole_flag == 1)
					xod -= 100;


				/*for (i = 0; i < 5; i++)
				{
				window.draw(AnifeImgae[i]);
				}
				printf("%d\n", count);*/
				float starting_pause = begin_clock.getElapsedTime().asSeconds();


				textxx_begin.setPosition(400, 200);
				if (starting_pause <= 2)
					textxx_begin.setString("Second year in CSEDU");

				else if (starting_pause <= 3){
					textxx_begin.setString("1");
					text_begin.setPosition(500, 200);
				}


				else if (starting_pause <= 4)
				{
					textxx_begin.setString("2");
					textxx_begin.setPosition(500, 200);
				}

				else if (starting_pause <= 5)
				{
					textxx_begin.setString("3");
					textxx_begin.setPosition(500, 200);
				}

				else if (starting_pause <= 6 && starting_pause<7)
					textxx_begin.setString("Go!! Go!! Go!!");
				else textxx_begin.setPosition(-100, -100);


				if (mummy.getPosition().y > 600)
				{
					textxx_begin.setPosition(500, 200);
					textxx_begin.setString("2nd!!year!!Passed");
					window.draw(textxx_begin);
					GAME_OVER2(count);
					
					if (mummy.getPosition().y > 1200)
					{
						music2.stop();
						savehigh_func(window, count);
						return;
					}
				}

				//if (mummy.getPosition().y > 1200) return;

				//if (playerImage2.getPosition().x > 1300)
				//return 2;

				//cout << Aknife_flagImage.getPosition().x << endl;
				window.draw(textxx_begin);
				window.draw(Aknife_flagImage);
				window.draw(sground);
				window.display();
				window.clear();

			}

		}
	}


}

//////////////////////////////level1 2  ends/////////////////////////////////////


