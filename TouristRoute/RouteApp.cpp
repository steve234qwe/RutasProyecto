#include "RouteApp.h"
#include <iostream>

RouteApp::RouteApp()
{
	window.create(VideoMode(1280, 720), "Proyecto Rutas");
	if (!texture.loadFromFile("Imagenes,Archivos/ImagenInicio.png"))
	{
		return;
	}
	if (!mapTexture.loadFromFile("Mapa.png"))
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
			clickMenu(event);
		}
		window.clear();
		window.draw(sprite);
		window.display();
	}
}

void RouteApp::clickMenu(Event& event)
{
	if (event.type == Event::MouseButtonPressed)
	{
		int x = event.mouseButton.x;
		int y = event.mouseButton.y;

		if (x >= 60 && x <= 266 && y >= 551 && y <= 579)
		{
			window.setVisible(false);
			optionMap();
		}
		if (x >= 52 && x <= 273 && y >= 612 && y <= 638)
		{
			window.setVisible(false);
			optionMap();
		}
		if (x >= 1200 && x <= 1257 && y >= 610 && y <= 681)
		{
			window.close();
		}
	}
}

void RouteApp::optionMap()
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
				cout << "X" << xMap << "\nY" << yMap << endl;
				if (xMap >= 6 && xMap <= 94 && yMap >= 607 && yMap <= 713)
				{
					windowMap.close();
					window.setVisible(true);
				}
			}
		}
		windowMap.clear();
		windowMap.draw(spriteMap);
		windowMap.display();
	}
}
