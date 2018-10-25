#include "Texture.h"

std::map<Texture::Type, sf::Texture*> Texture::textures;
std::map<Texture::Type, int> Texture::counts;

void Texture::add(Type type)
{
	if (!textures[type])
	{
		textures[type] = new sf::Texture();
		textures[type]->loadFromFile(typeToString(type));
	}
	counts[type] += 1;
}

void Texture::remove(Type type)
{
	if (counts[type] != 0)
	{
		counts[type] -= 1;
		if (counts[type] == 0)
		{
			delete textures[type];
			textures[type] = nullptr;
		}
	}
}

void Texture::debug()
{
	std::cout << "TEXTURE CONTAINER:" << std::endl << "Textures:" << std::endl;
	for (std::pair<Type, int> count : counts)
	{
		switch (count.first)
		{
		case Texture::example1:
			std::cout << "example1: ";
			break;
		case Texture::example2:
			std::cout << "example2: ";
			break;
		default:
			break;
		}
		std::cout << count.second << std::endl;
	}
}

std::string Texture::typeToString(Type t)
{
	std::string stringType;
	switch (t)
	{
	case Texture::example1:
		stringType = "resources/textures/example1.jpg";
		break;
	case Texture::example2:
		stringType = "resources/textures/example2.jpg";
		break;
	default:
		stringType = "resources/textures/example1.jpg";
		break;
	}
	return stringType;
}
