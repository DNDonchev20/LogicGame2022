#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../Frontend/LogicTenacity-SFML-Functions.h"
#include "../Backend/LogicTenacity-Functions.h"

using namespace std;

// play menu
void playMenu(sf::Event event, sf::Texture texture, sf::RenderWindow& window)
{
	while (true)
	{
		texture.loadFromFile("../Images/playMenu.png");

		sf::Sprite sprite(texture);

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::MouseButtonPressed:
				{
					switch (event.key.code)
					{
						case sf::Mouse::Left:
						{
							if ((event.mouseButton.x >= 140 && event.mouseButton.x <= 630) &&
								event.mouseButton.y >= 350 && event.mouseButton.y <= 410)
							{
								setup(false);
							}

							else if ((event.mouseButton.x >= 100 && event.mouseButton.x <= 700) &&
								event.mouseButton.y >= 520 && event.mouseButton.y <= 580)
							{
								setup(true);
							}

							else if ((event.mouseButton.x >= 30 && event.mouseButton.x <= 440) &&
								event.mouseButton.y >= 740 && event.mouseButton.y <= 800)
							{
								return;
							}
							break;
						}
						break;
					}
				}
			}
		}
		window.draw(sprite);
		window.display();
	}
}

// practice menu
void practiceMenu(sf::Event event, sf::Texture texture, sf::RenderWindow& window)
{
	while (true)
	{
		texture.loadFromFile("../Images/practice.png");

		sf::Sprite sprite(texture);

		window.draw(sprite);
		window.display();
	}
}

// tutorial menu
void tutorialMenu(sf::Event event, sf::Texture texture, sf::RenderWindow& window)
{
	while (true)
	{
		texture.loadFromFile("../Images/tutorial.png");

		sf::Sprite sprite(texture);

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::MouseButtonPressed:
				{
					switch (event.key.code)
					{
						case sf::Mouse::Left:
						{
							if ((event.mouseButton.x >= 480 && event.mouseButton.x <= 750) &&
							event.mouseButton.y >= 720 && event.mouseButton.y <= 800)
							{
								// future idea
								practiceMenu(event, texture, window);
							}

							else if ((event.mouseButton.x >= 10 && event.mouseButton.x <= 300) &&
								event.mouseButton.y >= 720 && event.mouseButton.y <= 800)
							{
								return;
							}
							break;
						}
						break;
					}
				}
			}
		}
		window.draw(sprite);
		window.display();
	}
}

// how to play menu
void howToPlayMenu(sf::Event event, sf::Texture texture, sf::RenderWindow& window)
{
	while (true)
	{
		texture.loadFromFile("../Images/howToPlay.png");

		sf::Sprite sprite(texture);

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::MouseButtonPressed:
				{
					switch (event.key.code)
					{
						case sf::Mouse::Left:
						{
							if ((event.mouseButton.x >= 40 && event.mouseButton.x <= 450) &&
								event.mouseButton.y >= 740 && event.mouseButton.y <= 800)
							{
								return;
							}
							break;
						}
						break;
					}
				}
			}
		}
		window.draw(sprite);
		window.display();
	}
}

// main menu
void startupMenu()
{
	sf::RenderWindow window{ sf::VideoMode(800,890), "Logic Tenacity", sf::Style::Titlebar | sf::Style::Close };

	sf::Texture texture;
	texture.loadFromFile("../Images/menu.png");

	sf::Sprite sprite(texture);

	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::MouseButtonPressed:
				{
					switch (event.key.code)
					{
						case sf::Mouse::Left:
						{
							// Play
							if ((event.mouseButton.x >= 300 && event.mouseButton.x <= 520) &&
							event.mouseButton.y >= 350 && event.mouseButton.y <= 400)
							{
								playMenu(event, texture, window);
							}

							// How to play
							else if ((event.mouseButton.x >= 220 && event.mouseButton.x <= 570) &&
							event.mouseButton.y >= 460 && event.mouseButton.y <= 510)
							{
								howToPlayMenu(event, texture, window);
							}

							// Tutorial
							else if ((event.mouseButton.x >= 300 && event.mouseButton.x <= 510) &&
							event.mouseButton.y >= 580 && event.mouseButton.y <= 630)
							{
								tutorialMenu(event, texture, window);
							}

							// Exit
							else if ((event.mouseButton.x >= 350 && event.mouseButton.x <= 460) &&
							event.mouseButton.y >= 700 && event.mouseButton.y <= 760)
							{
								window.close();
							}
							break;
						}
					}
					break;
				}
			}
		}
		window.draw(sprite);
		window.display();
	}
}