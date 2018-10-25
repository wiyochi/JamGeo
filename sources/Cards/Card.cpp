#include "Card.h"

Card::Card()
{
}

Card::Card(int ID, int lvl, std::string name) :
	m_ID(ID),
	m_filename("resources/textures/"),
	m_level(lvl),
	m_name(name)
{
	m_filename.append(std::to_string(m_ID));
	m_filename.append(".jpg");
}

Card::~Card()
{
}

void Card::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_sprite, states);
}
