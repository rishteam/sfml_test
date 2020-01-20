#pragma once

#include <SFML/Graphics.hpp>

#include <unordered_map>
#include <string>
#include <exception>

std::string toString(sf::Keyboard::Key key);
std::string toString(sf::Mouse::Button btn);
std::string toString(sf::Mouse::Wheel wh);