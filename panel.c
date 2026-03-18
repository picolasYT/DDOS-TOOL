SOCKET client_socket = accept(sock, NULL, NULL);

char buffer[256];while (true) {
    memset(buffer, 0, sizeof(buffer));
    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received <= 0) {
        break;
    }
    cout << "Mensaje recibido: " << buffer << endl;

    // Aquí puedes procesar los comandos recibidos del malware y enviar instrucciones de vuelta
    string command = "instrucción";send(client_socket, command.c_str(), command.length(),0);
}closesocket(client_socket);
closesocket(sock);
WSACleanup();
return 0;