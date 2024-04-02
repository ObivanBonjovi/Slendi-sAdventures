#pragma once
using namespace std;
///////////////////////////////////НОМЕР МИССИИ//////////////////////////////////
int getCurrentMission(int x, bool lifeB, int emerald)//ф-ция номера миссия, которая меняет номер миссии, в зависимости от координаты игрока Х (сюда будем передавать эту координату)
{
	int mission = 0;
	if ((x >= 1 * cubX) && (x < 27 * cubX))						{ mission = 1; }		//игрок на 1 миссии
	if ((x >= 28 * cubX) && (x < 56 * cubX))					{ mission = 3; }		//игрок на 3 миссии
	if ((x >= 56 * cubX) && (x < 82 * cubX))					{ mission = 0; }		//основная локация
	if ((x >= 83 * cubX) && (x < 109 * cubX))					{ mission = 4; }		//игрок на 4 миссии
	if ((x >= 110 * cubX) && (x < 136 * cubX))					{ mission = 2; }		//игрок на 2 миссии
	if (((x >= 1 * cubX) && (x < 136 * cubX)) && (emerald >= 4)){ mission = 6; }		//готовность к битве
	if ((x >= 153 * cubX) && (x < 180 * cubX))					{ mission = 5; }		//игрок на боссе
	if (((x >= 153 * cubX) && (x < 180 * cubX)) && (lifeB == false)) { mission = 7; }	//побкда
	return mission;																//ф-ция возвращает номер миссии
}
/////////////////////////////////////ТЕКСТ МИССИИ/////////////////////////////////
string getTextMission(int currentMission)
{
	string missionText = "";			//текст миссии и его инициализация

	switch (currentMission)				//принимается номер миссии и в зависимости от него переменной missionText присваивается различный текст
	{
	case 0: missionText =	"\nWelcome to the trials of the	\n wanderer, choose a level to	\npass, as you progress through	\nnew levels will open, if you"
							"\n  successfully pass all the	\n tests, you will have access 	\n to a battle with the boss!		\n\nDon't forget to open the 'TAB'"
							"\n   hints at each new level!"; break;
	case 1: missionText =	"\n  Use moving platforms to	\n    overcome the obstacle. 	\n\n    Be careful with your  " 
							"\n  opponents, one touch of	\n	  them is deadly!			\n\n    Spikes also do damage,	"
							"\n but it is not lethal if		\n   there are enough lives..."; break;
	case 2: missionText =	"\n  To open the passage,		\n       pick up the key.  		\n\n  Deftly use the keyboard to   "
							"\n overcome the spikes and  	\n  enemies that separate you   \n       from the emerald!"; break;
	case 3: missionText =	"\n  Do not rush to use the		\n'Shift' acceleration, try to  \n  pass by the spikes slowly."
							"\n\nOnly a well-thought-out move\nwill help you get the emerald \n   and not get damage."; break;
	case 4: missionText =	"\nUse 'Shift' along with the	\n jump to increase its range."
							"\n\nTo open the passage, you need\n to collect all the coins on\n     the level."; break;
	case 5: missionText =	"\n\n       Defeat the BOSS! "; break;
	case 6: missionText =	"\n Congratulations, you have 	\n passed all the levels, it's \n   time to defeat the boss. " 
							"\n\n          LET'S GO"; break;
	case 7: missionText =	"\n\n      Congratulations! \n       You did it! "; break;
	}
	return missionText;		//ф-ция возвращает текст
};

