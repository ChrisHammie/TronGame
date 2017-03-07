#pragma once

//#include "stdafx.h"

#include <iostream>
#include <future>
#include <string>

#include <SFML\Network.hpp>

using TcpClient = sf::TcpSocket;
using TcpClientPtr = std::unique_ptr<TcpClient>;
using TcpClients = std::vector<TcpClientPtr>;
const sf::IpAddress SERVER_IP("127.0.0.1");
constexpr int SERVER_TCP_PORT(53000);



class Client
{
public:
	Client();
	~Client();

	void client();
	bool connect(TcpClient& socket);
	void input(TcpClient& socket);


};

