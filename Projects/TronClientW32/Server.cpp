#include "Server.h"



Server::Server()
{
}


Server::~Server()
{
}

bool Server::bindServerPort(sf::TcpListener& listener)
{
	if (listener.listen(SERVER_TCP_PORT) != sf::Socket::Done)
	{
		std::cout << "Could not bind server port";
		std::cout << std::endl << "Port: " << SERVER_TCP_PORT;
		std::cout << std::endl;

		return false;
	}
	return true;
}

void Server::listen(sf::TcpListener & tcp_listener, sf::SocketSelector & selector, TcpClients & tcp_clients)
{
	while (true)
	{
		if (selector.wait())
		{
			//new connection request
			if (selector.isReady(tcp_listener))
			{
				connect(tcp_listener, selector, tcp_clients);
			}

			//message being recieved
			else
			{
				receiveMsg(tcp_clients, selector);
			}
		}
	}
}

void Server::connect(sf::TcpListener & tcp_listener, sf::SocketSelector & selector, TcpClients & tcp_clients)
{
	auto client_ptr = std::make_unique<sf::TcpSocket>();
	auto& client_ref = *client_ptr;
	if (tcp_listener.accept(client_ref) == sf::Socket::Done)
	{
		selector.add(client_ref);
		tcp_clients.push_back(std::move(client_ptr));
	}
}

void Server::receiveMsg(TcpClients & tcp_clients, sf::SocketSelector & selector)
{
	auto sender = std::make_unique<TcpClients>();

	for (int i = 0; i < tcp_clients.size(); i++)
	{
		auto& sender_ref = *tcp_clients[i].get();
		if (selector.isReady(sender_ref))
		{
			std::cout << "Message Received" << std::endl;

			sf::Packet packet;
			tcp_clients[i].get()->receive(packet);

			std::string string;
			packet >> string;

			for (int i = 0; i < tcp_clients.size(); i++)
			{
				tcp_clients[i].get()->send(packet);
			}
		}
	}
}

void Server::runServer()
{
	sf::TcpListener tcp_listener;
	if (!bindServerPort(tcp_listener))
	{
		return;
	}

	sf::SocketSelector selector;
	selector.add(tcp_listener);

	TcpClients tcp_clients;
	return listen(tcp_listener, selector, tcp_clients);
}
