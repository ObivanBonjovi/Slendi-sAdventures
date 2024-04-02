#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <windows.h>
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Mission.h"
#include "Menu.h"
#include "Background.h"

using namespace sf;

////////////////////// ��������� ������ //////////////////////////
const int shirina = 1024; const int dlina = 768;

int gameRunning(RenderWindow& window)
{
	menu(window);//����� ����
	Texture t;										// 
	t.loadFromFile("pictures/sprite.png");					//	�������� ������� ������  � ������
	Texture b;										// 
	b.loadFromFile("pictures/boss.png");						//	�������� ������� �����
	Texture background;								// 
	background.loadFromFile("pictures/background.png");		//	�������� ������� ������� ����

	BACKGROUND back;
	back.set(background, 0, 0);
	//�����____________________________________
	Font font;
	font.loadFromFile("Shrift.ttf");
	//Text_____________________________________
	Text textUpRight("", font, 20);						//����� ������
	textUpRight.setFillColor(Color::White);
	textUpRight.setStyle(Text::Bold);

	Text textPlayerHP("", font, 55);					 //����� �����
	textPlayerHP.setFillColor(Color::White);

	Text textBossHP("", font, 36);							// XP �����
	textBossHP.setFillColor(Color::Yellow);

	Text textMissionAndTab("", font, 15);						//����� TAB
	textMissionAndTab.setFillColor(Color::Black);
	textMissionAndTab.setStyle(Text::Italic);

	Text textTipOpenTab("", font, 15);						//����� ���������
	textTipOpenTab.setFillColor(Color::White);
	textTipOpenTab.setStyle(Text::Italic);

	Image image_map;								//������ ����������� ��� �����
	image_map.loadFromFile("pictures/map.png");				//��������� ���� ��� �����
	Texture t_map;									//�������� �����
	t_map.loadFromImage(image_map);					//�������� �������� ���������
	Sprite s_map;									//������ ������ ��� �����
	s_map.setTexture(t_map);						//�������� �������� ��������

	Image mission_image;
	mission_image.loadFromFile("pictures/missionbgmain.png");
	Texture mission_texture;
	mission_texture.loadFromImage(mission_image);
	Sprite s_mission;
	s_mission.setTexture(mission_texture);
	s_mission.setTextureRect(IntRect(0, 0, 340, 510));		//
	s_mission.setScale(0.9f, 0.8f);							//���������� �������� ��������

	Image Emeralds_frame;
	Emeralds_frame.loadFromFile("pictures/ems.png");
	Texture Emeralds_texture;
	Emeralds_texture.loadFromImage(Emeralds_frame);					// ����������� ��� �������� ������
	Sprite emeralds_sprite;
	emeralds_sprite.setTexture(Emeralds_texture);
	emeralds_sprite.setTextureRect(IntRect(0, 0, 791, 544));
	emeralds_sprite.setScale(0.04f, 0.04f);

	Image Skull_frame;
	Skull_frame.loadFromFile("pictures/skull.png");
	Texture Skull_texture;
	Skull_texture.loadFromImage(Skull_frame);					// ����������� ��� �������� ������
	Sprite skull_sprite;
	skull_sprite.setTexture(Skull_texture);
	skull_sprite.setTextureRect(IntRect(0, 0, 544, 544));
	skull_sprite.setScale(0.04f, 0.04f);

	Image Time_frame;
	Time_frame.loadFromFile("pictures/time.png");
	Texture Time_texture;
	Time_texture.loadFromImage(Time_frame);					// ����������� ��� �������� ������
	Sprite time_sprite;
	time_sprite.setTexture(Time_texture);
	time_sprite.setTextureRect(IntRect(0, 0, 544, 544));
	time_sprite.setScale(0.04f, 0.04f);

	Image bottom_frame;
	bottom_frame.loadFromFile("pictures/Frame.png");
	Texture bottom_texture;
	bottom_texture.loadFromImage(bottom_frame);				// ����������� ��� �������� �����
	Sprite bottom_sprite;
	bottom_sprite.setTexture(bottom_texture);
	bottom_sprite.setTextureRect(IntRect(0, 0, 148, 40));
	bottom_sprite.setScale(2.0f, 2.0f);

	Image top_frame;
	top_frame.loadFromFile("pictures/top.png");
	Texture top_texture;
	top_texture.loadFromImage(top_frame);				// ����������� ��� �������� �����
	Sprite top_sprite;
	top_sprite.setTexture(top_texture);
	top_sprite.setTextureRect(IntRect(0, 0, 541, 367));
	top_sprite.setScale(0.45f, 0.25f);

	Image death_frame;
	death_frame.loadFromFile("pictures/Death.png");
	Texture death_texture;
	death_texture.loadFromImage(death_frame);				// ����������� ��� �������� �����
	Sprite death_sprite;
	death_sprite.setTexture(death_texture);
	death_sprite.setTextureRect(IntRect(0, 0, 544, 544));
	death_sprite.setScale(1.0f, 1.0f);

	Image win_frame;
	win_frame.loadFromFile("pictures/Win.png");
	Texture win_texture;
	win_texture.loadFromImage(win_frame);				// ����������� ��� �������� �����
	Sprite win_sprite;
	win_sprite.setTexture(win_texture);
	win_sprite.setTextureRect(IntRect(0, 0, 544, 544));
	win_sprite.setScale(1.0f, 1.0f);
	/////////////////////////////  Music  /////////////////////////////////
	Music music;
	music.openFromFile("sounds/song.ogg");
	music.play();
	music.setVolume(30);
	music.setLoop(1);

	Music death;
	death.setVolume(120);
	death.openFromFile("sounds/death.ogg");

	Music boss_music;
	boss_music.openFromFile("sounds/boss.ogg");
	boss_music.setVolume(30);
	boss_music.setLoop(1);

	Music win;
	win.openFromFile("sounds/win.ogg");

	Music paskhalka;
	paskhalka.openFromFile("sounds/paskhalka.ogg");
	/////////////////////////////  Sounds  /////////////////////////////////
	SoundBuffer KILLENEMY, BOSSTAKEDDAMAGE, EMERELD, HEALKA, SHIPI, TELEPORT, PASHALKA, KEY, WOW;

	KILLENEMY.loadFromFile("sounds/killenemy.ogg");
	Sound killenemy(KILLENEMY);
	BOSSTAKEDDAMAGE.loadFromFile("sounds/bosstakedamage.ogg");
	Sound bosstakeddamage(BOSSTAKEDDAMAGE);
	EMERELD.loadFromFile("sounds/takeemerald.ogg");
	Sound emerald(EMERELD);
	HEALKA.loadFromFile("sounds/takeheal.ogg");
	Sound heal(HEALKA);
	SHIPI.loadFromFile("sounds/breakspike.ogg");
	Sound spike(SHIPI);
	TELEPORT.loadFromFile("sounds/useteleport.ogg");
	Sound teleport(TELEPORT);
	KEY.loadFromFile("sounds/KeyUse.ogg");
	Sound key(KEY);
	WOW.loadFromFile("sounds/wow.ogg");
	Sound wow(WOW);

	Player p;
	p.set(t, 68 * cubX, 24 * cubY);
	//Enemies_______________________________________________________
	ENEMY enemy1, enemy2, enemy3, enemy4, enemy5, enemy6;
	enemy1.set(t, 133 * cubX, 8 * cubY);
	enemy2.set(t, 124 * cubX, 22 * cubY);
	enemy3.set(t, 120 * cubX, 22 * cubY);
	enemy4.set(t, 40 * cubX, 16 * cubY);
	enemy5.set(t, 16 * cubX, 7 * cubY);
	enemy6.set(t, 48 * cubX, 6 * cubY);

	MOVING_PLATFORM mplat1, mplat2;
	mplat1.set(t, 10 * cubX, 22 * cubY);
	mplat2.set(t, 14 * cubX, 14 * cubY);

	BOSS boss;
	boss.set(b, 164 * cubX, 21 * cubY);

	bool death_music_plays = 0;
	bool boss_music_plays = 0;
	bool paskhalka_music_plays = 0;
	bool wow_plays = 0;
	float currentFrame = 0;
	Clock clock;						// ���������� �������
	Clock gameTimeClock;				// ���������� �������� �������
	int gameTime = 0;					//������������� �������� �������
	int countEnemies = 0;
	int countEnemiesMax = 6;

	RectangleShape rectangle;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();

		if ((p.life) && (boss.life)) gameTime = gameTimeClock.getElapsedTime().asSeconds(); /////////////////// ������� �����
		clock.restart();
		time = time / 600;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)				//������� ������� ������� Esc
				if ((event.key.code == Keyboard::Escape))
					window.close();
		}
		////////////////////////////////////////// ���������� ���������� ///////////////////////////////
		if ((p.life == true) && (boss.life == true))
		{
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				p.dx = -0.1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				p.dx = 0.1;

			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				if (p.onGround)
				{
					p.dy = -0.4;
					p.onGround = false;
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::LShift))
			{
				if (Keyboard::isKeyPressed(Keyboard::Right))
				{
					p.dx = 0.25;
				}
				if (Keyboard::isKeyPressed(Keyboard::Left))
				{
					p.dx = -0.25;
				}
			}
		}
		//////////////////////////////////////////  ���������� �������� ///////////////////////////////
		p.updateP(time, emerald, heal, spike, teleport, key);
		enemy1.update(time);
		enemy2.update(time);
		enemy3.update(time);
		enemy4.update(time);
		enemy5.update(time);
		enemy6.update(time);
		mplat1.update(time);
		mplat2.update(time);
		boss.update(time);
		back.update(time);
		/////////////////////////////////// ������������ � ������������. ����� "������" ��������� ////////////////////////////////////
		if (p.rect.intersects(enemy1.rect))
		{
			if (enemy1.life)
			{
				if ((p.dy > 0) && (p.Health > 0))
				{
					enemy1.dx = 0;
					p.dy = -0.2;
					enemy1.life = false;
					killenemy.play();
					countEnemies++;
				}
				else
					if (p.Health > 0)
					{
						p.Health -= 100;
					}
			}
		}
		if (p.rect.intersects(enemy2.rect))
		{
			if (enemy2.life)
			{
				if ((p.dy > 0) && (p.Health > 0))
				{
					enemy2.dx = 0;
					p.dy = -0.2;
					enemy2.life = false;
					killenemy.play();
					countEnemies++;
				}
				else
					if (p.Health > 0)
					{
						p.Health -= 100;
					}
			}
		}
		if (p.rect.intersects(enemy3.rect))
		{
			if (enemy3.life)
			{
				if ((p.dy > 0) && (p.Health > 0))
				{
					enemy3.dx = 0;
					p.dy = -0.2;
					enemy3.life = false;
					killenemy.play();
					countEnemies++;
				}
				else
					if (p.Health > 0)
					{
						p.Health -= 100;
					}
			}
		}
		if (p.rect.intersects(enemy4.rect))
		{
			if (enemy4.life)
			{
				if ((p.dy > 0) && (p.Health > 0))
				{
					enemy4.dx = 0;
					p.dy = -0.2;
					enemy4.life = false;
					killenemy.play();
					countEnemies++;
				}
				else
					if (p.Health > 0)
					{
						p.Health -= 100;
					}
			}
		}
		if (p.rect.intersects(enemy5.rect))
		{
			if (enemy5.life)
			{
				if ((p.dy > 0) && (p.Health > 0))
				{
					enemy5.dx = 0;
					p.dy = -0.2;
					enemy5.life = false;
					killenemy.play();
					countEnemies++;
				}
				else
					if (p.Health > 0)
					{
						p.Health -= 100;
					}
			}
		}
		if (p.rect.intersects(enemy6.rect))
		{
			if (enemy6.life)
			{
				if ((p.dy > 0) && (p.Health > 0))
				{
					enemy6.dx = 0;
					p.dy = -0.2;
					enemy6.life = false;
					killenemy.play();
					countEnemies++;
				}
				else
					if (p.Health > 0)
					{
						p.Health -= 100;
					}
			}
		}
		if (p.rect.intersects(boss.rect))
		{
			if (boss.life)
			{
				if ((p.dy > 0) && (p.Health > 0))
				{
					if (boss.dx > 0)boss.dx += 0.15;
					if (boss.dx < 0)boss.dx -= 0.15;
					p.dy = -0.6;
					boss.HealthBoss -= 100;
					bosstakeddamage.play();
					if (boss.HealthBoss <= 0)
					{
						boss.life = false;
						boss_music.stop();
						win.play();
					}
				}
				else
					if (p.Health > 0)
					{
						p.Health -= 100;
					}
			}
		}
		if (p.rect.intersects(mplat1.rect))
		{
			if ((p.dy > 0) || (p.onGround == false))//��� ���� ����� ��������� � ��������� ����� ������, �.� ������ ����
				if (p.rect.top + 100 < mplat1.rect.top + 50)//���� ����� ��������� ���� ���������, �.� ��� ��� ���� ������� (�� �� ��� ��������� ��� �� ���������� � ����������)
				{
					p.rect.top = mplat1.rect.top - 100 + 0.5;
					p.rect.left += mplat1.dx * time;
					p.dy = 0;
					p.onGround = true; // �� ����������� ������ ���, ����� �� ��� �� ����� �� ���������
				}
		}
		if (p.rect.intersects(mplat2.rect))
		{
			if ((p.dy > 0) || (p.onGround == false))//��� ���� ����� ��������� � ��������� ����� ������, �.� ������ ����
				if (p.rect.top + 100 < mplat2.rect.top + 50)//���� ����� ��������� ���� ���������, �.� ��� ��� ���� ������� (�� �� ��� ��������� ��� �� ���������� � ����������)
				{
					p.rect.top = mplat2.rect.top - 100 + 0.5;
					p.rect.left += mplat2.dx * time;
					p.dy = 0;
					p.onGround = true; // �� ����������� ������ ���, ����� �� ��� �� ����� �� ���������
				}
		}
		///////////////////////////////////////////  ������� ����������� ����� �������  //////////////////////////////////////////////
		if (p.rect.left > shirina / 2)
		{
			offsetX = p.rect.left - shirina / 2;
		}
		if (p.rect.left > W * cubX - shirina / 2)
		{
			offsetX = W * cubX - shirina;
		}
		if (p.rect.top < (24 * cubY - dlina / 2))
		{
			offsetY = p.rect.top - dlina / 2 + 95;
		}
		else
		{
			offsetY = 525;
		}
		if (p.rect.top < ((dlina / 2) - cubY - 45))
		{
			offsetY = 0;
		}

		window.clear(Color::Cyan);		// ������ ������ ��� ������������ � ������� ����
		window.draw(back.sprite);		// ��������� ������� ����
		///////////////////////////////////////  ���������� ����� ����������� - �������   ////////////////////////////////////////////
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == ' ')  continue;						//���� ��������� ������ ������, �� ������ 1� ���������;
				if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(0 * cubX, 0, cubX, cubY));	//

				if (TileMap[i][j] == 'p')  s_map.setTextureRect(IntRect(cubX, 0, cubX, cubY));		//
				if (TileMap[i][j] == 'l')  s_map.setTextureRect(IntRect(2 * cubX, 0, cubX, cubY));	// 

				if (TileMap[i][j] == 'k')  s_map.setTextureRect(IntRect(8 * cubX, 0, cubX, cubY));	//���� ��������� ������ 0, �� ������ 3� ���������
				if (TileMap[i][j] == 'c')  s_map.setTextureRect(IntRect(7 * cubX, 0, cubX, cubY));	// m - �������
				if (TileMap[i][j] == 'n')  s_map.setTextureRect(IntRect(9 * cubX, 0, cubX, cubY));	// m - �������

				if (TileMap[i][j] == 'e')  s_map.setTextureRect(IntRect(3 * cubX, 0, cubX, cubY));	// m - �������
				if (TileMap[i][j] == 'E')  s_map.setTextureRect(IntRect(4 * cubX, 0, cubX, cubY));	// m - �������

				if (TileMap[i][j] == 'z')  s_map.setTextureRect(IntRect(13 * cubX, 0, cubX, cubY));	// ����
				if (TileMap[i][j] == 'Z')  s_map.setTextureRect(IntRect(14 * cubX, 0, cubX, cubY));	// ����
				if (TileMap[i][j] == 'R')  s_map.setTextureRect(IntRect(14 * cubX, 0, cubX, cubY));	// ���� (����)

				if (TileMap[i][j] == '0')  s_map.setTextureRect(IntRect(10 * cubX, 0, cubX, cubY));	//���� ��������� ������ 0, �� ������ 3� ���������
				if (TileMap[i][j] == 'm')  s_map.setTextureRect(IntRect(15 * cubX, 0, cubX, cubY));	// m - �������
				if (TileMap[i][j] == 'h')  s_map.setTextureRect(IntRect(18 * cubX, 0, cubX, cubY));	// ������� ������
				if (TileMap[i][j] == 'b')  s_map.setTextureRect(IntRect(17 * cubX, 0, cubX, cubY));	// �������� �������� (+�������)
				if (TileMap[i][j] == 'r')  s_map.setTextureRect(IntRect(16 * cubX, 0, cubX, cubY));	// ������ (�� �� ������������ �����)
				if (TileMap[i][j] == 'g')  s_map.setTextureRect(IntRect(11 * cubX, 0, cubX, cubY));	// ��������� � 3 � 4 ������
				if (TileMap[i][j] == '1')  s_map.setTextureRect(IntRect(12 * cubX, 0, cubX, cubY));	// �������� �� ������� 1
				if (TileMap[i][j] == '2')  s_map.setTextureRect(IntRect(12 * cubX, 0, cubX, cubY));	// �������� �� ������� 2
				if (TileMap[i][j] == '3')  s_map.setTextureRect(IntRect(12 * cubX, 0, cubX, cubY));	// �������� �� ������� 3
				if (TileMap[i][j] == '4')  s_map.setTextureRect(IntRect(12 * cubX, 0, cubX, cubY));	// �������� �� ������� 4
				if (TileMap[i][j] == '5')  s_map.setTextureRect(IntRect(12 * cubX, 0, cubX, cubY));	// �������� �� ������� 5
				if (TileMap[i][j] == 'y')  s_map.setTextureRect(IntRect(10 * cubX, 0, cubX, cubY));	// ��������� ����� � ���������
				if (TileMap[i][j] == 'O')  s_map.setTextureRect(IntRect(12 * cubX, 0, cubX, cubY));	// �������� �������� (� ����������� ������)
				if (TileMap[i][j] == 'u')  s_map.setTextureRect(IntRect(11 * cubX, 0, cubX, cubY));	// u - ������� ��������� �� 2 ������
				if (TileMap[i][j] == 'j')  s_map.setTextureRect(IntRect(11 * cubX, 0, cubX, cubY));	// �������� �������������� ���������
				if (TileMap[i][j] == 'q') continue;	// ��������� ������ ��� ���

				s_map.setPosition(j * cubX - offsetX, i * cubY - offsetY - 10);		// ����������� ����������� (��������� �� �������), �������� ����� 
																					// ����� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������
				window.draw(s_map);													// ������ ���������� �� �����
			}
		/// //////////////////////////////////  ����������, ����������� �� �����  ///////////////////////////////////
		std::ostringstream	levelString, levelmaxString, healthString, gameTimeString,	//
			countEnemiesString, countEnemiesMaxString, ZdorovieBoss;	// ���������� ����������
		levelString << level;
		levelmaxString << levelmax;
		countEnemiesString << countEnemies;
		countEnemiesMaxString << countEnemiesMax;;
		healthString << p.Health;
		gameTimeString << gameTime;
		ZdorovieBoss << boss.HealthBoss;

		window.draw(enemy1.sprite);
		window.draw(enemy2.sprite);
		window.draw(enemy3.sprite);
		window.draw(enemy4.sprite);
		window.draw(enemy5.sprite);
		window.draw(enemy6.sprite);
		window.draw(mplat1.sprite);
		window.draw(mplat2.sprite);
		window.draw(boss.sprite);
		window.draw(p.sprite);
		/// //////////////////////////////////  ���������  ///////////////////////////////////
		if (Keyboard::isKeyPressed(Keyboard::Tab))
		{
			std::ostringstream task;						//������ ������ ������
			task << getTextMission(getCurrentMission(p.rect.left, boss.life, level));		//���������� ������� getTextMission (��� ���������� ����� ������), 
																		//������� ��������� � �������� ��������� ������� getCurrentMission(������������ ����� ������)
																		//, � ��� ��� �-��� ��������� � �������� ��������� ������� p.getplayercoordinateX()
																		//	(��� �-��� ���������� ��� ���������� ������)
			textMissionAndTab.setString(task.str());					//������ ��������	
			textMissionAndTab.setPosition(80, 35);       // ������� ������ TAB
			s_mission.setPosition(40, 0);				// ������� ���� 
			window.draw(s_mission);						// ������ ������ ������ (���)
			window.draw(textMissionAndTab);				// � ����� � �����
		}
		if (gameTime < 6)
		{
			textTipOpenTab.setString("Hold 'TAB' to \n  get hints ");
			textTipOpenTab.setPosition(p.rect.left - offsetX - 10, p.rect.top - offsetY - 35);	// ������� - ���������
			window.draw(textTipOpenTab);
		}
		bottom_sprite.setPosition(10, dlina - 85);    //////////////////// ��� ������� ����� (��)
		window.draw(bottom_sprite);
		top_sprite.setPosition(688 + 80, 4);
		window.draw(top_sprite);
		emeralds_sprite.setPosition(700 + 80, 12);
		window.draw(emeralds_sprite);
		skull_sprite.setPosition(705 + 80, 37);
		window.draw(skull_sprite);
		time_sprite.setPosition(705 + 80, 62);
		window.draw(time_sprite);

		textBossHP.setString(" HP:" + ZdorovieBoss.str());
		textBossHP.setPosition(boss.rect.left - offsetX + 15, boss.rect.top - offsetY - 50);	// ������� - �� �����
		if (boss.HealthBoss > 0) { window.draw(textBossHP); }

		textUpRight.setString("Emeralds : " + levelString.str() + "/" + levelmaxString.str());
		textUpRight.setPosition(745 + 80, 10);								// ������� � ������� ������ ���� ������
		window.draw(textUpRight);

		textUpRight.setString("Enemies : " + countEnemiesString.str() + "/" + countEnemiesMaxString.str());
		textUpRight.setPosition(745 + 80, 35);								// ������� � ������� ������ ���� ������
		window.draw(textUpRight);

		textUpRight.setString("Time: " + gameTimeString.str());
		textUpRight.setPosition(745 + 80, 60);								// ������� � ������� ������ ���� ������
		window.draw(textUpRight);

		textPlayerHP.setString(healthString.str());
		textPlayerHP.setPosition(145, 685);								// ������� � ������ ����� ���� ������
		window.draw(textPlayerHP);
		///////////////////////  ���� ��� ����� ����� ��� ��� �������� ������� ///////////////////////////
		if ((countEnemies == countEnemiesMax) && !(paskhalka_music_plays))
		{
			paskhalka_music_plays = 1; paskhalka.play();
		}
		if ((level == levelmax) && !(wow_plays))
		{
			wow_plays = 1; wow.play();
		}
		//////////////////////////////////  ���� � ������� ����� ////////////////////////////////
		if ((p.rect.left >= 147 * cubX) && (p.rect.left < 176 * cubX) && !(boss_music_plays))
		{
			boss_music_plays = 1;
			music.stop();
			boss_music.play();
			background.loadFromFile("pictures/background_boss.png");
		}
		/// ////////////////// ������� ��� ������ ��������� /////////////////////////////////////////
		if (!(p.life) && (death_music_plays == 0))
		{
			music.stop();
			boss_music.stop();
			death.play();
			death_music_plays = 1;
		}
		if (!(p.life) && (death_music_plays == 1))
		{
			//textEnding1.setString(" GAME OVER \n  For EXIT \n  click ESC");
			death_sprite.setPosition(shirina / 2 - 272, dlina / 2 - 272);
			window.draw(death_sprite);
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				return false;
			}
		}
		if (!(boss.HealthBoss))
		{
			win_sprite.setPosition(shirina / 2 - 272, dlina / 2 - 272);
			window.draw(win_sprite);
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				return false;
			}
		}

		window.display();
	}
}
