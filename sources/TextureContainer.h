#ifndef _TEXTURES_H_
#define _TEXTURES_H_

#include <SFML/Graphics.hpp>

static class TextureContainer
{
public:
	typedef struct
	{
		sf::Texture texture;
		int count;
	} Texture;

	static std::map<std::string, Texture*> textures;
	static void add(std::string filename);
	
private:

};



#endif // !_TEXTURES_H_
