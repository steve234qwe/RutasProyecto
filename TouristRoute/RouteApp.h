#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class RouteApp
{
private:
	RenderWindow window;
	RenderWindow windowMap;
	RenderWindow windowSubMenu;
	Texture texture;
	Texture mapTexture;
	

public:
	RouteApp();
	~RouteApp();

	void startApp();
	void clickMenu(Event& event);
	void optionMap();

};

