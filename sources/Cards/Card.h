#ifndef _CARD_H_
#define _CARD_H_

#include <string>
#include "../Texture.h"

class Card : public sf::Drawable
{
public:
	Card();
	Card(int ID, int lvl, std::string name);
	~Card();

protected:
	int m_ID;
	int m_level;
	std::string m_filename;
	std::string m_name;
	std::string m_description;
	sf::Sprite m_sprite;

private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // !_CARD_H_
