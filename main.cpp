#include "StartGame.h"
#include <Windows.h>

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE); //Скрываем консоль
	RenderWindow window(VideoMode(shirina, dlina), "SlenDi's Adventures", Style::Close);
	gameRunning(window);
	return(0);
}
