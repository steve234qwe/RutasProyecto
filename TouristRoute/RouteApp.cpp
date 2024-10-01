
#include "RouteApp.h"

RouteApp::RouteApp()
{
	window.create(VideoMode(1280, 720), "Proyecto Rutas");
	
	if (!texture.loadFromFile("Imagenes,Archivos/FondoInicial.png"))
	{
		return;
	}
	if (!SubMenuTexture.loadFromFile("Imagenes,Archivos/SubMenu.png"))
	{
		return;
	}
	if (!mapTexture.loadFromFile("Imagenes,Archivos/MapaBase.png"))
	{
		return;
	}


}
RouteApp::~RouteApp()
{
}

void RouteApp::startApp()
{
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
}

void RouteApp::clickMenu(Event& event, Texture& mapTexture, RenderWindow& window, Texture& map)
{


	if (event.type == Event::MouseButtonPressed)
	{
		int x = event.mouseButton.x;
		int y = event.mouseButton.y;
		if (x >= 54 && x <= 232 && y >= 598 && y <= 657)
		{
			subMapMenu(mapTexture, map);
		}
		if (x >= 1200 && x <= 1257 && y >= 610 && y <= 681)
		{
			window.close();
		}
	}

}

void RouteApp::subMapMenu(Texture& SubMapTexture, Texture& map)
{
	windowSubMenu.create(VideoMode(1280, 720), "Menu");
	Sprite spriteSubMenu;
	spriteSubMenu.setTexture(SubMapTexture);
	while (windowSubMenu.isOpen())
	{
		Event eventSubMenu{};
		while (windowSubMenu.pollEvent(eventSubMenu))
		{
			if (eventSubMenu.type == Event::MouseButtonPressed)
			{
				int xMenu = eventSubMenu.mouseButton.x;
				int yMenu = eventSubMenu.mouseButton.y;

				if (xMenu >= 422 && xMenu <= 966 && yMenu >= 186 && yMenu <= 254)
				{
					optionMap(map);
				}
				if (xMenu >= 425 && xMenu <= 963 && yMenu >= 376 && yMenu <= 456)
				{
					optionMap(map);
				}
				if (xMenu >= 1172 && xMenu <= 1255 && yMenu >= 598 && yMenu <= 691)
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

void RouteApp::optionMap(Texture& map)
{
	windowMap.create(VideoMode(1280, 720), "Mapa Tour");
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
