#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../Frontend/Frontend-Functions.h"
#include "../Backend/LogicTenacity-Functions.h"

using namespace std;

// main menu
void startupMenu()
{
	sf::RenderWindow window{ sf::VideoMode(800,890), "Boole0", sf::Style::Titlebar | sf::Style::Close };

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