#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    SOCKET clientSocket;
    struct sockaddr_in serverAddr;


    // 初始化Winsock库
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("Failed to initialize Winsock\n");
        return -1;
    }

    // 创建客户端套接字
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        printf("Failed to create socket\n");
        WSACleanup();
        return -1;
    }

    // 设置服务器地址和端口
    const char *serverIP = "127.0.0.1";  // 服务器IP地址
    const int serverPort = 9999;        // 服务器监听的端口号
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(serverIP);//将点分十进制，转换网络字节序
    serverAddr.sin_port = htons(serverPort);//将端口号转换为网络字节序

    // 连接到服务器，如果服务器那边没有在accept，那么这里请求5次后，就会失败
    if (connect(clientSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        printf("Failed to connect to server\n");
        closesocket(clientSocket);
        WSACleanup();
        return -1;
    }

    printf("Connected to server\n");

    // 发送数据
    char buffer[1024]="I am client,Wangdao niu";
    if (send(clientSocket, buffer, strlen(buffer), 0) == SOCKET_ERROR) {
        printf("Failed to send data\n");
        return -1;
    }

    // 接收数据
    int bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead <= 0) {
        printf("Connection closed by server\n");
        return -1;
    }

    // 添加字符串结束符
    buffer[bytesRead] = '\0';
    // 打印接收到的数据
    printf("Received: %s\n", buffer);


    // 关闭套接字和清理Winsock库，四次挥手
    closesocket(clientSocket);

    WSACleanup();

    return 0;
}