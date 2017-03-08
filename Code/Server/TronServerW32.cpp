// TronServerW32.cpp : Defines the entry point for the console application.
//

#include <Server/stdafx.h>
#include <iostream>
#include <memory>

#include "Server.h"




int main()
{
	//Server* server = new Server();
	std::unique_ptr<Server> server;
	std::cout << "Searching for life signs...";
	//TronGame game;
	while (true)
	{
		//std::cin.get();
		server->runServer();
	}

	/*sf::Packet outPacket;
	outPacket << game;
	port.send(packet);

	port.receive(packet);
	packet >> game;*/
    return 0;
}

