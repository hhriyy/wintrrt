#include "WINtrrt.h"

int main(int argc, char** argv)
{
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);

    SOCKET s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s == INVALID_SOCKET) {
        printf("socket error: %d\n", WSAGetLastError());
        return 1;
    }

    struct sockaddr_in addr;
    ZeroMemory(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(40001);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    const char* msg = "hello";

    int sent = sendto(s, msg, strlen(msg), 0, (struct sockaddr*)&addr, sizeof(addr));

    if (sent == SOCKET_ERROR) {
        printf("sendto error: %d\n", WSAGetLastError());
    }
    else {
        printf("sent %d bytes\n", sent);
    }

    closesocket(s);
    WSACleanup();
}