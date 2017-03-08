#include "Client.h"



Client::Client()
{
}


Client::~Client()
{
}

void Client::client()
{
	TcpClient socket;

	if (!connect(socket))
	{
		return;
	}

	auto handle = std::async(std::launch::async, [&]
	{
		// keep track of the socket status
		sf::Socket::Status status;
		do
		{
			sf::Packet packet;
			status = socket.receive(packet);
			if (status == sf::Socket::Done)
			{
				// TODO:
				std::string packetStore;
				packet >> packetStore;

				//std::cout << packetStore;

				//std::cout << std::endl;

			}
		} while (status != sf::Socket::Disconnected);

	});
	return input(socket);
}

bool Client::connect(TcpClient & socket)
{
	// attempt connection to server
	auto status = socket.connect(SERVER_IP, SERVER_TCP_PORT);
	if (status != sf::Socket::Done)
	{
		return false;
	}
	// if it works
	//std::cout << "Connected to server: " << SERVER_IP;
	//std::cout << std::endl;
	return true;
}

void Client::input(TcpClient & socket)
{
	//while (false)
	//{
	//	auto& sender_ref = socket;
	//	sf::Packet packet;
	//	//std::string message;

	//	//std::getline(std::cin, message);
	////	packet << message;

	//	socket.send(packet);
	//}
}
