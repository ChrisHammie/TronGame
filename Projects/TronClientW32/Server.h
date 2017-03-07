#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <SFML\Network.hpp>

constexpr int SERVER_TCP_PORT(53000);
constexpr int SERVER_UDP_PORT(53001);

using TcpClient = sf::TcpSocket;
using TcpClientPtr = std::unique_ptr<TcpClient>;
using TcpClients = std::vector<TcpClientPtr>;

class Server
{
public:
	Server();
	~Server();

	bool bindServerPort(sf::TcpListener& listener);
	void listen(sf::TcpListener& tcp_listener, sf::SocketSelector& selector, TcpClients& tcp_clients);
	void connect(sf::TcpListener& tcp_listener, sf::SocketSelector& selector, TcpClients& tcp_clients);
	void receiveMsg(TcpClients& tcp_clients, sf::SocketSelector& selector);
	void runServer();
};

