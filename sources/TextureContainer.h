#ifndef _TEXTURES_H_
#define _TEXTURES_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class TextureContainer
{
public:
	enum Type
	{
		example1,
		example2
	};

	static std::map<Type, sf::Texture*> textures;
	static std::map<Type, int> counts;

	static void add(Type type);
	static void remove(Type type);
	static void debug();
	
private:
	static std::string typeToString(Type t);
};



#endif // !_TEXTURES_H_
