#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <cstdlib>
#include <unistd.h>
#include <netinet/in.h> // Для sockaddr_in
#include <arpa/inet.h>  // Для htons и inet_pton

int main(int argc, char *argv[])
{
    int sock = socket(AF_INET, SOCK_STREAM, 0); // Создаём TCP сокет

    if (sock < 0)
    {
        perror("socket");
        return 1;
    }

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    int opt = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    if (bind(sock, (sockaddr *)&addr, sizeof(addr)) < 0)
    {
        std::cout << "Не удалось связать сокет сервера с адресом." << std::endl;
        return 1;
    }
    else
    {
        std::cout << "Порт открыт" << std::endl;
    }

    if (listen(sock, 5) == 0)
    {
        std::cout << "Сокет стал в режим прослушки" << std::endl;

        int client; // Файловый дескриптор клиента

        if ((client = accept(sock, nullptr, nullptr)) < 0)
        {
            std::cout << "Не получилось соединится с клиентом" << std::endl;
            close(sock);
            return -1;
        }
        else
            std::cout << "Успешное соединение с клиентом" << std::endl;

        char buf[1025]; // Сообщение которое пришлёт клиент
        int bytes_read = recv(client, buf, 1025, 0);

        if (bytes_read < 0)
        {
            perror("recv");
        }
        else if (bytes_read == 0)
        {
            std::cout << "Клиент отключился" << std::endl;
        }
        else
        {
            buf[bytes_read] = '\0'; // ВАЖНО
            std::cout << "Сообщение: " << buf << std::endl;
        }

        close(client);
    }
    else
    {
        close(sock);
        std::cout << "Не удалось прослушать сокет" << std::endl;
        return 1;
    }

    close(sock);

    return 0;
}