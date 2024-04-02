#pragma once
class ENEMY
{
public:
	float dx, dy, currentFrame;
	FloatRect rect;
	Sprite sprite;
	bool life = true;
	int HealthEnemy = 100;

	void set(Texture& image, int x, int y)
	{
		sprite.setTexture(image);
		rect = FloatRect(x, y, 80, 100);
		dx = 0.05;
		currentFrame = 0;
	}

	void update(float time)
	{
		rect.left += dx * time;
		Collision();

		sprite.setTextureRect(IntRect(160 + 10, 200, 80, 100));
		currentFrame += 0.003 * time;
		if (currentFrame > 2) currentFrame -= 2;
		if (dx > 0) sprite.setTextureRect(IntRect(IntRect(80 * int(currentFrame) + 260, 210, -80, 100)));		// вправо
		if (dx < 0) sprite.setTextureRect(IntRect(IntRect(80 * int(currentFrame) + 180, 210, 80, 100)));		// влево
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

		if (HealthEnemy <= 0) life = false;
		if (!life)
		{
			sprite.setTextureRect(IntRect(170, 5, 121, 100)); // анимация смерти врага
		}
	}

	void Collision()
	{
		for (int i = rect.top / cubY; i < (rect.top + rect.height) / cubY; i++)
			for (int j = rect.left / cubX; j < (rect.left + rect.width) / cubX; j++)
				if ((TileMap[i][j] == 's') || (TileMap[i][j] == '0') ||
					(TileMap[i][j] == 'u') || (TileMap[i][j] == 'y') ||
					(TileMap[i][j] == 'k') || (TileMap[i][j] == 'c') ||
					(TileMap[i][j] == 'n') || (TileMap[i][j] == 'p') ||
					(TileMap[i][j] == 'l') || (TileMap[i][j] == 'q'))
				{
					if (dx > 0)
					{
						rect.left = j * cubX - rect.width; dx *= -1;
					}
					else if (dx < 0)
					{
						rect.left = j * cubX + cubX;  dx *= -1;
					}
				}
	}
};

class BOSS
{
public:
	float dx, dy, currentFrame;
	FloatRect rect;
	Sprite sprite;
	bool life = true;
	int HealthBoss = 400;
	void set(Texture& image, int x, int y)
	{
		sprite.setTexture(image);
		rect = FloatRect(x, y, 188, 150);

		dx = 0.05;
		currentFrame = 0;
	}

	void update(float time)
	{
		rect.left += dx * time;
		Collision();

		sprite.setTextureRect(IntRect(0, 0, 188, 150));
		currentFrame += 0.003 * time;
		if (currentFrame > 2) currentFrame -= 2;
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY - 10);
		/// ///////////////////////////СТепени урона по боссу
		if (HealthBoss == 300)sprite.setTextureRect(IntRect(0, 150, 188, 150));			// 
		if (HealthBoss == 200) { sprite.setTextureRect(IntRect(188, 150, 188, 150)); }	// текстуры для каждого положения
		if (HealthBoss == 100) { sprite.setTextureRect(IntRect(188, 0, 188, 150)); }	// здоровья босса
		if (HealthBoss <= 0)
		{
			sprite.setTextureRect(IntRect(188 + 188, 150, 188, 150));
			life = false;
			dx = 0;
		}
	}

	void Collision()
	{
		for (int i = rect.top / cubY; i < (rect.top + rect.height) / cubY; i++)
			for (int j = rect.left / cubX; j < (rect.left + rect.width) / cubX; j++)
				if ((TileMap[i][j] == 'q') || (TileMap[i][j] == 's') || (TileMap[i][j] == '0'))
				{
					if (dx > 0)
					{
						rect.left = j * cubX - rect.width; dx *= -1;
					}
					else if (dx < 0)
					{
						rect.left = j * cubX + cubX;  dx *= -1;
					}
				}
	}
};

class MOVING_PLATFORM
{
public:
	float dx = 0.07;
	FloatRect rect;
	Sprite sprite;
	float timer;

	void set(Texture& image, int x, int y)
	{
		sprite.setTexture(image);
		rect = FloatRect(x, y, 140, 50);		// размеры
	}

	void update(float time)		//функция обновления платформы.
	{
		rect.left += dx * time;	//реализация движения по горизонтали
		sprite.setTextureRect(IntRect(196, 357, 140, 50)); // координаты спрайта
		Collision();
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY - 10);
	}
	void Collision()
	{
		for (int i = rect.top / cubY; i < (rect.top + rect.height) / cubY; i++)
			for (int j = rect.left / cubX; j < (rect.left + rect.width) / cubX; j++)
				if ((TileMap[i][j] == 'q') ||
					(TileMap[i][j] == 's') ||
					(TileMap[i][j] == '0'))
				{
					if (dx > 0)
					{
						rect.left = j * cubX - rect.width; dx *= -1;
					}
					else if (dx < 0)
					{
						rect.left = j * cubX + cubX;  dx *= -1;
					}
				}
	}
};
