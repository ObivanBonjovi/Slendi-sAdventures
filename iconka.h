#pragma once

int Icon(RenderWindow& window)
{
	Image icon;
	if (!icon.loadFromFile("pictures/icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());
}