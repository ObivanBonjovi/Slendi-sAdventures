#pragma once
#include "iconka.h"

void menu(RenderWindow& window)
{
	Icon(window);
	Texture menuTexture1, menuTexture2, menuTexture4, menuTexture3, aboutTexture, controlsTexture, menuBackground;
	Music musicOkno;
	musicOkno.openFromFile("sounds/menu.ogg");
	musicOkno.play();
	musicOkno.setVolume(40);
	musicOkno.setLoop(1);
	menuTexture1.loadFromFile("images/new.png");
	menuTexture2.loadFromFile("images/creators.png");
	menuTexture4.loadFromFile("images/controls.png");
	menuTexture3.loadFromFile("images/exit.png");
	aboutTexture.loadFromFile("images/about.png");
	controlsTexture.loadFromFile("images/controlss.png");
	menuBackground.loadFromFile("images/back.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu4(menuTexture4), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground), keys(controlsTexture);
	bool isMenu = 1;
	int menuNum = 0;
	menu1.setPosition(52, 375);
	menu2.setPosition(52, 450);
	menu4.setPosition(52, 520);
	menu3.setPosition(52, 660);
	menuBg.setPosition(0, 0);
	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menuNum = 0;
		window.clear();

		if (IntRect(52, 375, 252, 69).contains(Mouse::getPosition(window))) { menuNum = 1; }
		if (IntRect(52, 450, 252, 69).contains(Mouse::getPosition(window))) { menuNum = 2; }
		if (IntRect(52, 660, 252, 69).contains(Mouse::getPosition(window))) { menuNum = 3; }
		if (IntRect(52, 520, 252, 69).contains(Mouse::getPosition(window))) { menuNum = 4; }

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;					//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2)
			{
				while (!Keyboard::isKeyPressed(Keyboard::Escape))
				{
					window.draw(about);
					window.display();
				}
			}
			if (menuNum == 4)
			{
				while (!Keyboard::isKeyPressed(Keyboard::Escape))
				{
					window.draw(keys);
					window.display();
				}
			}
			if (menuNum == 3) { window.close(); isMenu = false; }
		}
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isMenu = false;
				window.close();
			}
		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(menu4);
		window.display();
	}
}
