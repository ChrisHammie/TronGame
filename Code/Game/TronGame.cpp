#include "TronGame.h"
#include <SFML\Network.hpp>

sf::Packet& operator<<(sf::Packet& packet, const TronGame& game)
{
	packet << game.numberOfPlayers;
	packet << game.ganenamae;
	return packet;
}

sf::Packet& operator >> (sf::Packet& packet, TronGame& game)
{
	packet >> game.name;
	packet >> game.numberOfPlayers;
	return packet;
}
