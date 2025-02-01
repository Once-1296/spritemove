#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include<sstream>
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Network.hpp>
using namespace std;
class sprite
{
private:
	//variables
	sf::Sprite grid[4][3];
	sf::Texture tgrid[4][3];
	int cptr, rptr;
	float cx, cy;
	bool kh1,kh2,kh3,kh4;
	float tm1,tm2,tm3,tm4;
	sf::FloatRect dim;
	//window
	sf::RenderWindow* window;
	sf::Event eevee;
	sf::VideoMode videoMode;
	//Mouse position
	sf::Vector2i MousePosWindow;
	sf::Vector2f mousePosView;
	void initVariables();
	void initWindow();
public:
	sprite();//Constructor
	virtual ~sprite();//Destructor
	//Accessors
	const bool running() const;
	void pollEvents();
	void updateMousePositions();
	void update();
	void updatepos();
	void render();
	void render1(sf::RenderTarget& target);
};

