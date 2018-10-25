#include "TextureContainer.h"

std::map<TextureContainer::Type, sf::Texture*> TextureContainer::textures;
std::map<TextureContainer::Type, int> TextureContainer::counts;

void TextureContainer::add(Type type)
{
	if (!textures[type])
	{
		textures[type] = new sf::Texture();
		textures[type]->loadFromFile(typeToString(type));
	}
	counts[type] += 1;
}

void TextureContainer::remove(Type type)
{
	if (counts[type] != 0)
	{
		counts[type] -= 1;
		if (counts[type] == 0)
		{
			delete textures[type];
		}
	}
}

void TextureContainer::debug()
{
	std::cout << "TEXTURE CONTAINER:" << std::endl << "Textures:" << std::endl;
	for (std::pair<Type, int> count : counts)
	{
		switch (count.first)
		{
		case TextureContainer::example1:
			std::cout << "example1: ";
			break;
		case TextureContainer::example2:
			std::cout << "example2: ";
			break;
		default:
			break;
		}
		std::cout << count.second << std::endl;
	}
}

std::string TextureContainer::typeToString(Type t)
{
	std::string stringType;
	switch (t)
	{
	case TextureContainer::example1:
		stringType = "resources/textures/example1.jpg";
		break;
	case TextureContainer::example2:
		stringType = "resources/textures/example2.jpg";
		break;
	default:
		stringType = "resources/textures/example1.jpg";
		break;
	}
	return stringType;
}
