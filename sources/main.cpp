#include <SFML/Graphics.hpp>
#include "TextureContainer.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

	TextureContainer::add(TextureContainer::example1);
	sf::Sprite sprite;
	sprite.setTexture(*TextureContainer::textures[TextureContainer::example1]);
	sprite.setPosition(sf::Vector2f(20, 20));
	sprite.scale(sf::Vector2f(0.1f, 0.1f));
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				{
					TextureContainer::debug();
				}
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			TextureContainer::add(TextureContainer::example1);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			TextureContainer::remove(TextureContainer::example1);
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}

	return 0;
}