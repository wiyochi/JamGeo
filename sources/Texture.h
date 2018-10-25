#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class Texture
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



#endif // !_TEXTURE_H_
