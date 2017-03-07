// TronServerW32.cpp : Defines the entry point for the console application.
//

#include <Server/stdafx.h>
#include <iostream>
#include <memory>

#include "Server.h"




int main()
{
	Server* apple = new Server();
	std::unique_ptr<Server> server;
	std::cout << "Searching for life signs...";
	while (true)
	{
		server->runServer();
		std::cin.get();
		
	}

    return 0;
}

