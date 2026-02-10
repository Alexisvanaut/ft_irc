#include "../include/ft_irc.hpp"

int main()
{
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (server_fd == INVALID_SOCKET)
	{
		std::cerr << "Erreur de creation socket" << std::endl;
		return 1;
	}
	std::cout << "Succes de creation socket" << std::endl;

	sockaddr_in server;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(6666);

	if (connect(server_fd, (struct sockaddr *)&server, sizeof(server)) != 0)
	{
		std::cout << "Erreur de connection" << std::endl;
		close(server_fd);
		return 1;
	}
	std::cout << "Socket connecte" << std::endl;
	close(server_fd);
	return (0);
}
