#include <SFML/Graphics.hpp>
#include "Texture.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");

	Texture::add(Texture::example1);
	sf::Sprite sprite;
	sprite.setTexture(*Texture::textures[Texture::example1]);
	sprite.setPosition(sf::Vector2f(20, 20));
	sprite.scale(sf::Vector2f(0.1f, 0.1f));
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::D)
				{
					Texture::debug();
				}
				else if (event.key.code == sf::Keyboard::A)
				{
					Texture::add(Texture::example1);
				}
				else if (event.key.code == sf::Keyboard::Z)
				{
					Texture::add(Texture::example2);
				}
				else if (event.key.code == sf::Keyboard::R)
				{
					Texture::remove(Texture::example1);
				}
			}
		}

		

		window.clear();
		window.draw(sprite);
		window.display();
	}

	return 0;
}