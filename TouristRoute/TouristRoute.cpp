#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void mapMenu(Texture & mapTexture)
{
	RenderWindow windowMap(VideoMode(1280, 720), "Mapa Tour");
	Sprite spriteMap;
	spriteMap.setTexture(mapTexture);
	while (windowMap.isOpen())
	{
		Event eventMap{};
		while (windowMap.pollEvent(eventMap))
		{
			if (eventMap.type == Event::MouseButtonPressed)
			{
				int xMap = eventMap.mouseButton.x;
				int yMap = eventMap.mouseButton.y;
				if (xMap >= 1201 && xMap <= 1251 && yMap >= 611 && yMap <= 677)
				{
					windowMap.close();
				}
			}
		}
		windowMap.clear();
		windowMap.draw(spriteMap);
		windowMap.display();
	}
}

void clickMenu(Event& event,Texture& mapTexture, RenderWindow& window)
{
	if (event.type == Event::MouseButtonPressed)
	{
		int x = event.mouseButton.x;
		int y = event.mouseButton.y;

		if (x >= 54 && x <= 232 && y >= 598 && y <= 657)
		{
			mapMenu(mapTexture);
		}
		if (x >= 1201 && x <= 1251 && y >= 611 && y <= 677)
		{
			window.close();
		}
	}
}

int main()
{
	RenderWindow window(VideoMode(1280, 720), "SFML works!");

	Texture texture;
	if (!texture.loadFromFile("FondoInicial.png"))
	{
		return -1;
	}


	Texture mapTexture;
	if (!mapTexture.loadFromFile("MapaBase.png"))
	{
		return -1;
	}

	Sprite sprite;
	sprite.setTexture(texture);

	while (window.isOpen())
	{
		Event event{};
		while (window.pollEvent(event))
		{

			clickMenu(event, mapTexture, window);
		}
		window.clear();
		window.draw(sprite);
		window.display();
	}
	return 0;
}