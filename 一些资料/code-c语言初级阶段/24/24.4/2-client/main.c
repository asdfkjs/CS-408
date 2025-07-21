#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 9999
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // 创建套接字
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 设置服务器地址信息
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);//把端口变为网络字节序
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {//把ip地址变为网络字节序
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    // 连接到服务器
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // 发送数据到服务器
    strcpy(buffer, "Hello, server!");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    // 接收服务器发送的数据
    memset(buffer, 0, BUFFER_SIZE);//把buffer中的数据全部填写为0
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    printf("Received from server: %s\n", buffer);

    // 关闭连接
    close(sockfd);

    return 0;
}
