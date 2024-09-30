#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void optionMap(Texture& map)
{
	RenderWindow windowMap(VideoMode(1280, 720), "Mapa Tour");
	Sprite spriteMap;
	spriteMap.setTexture(map);
	while (windowMap.isOpen())
	{
		Event eventMap{};
		while (windowMap.pollEvent(eventMap))
		{
			if (eventMap.type == Event::MouseButtonPressed)
			{
				int xMap = eventMap.mouseButton.x;
				int yMap = eventMap.mouseButton.y;
				cout << "X" << xMap << endl << "Y" << yMap << endl;
				if (xMap >= 1172 && xMap <= 1255 && yMap >= 598 && yMap <= 691)
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


void subMapMenu(Texture& SubMapTexture, Texture& map)
{
	RenderWindow windowSubMenu(VideoMode(1280, 720), "Menu");
	Sprite spriteSubMenu;
	spriteSubMenu.setTexture(SubMapTexture);
	while (windowSubMenu.isOpen())
	{
		Event eventSubMenu{};
		while (windowSubMenu.pollEvent(eventSubMenu))
		{
			if (eventSubMenu.type == Event::MouseButtonPressed)
			{
				int xMap = eventSubMenu.mouseButton.x;
				int yMap = eventSubMenu.mouseButton.y;
				cout << "X" << xMap << endl << "Y" << yMap << endl;

				if (xMap >= 422 && xMap <= 966 && yMap >= 186 && yMap <= 254)
				{
					optionMap(map);
				}
				if (xMap >= 425 && xMap <= 963 && yMap >= 376 && yMap <= 456)
				{
					optionMap(map);
				}
				if (xMap >= 1172 && xMap <= 1255 && yMap >= 598 && yMap <= 691)
				{
					windowSubMenu.close();
				}
			}
		}

		windowSubMenu.clear();
		windowSubMenu.draw(spriteSubMenu);
		windowSubMenu.display();
	}
}



void clickMenu(Event& event, Texture& mapTexture, RenderWindow& window, Texture& map)
{
	if (event.type == Event::MouseButtonPressed)
	{
		int x = event.mouseButton.x;
		int y = event.mouseButton.y;

		if (x >= 54 && x <= 232 && y >= 598 && y <= 657)
		{
			subMapMenu(mapTexture, map);
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


	Texture SubMenuTexture;
	if (!SubMenuTexture.loadFromFile("SubMenu.png"))
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

			clickMenu(event, SubMenuTexture, window, mapTexture);
		}
		window.clear();
		window.draw(sprite);
		window.display();
	}
	return 0;
}