#pragma once
float offsetX = 0, offsetY = 0;
int level = 0;
int levelmax = 5;
int rich = 0;
class Player
{
public:
	float dx, dy, currentFrame;
	FloatRect rect;
	bool onGround, life;
	Sprite sprite;
	int Score = 0, Health = 100;

	void set(Texture& image, int x, int y)
	{
		sprite.setTexture(image);
		rect = FloatRect(x, y, 75, 100);
		life = true;
		dx = 0;
		dy = 0;
		currentFrame = 0;
	}

	void updateP(float time, Sound& soundE, Sound& soundH, Sound& soundS, Sound& soundT, Sound& soundK)
	{
		rect.left += dx * time;
		CollisionX();
		if (!onGround) dy = dy + 0.0005 * time;

		rect.top += dy * time;
		onGround = false;
		CollisionY();

		currentFrame += 0.003 * time;
		if (currentFrame > 2) currentFrame -= 2;
		if (dx > 0) sprite.setTextureRect(IntRect(IntRect(80 * int(currentFrame) + 80, 210, -80, 100))); // ������
		if (dx < 0) sprite.setTextureRect(IntRect(IntRect(80 * int(currentFrame), 210, 80, 100)));		 // �����
		if (dx == 0 && dy == 0) sprite.setTextureRect(IntRect(0, 5, 80, 100));							 // ����� �� �����
		if (dx > 0 && !(dy == 0)) sprite.setTextureRect(IntRect(IntRect(160, 210, -80, 100)));			 // ���� ������
		if (dx < 0 && !(dy == 0)) sprite.setTextureRect(IntRect(IntRect(80, 210, 80, 100)));             // ���� �����

		Monetki(soundK);
		Teleport(soundE, soundT);
		YadCvetok(soundS);
		HpBanka(soundH);
		Richag(soundK);
		Change();
		if (Health <= 0) //���� ������ ������ ���� ����� 0, �� ������� � ��������� �������� ������ ����� ������
		{
			sprite.setTextureRect(IntRect(0, 96, 106, 108));
			life = false;
			Health = 0;
		}
		if (Health > 100) // ����� �������� //
		{
			Health = 100;
		}

		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
		dx = 0;
	}
	//////////////////////////////// ������� ��������� � ������� ����� ///////////////////////////////////
	void CollisionX()
	{
		for (int i = rect.top / cubY; i < (rect.top + rect.height) / cubY; i++)
			for (int j = rect.left / cubX; j < (rect.left + rect.width) / cubX; j++)
			{
				if ((TileMap[i][j] == 's') ||
					(TileMap[i][j] == '0') ||
					(TileMap[i][j] == 'u') ||
					(TileMap[i][j] == 'y') ||
					(TileMap[i][j] == 'k') ||
					(TileMap[i][j] == 'c') ||
					(TileMap[i][j] == 'n') ||
					(TileMap[i][j] == 'p') ||
					(TileMap[i][j] == 'l') ||
					(TileMap[i][j] == 'e') ||
					(TileMap[i][j] == 'E'))
				{
					if (dx > 0)
					{
						rect.left = j * cubX - rect.width;
					}
					if (dx < 0)
					{
						rect.left = j * cubX + cubX;
					}
				}
			}
	}
	void CollisionY()
	{
		for (int i = rect.top / cubY; i < (rect.top + rect.height) / cubY; i++)
			for (int j = rect.left / cubX; j < (rect.left + rect.width) / cubX; j++)
			{
				if ((TileMap[i][j] == 's') ||
					(TileMap[i][j] == '0') ||
					(TileMap[i][j] == 'u') ||
					(TileMap[i][j] == 'g') ||
					(TileMap[i][j] == 'j') ||
					(TileMap[i][j] == 'y') ||
					(TileMap[i][j] == 'k') ||
					(TileMap[i][j] == 'c') ||
					(TileMap[i][j] == 'n') ||
					(TileMap[i][j] == 'p') ||
					(TileMap[i][j] == 'l') ||
					(TileMap[i][j] == 'e') ||
					(TileMap[i][j] == 'E'))
				{
					if (dy > 0)
					{
						rect.top = i * cubY - rect.height;
						dy = 0;
						onGround = true;
					}
					if (dy < 0)
					{
						rect.top = i * cubY + cubY;
						dy = 0;
					}
				}
			}
	}
	void Monetki(Sound& soundK)
	{
		for (int i = rect.top / cubY; i < (rect.top + rect.height) / cubY; i++)
			for (int j = rect.left / cubX; j < (rect.left + rect.width) / cubX; j++)
			{
				if (TileMap[i][j] == 'm')
				{						//���� ������ ����� 'm' (monetka)
					Score++;			// + ���� (3 �������)
					TileMap[i][j] = ' ';//������� �����
					soundK.play();
				}
			}
	}
	void Teleport(Sound& soundE, Sound& soundT)
	{
		for (int i = rect.top / cubY; i < (rect.top + rect.height) / cubY; i++)
			for (int j = rect.left / cubX; j < (rect.left + rect.width) / cubX; j++)
			{
				if ((TileMap[i][j] == '1') && (Keyboard::isKeyPressed(Keyboard::Space)))
				{
					dx = 0; dy = 0;
					rect.top = 21 * cubY; rect.left = 22 * cubX;	// ���������� ����������� 
					soundT.play();
				}
				if ((TileMap[i][j] == '2') && (Keyboard::isKeyPressed(Keyboard::Space)))
				{
					dx = 0; dy = 0;
					rect.top = 2 * cubY; rect.left = 122 * cubX;	// ���������� ����������� 
					soundT.play();
				}
				if ((TileMap[i][j] == '3') && (Keyboard::isKeyPressed(Keyboard::Space)))
				{
					dx = 0; dy = 0;
					rect.top = 3 * cubY; rect.left = 30 * cubX;	// ���������� ����������� 
					soundT.play();
				}
				if ((TileMap[i][j] == '4') && (Keyboard::isKeyPressed(Keyboard::Space)))
				{
					dx = 0; dy = 0;
					rect.top = 24 * cubY; rect.left = 90 * cubX;	// ���������� ����������� 
					soundT.play();
				}
				if ((TileMap[i][j] == '5') && (Keyboard::isKeyPressed(Keyboard::Space)))
				{
					dx = 0; dy = 0;
					rect.top = 20 * cubY; rect.left = 154 * cubX;	// ���������� ����������� 
					soundT.play();
				}
				if (TileMap[i][j] == 'b')
				{										//���� ������ ����� 't' (teleport)
					dx = 0; dy = 0;
					level++;
					TileMap[i][j] = ' ';
					soundE.play();
				}
				if ((TileMap[i][j] == 'O') && (Keyboard::isKeyPressed(Keyboard::Space)))
				{
					dx = 0; dy = 0;
					soundT.play();
					if (level <= 2)
					{
						rect.top = 24 * cubY; rect.left = 68 * cubX;	// ���������� ����������� 
					}
					if (level > 2)
					{
						rect.top = 16 * cubY; rect.left = 68 * cubX;	// ���������� ����������� 
					}
				}
			}
	}
	void YadCvetok(Sound& soundS)
	{
		for (int i = rect.top / cubY; i < (rect.top + rect.height) / cubY; i++)
			for (int j = rect.left / cubX; j < (rect.left + rect.width) / cubX; j++)
			{
				if ((TileMap[i][j] == 'z') || (TileMap[i][j] == 'Z') || (TileMap[i][j] == 'R'))
				{							//���� ������ ����� 'z' (cvetok)
					Health -= 25;			// - zizn
					TileMap[i][j] = ' ';	//�������  �����.
					soundS.play();
				}
			}
	}
	void HpBanka(Sound& soundH)
	{
		for (int i = rect.top / cubY; i < (rect.top + rect.height) / cubY; i++)
			for (int j = rect.left / cubX; j < (rect.left + rect.width) / cubX; j++)
			{
				if (TileMap[i][j] == 'h')
				{							//���� ������ ����� 'h' (zdorovie)
					Health += 20;			// + zizn
					TileMap[i][j] = ' ';	//�������  �����
					soundH.play();
				}
			}
	}
	void Richag(Sound& soundK)
	{
		for (int i = rect.top / cubY; i < (rect.top + rect.height) / cubY; i++)
			for (int j = rect.left / cubX; j < (rect.left + rect.width) / cubX; j++)
			{
				if (TileMap[i][j] == 'r')
				{
					rich++;
					TileMap[i][j] = ' ';	    //�������  ��������
					soundK.play();
				}
			}
	}
	void Change()
	{
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'u' && rich == 1)
				{
					TileMap[i][j] = ' ';	    //�������  ��������
				}
				if (TileMap[i][j] == 'R' && (rich == 2))
				{
					TileMap[i][j] = ' ';	    //�������  ��������
				}
				if (TileMap[i][j] == 'g' && level >= 2)
				{
					TileMap[i][j] = ' ';	    //�������  ��������
				}

				if (TileMap[i][j] == 'j' && level >= 4)
				{
					TileMap[i][j] = ' ';	    //�������  ��������
				}
				if (TileMap[i][j] == 'y' && Score == 3)
				{
					TileMap[i][j] = ' ';	    //�������  ��������
				}
			}
	}
};
