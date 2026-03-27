#include <iostream>
#include <cstdlib>
#include <thread>
#include "sqliteDB/sqlite3.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> // Для sockaddr_in
#include <arpa/inet.h>  // Для htons и inet_pton

void handle_user(int client_soc, std::string ip_addr)
{
    sqlite3 *db;

    if (sqlite3_open("my_database.db", &db) != SQLITE_OK)
    {
        std::cerr << "DB error: " << sqlite3_errmsg(db) << std::endl;
        close(client_soc);
        return;
    }

    char buf[1025];
    int bytes_read;

    while (true)
    {
        bytes_read = recv(client_soc, buf, 1024, 0);

        if (bytes_read > 0)
        {
            std::string message(buf, bytes_read);

            std::cout << "Сообщение: " << message << std::endl;

            if (send(client_soc, "OK", 2, 0) < 0)
            {
                perror("send");
            }

            const char *sql = "INSERT INTO messages (content, client_ip) VALUES (?, ?);";
            sqlite3_stmt *stmt;

            if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK)
            {
                sqlite3_bind_text(stmt, 1, message.c_str(), -1, SQLITE_TRANSIENT);
                sqlite3_bind_text(stmt, 2, ip_addr.c_str(), -1, SQLITE_TRANSIENT);

                if (sqlite3_step(stmt) != SQLITE_DONE)
                {
                    std::cerr << "Ошибка записи: " << sqlite3_errmsg(db) << std::endl;
                }

                sqlite3_finalize(stmt);
            }
            else
            {
                std::cerr << "Prepare error: " << sqlite3_errmsg(db) << std::endl;
            }
        }
        else if (bytes_read == 0)
        {
            std::cout << "Клиент отключился" << std::endl;
            break;
        }
        else
        {
            perror("recv");
            break;
        }
    }

    sqlite3_close(db);
    close(client_soc);
    std::cout << "Соединение закрыто в потоке." << std::endl;
}

int main()
{
    sqlite3 *db;
    // SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE — откроет или создаст файл
    int rc = sqlite3_open("my_database.db", &db);

    if (rc != SQLITE_OK)
    {
        std::cerr << "Ошибка: " << sqlite3_errmsg(db) << std::endl;
    }
    else
    {
        std::cout << "SQLite работает! Версия: " << sqlite3_libversion() << std::endl;
    }

    const char *createTableSQL = "CREATE TABLE IF NOT EXISTS messages (id INTEGER PRIMARY KEY, content TEXT, client_ip TEXT);";
    char *errMsg = nullptr;
    sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errMsg);

    int sock = socket(AF_INET, SOCK_STREAM, 0); // Создаём TCP сокет

    if (sock < 0)
    {
        perror("socket");
        return 1;
    }

    sockaddr_in addr{};
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

    // 2. ЗАПУСК ПРОСЛУШКИ
    if (listen(sock, 10) < 0)
    {
        perror("listen");
        return 1;
    }
    std::cout << "Сервер запущен, ожидаем клиентов..." << std::endl;

    while (true)
    {
        std::cout << "Сокет стал в режим прослушки" << std::endl;

        sockaddr_in client_addr{};
        socklen_t client_len = sizeof(client_addr);

        int client = accept(sock, (struct sockaddr *)&client_addr, &client_len);

        if (client < 0)
        {
            perror("accept");
            continue;
        }

        if (client >= 0)
        {
            // Преобразуем адрес в строку
            char ip_str[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &client_addr.sin_addr, ip_str, INET_ADDRSTRLEN);

            std::cout << "Подключился: " << ip_str << std::endl;

            std::cout << "Новое подключение! Создаем поток..." << std::endl;

            // Передаем IP строкой в поток
            std::thread(handle_user, client, std::string(ip_str)).detach();
        }
    }

    sqlite3_close(db);

    close(sock);

    return 0;
}