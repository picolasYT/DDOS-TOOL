#include <string>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

int main() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);SOCKADDR_INserver;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY; // Escuchar en todas las interfaces de red
    server.sin_port = htons(12345); // Puerto de escucha

    bind(sock, (SOCKADDR*)&server, sizeof(server));
    listen(sock, SOMAXCONN);
    SOCKET client_