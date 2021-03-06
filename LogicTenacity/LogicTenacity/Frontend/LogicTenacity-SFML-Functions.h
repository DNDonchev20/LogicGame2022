#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstdlib>

void gamemodeOptionMenu(sf::Event event, sf::Texture texture, sf::RenderWindow& window);

void playMenu(sf::Event event);

void tutorialMenu(sf::Event event, sf::Texture texture, sf::RenderWindow& window);

void howToPlayMenu(sf::Event event, sf::Texture texture, sf::RenderWindow& window);

void startupMenu();