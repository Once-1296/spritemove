#include "sprite.h"
sprite::sprite()
{
	this->initVariables();
	this->initWindow();
}
sprite::~sprite()
{
	delete this->window;
}
void sprite::initVariables()
{
	tm1 = 5.f;
	tm2 = 5.f;
	tm3 = 5.f;
	tm4 = 5.f;
	kh1 = false;
	kh2 = false;
	kh3 = false;
	kh4 = false;
	cptr = 0;
	rptr = 1;
	tgrid[0][0].loadFromFile("up.png");
	tgrid[0][1].loadFromFile("up1.png");
	tgrid[0][2].loadFromFile("up2.png");
	tgrid[1][0].loadFromFile("down.png");
	tgrid[1][1].loadFromFile("down1.png");
	tgrid[1][2].loadFromFile("down2.png");
	tgrid[2][0].loadFromFile("left.png");
	tgrid[2][1].loadFromFile("left2.png");
	tgrid[3][0].loadFromFile("right.png");
	tgrid[3][1].loadFromFile("right2.png");
	for (int i = 0; i < 4; i++)
	{
		int n = i < 2 ? 3 : 2;
		for (int j = 0; j < n; j++)
		{
			grid[i][j].setTexture(tgrid[i][j]);
			grid[i][j].setScale(sf::Vector2f(0.4f, 0.4f));
			sf::FloatRect fr = grid[i][j].getGlobalBounds();
			grid[i][j].setOrigin(0.5f*fr.width, fr.height * 0.5f);
			if (!i && !j)
			{
				dim = grid[i][j].getGlobalBounds();
				cx = 3.5f * dim.width;
				cy = 3.5f * dim.height;
			}
			grid[i][j].setPosition(cx, cy);
		}
	}
	dim = grid[0][0].getGlobalBounds();
}
void sprite::initWindow()
{
	this->videoMode.height = (dim.height * 8) + 50;
	this->videoMode.width = (dim.width * 8) + 50;
	this->window = new sf::RenderWindow(this->videoMode, "sprite", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}
//Accessors
const bool sprite::running() const
{
	return this->window->isOpen();
}
//Functions
void sprite::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->eevee))
	{
		switch (this->eevee.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->eevee.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
				break;
			}
		}
	}
}
void sprite::updateMousePositions()
{
	/*return void
	Updates the mouse position:
	Mouse pos relative to window(vector2i)*/
	this->MousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->MousePosWindow);
}
void sprite::updatepos()
{
	for (int i = 0; i < 4; i++)
	{
		int n = i < 2 ? 3 : 2;
		for (int j = 0; j < n; j++)
		{
			grid[i][j].setPosition(cx, cy);
		}
	}
}
void sprite::update()
{
	this->pollEvents();
	this->updateMousePositions();
	bool s1 = (sf::Keyboard::isKeyPressed(sf::Keyboard::Up));
	s1 = s1 || (sf::Keyboard::isKeyPressed(sf::Keyboard::Down));
	s1 = s1 || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right));
	s1 = s1 || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
	if (s1)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (kh1 == false || !tm1)
			{
				tm1 = max(tm1 - 1.f, 0.f);
				kh1 = true;
				rptr = 0;
				cptr = 0;
				this->render();
				this->updatepos();
				cy = max(dim.height*0.5f, cy - 0.3f*dim.height);
				cptr++;
				this->render();
				this->updatepos();
				cy = max(dim.height*0.5f, cy - 0.3f*dim.height);
				cptr++;
				this->render();
				this->updatepos();
				cy = max(dim.height*0.5f, cy - 0.4f*dim.height);
				cptr = 0;
			}
			else
			{
				tm1 = max(tm1 - 1.f, 0.f);
			}
		}
		else
		{
			tm1 = 5.f;
			tm1 = max(tm1 - 1.f, 0.f);
			kh1 = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (!kh2 || !tm2)
			{
				kh2 = true;
				tm2 = max(tm2 - 1.f, 0.f);
				rptr = 1;
				cptr = 0;
				this->render();
				this->updatepos();
				cy = min(videoMode.height - 50 - (dim.height * 0.5f), cy + 0.3f * dim.height);
				cptr++;
				this->render();
				this->updatepos();
				cy = min(videoMode.height - 50 - (dim.height * 0.5f), cy + 0.3f * dim.height);
				cptr++;
				this->render();
				this->updatepos();
				cy = min(videoMode.height - 50 - (dim.height * 0.5f), cy + 0.4f * dim.height);
				cptr = 0;
			}
			else
			{
				tm2 = max(tm2 - 1.f, 0.f);
			}
		}
		else
		{
			tm2 = 5.f;
			tm2 = max(tm2 - 1.f, 0.f);
			kh2 = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (!kh3 || !tm3)
			{
				kh3 = true;
				tm3 = max(tm3 - 1.f, 0.f);
				rptr = 2;
				cptr = 0;
				this->render();
				this->updatepos();
				cx = max(dim.width*0.5f, cx - 0.5f*dim.width);
				cptr++;
				this->render();
				this->updatepos();
				cx = max(dim.width * 0.5f, cx - 0.5f * dim.width);
				cptr = 0;
			}
			else
			{
				tm3 = max(tm3 - 1.f, 0.f);
			}
		}
		else
		{
			tm3 = 5.f;
			tm3 = max(tm3 - 1.f, 0.f);
			kh3 = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (!kh4 || !tm4)
			{
				tm4 = max(tm4 - 1.f, 0.f);
				kh4 = true;
				rptr = 3;
				cptr = 0;
				this->render();
				this->updatepos();
				cx = min(videoMode.width - 50 - dim.width*0.5f, cx + 0.5f * dim.width);
				cptr++;
				this->render();
				this->updatepos();
				cx = min(videoMode.width - 50 - dim.width * 0.5f, cx + 0.5f * dim.width);
				cptr = 0;
			}
			else
			{
				tm4 = max(tm4 - 1.f, 0.f);
			}
		}
		else
		{
			tm4 = 5.f;
			tm4 = max(tm4 - 1.f, 0.f);
			kh4 = false;
		}
	}
	else
	{
		kh1 = false;
		kh2 = false;
		kh3 = false;
		kh4 = false;
		tm1 = 5.f;
		tm2 = 5.f;
		tm3 = 5.f;
		tm4 = 5.f;
	}
}
void sprite::render1(sf::RenderTarget& target)
{
	cout << rptr << " " << cptr<<"\n";
	cout << cx << " " << cy << "\n";
	target.draw(grid[rptr][cptr]);
}
void sprite::render()
{
	this->window->clear(sf::Color());
	this->render1(*this->window);
	this->window->display();

}