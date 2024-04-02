#pragma once
class BACKGROUND
{
public:
	FloatRect rect;
	Sprite sprite;

	void set(Texture& image, int x, int y)
	{
		sprite.setTexture(image);
		rect = FloatRect(x, y, H * cubY, W * cubX);
	}

	void update(float time)
	{
		rect.left = 0;
		rect.top = 0;
		sprite.setTextureRect(IntRect(0, 0, 1024, 768));
	}
};