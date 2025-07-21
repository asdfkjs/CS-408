#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd, client_sockfd;//套接字操作系统通过一个整形id来区分
    struct sockaddr_in server_addr;
    socklen_t client_addrlen;


    // 创建套接字
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 设置服务器地址信息
    server_addr.sin_family = AF_INET;//进行ipv4通信
    server_addr.sin_port = htons(9999);//端口号转为网络字节序
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");//点分十进制的ip地址，转为32位整型数-网络字节序

    // 绑定套接字到服务器地址
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // 监听连接请求
    if (listen(sockfd, 5) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", 9999);


    // 接受客户端连接
    struct sockaddr_in client_addr;//用来存储客户端的ip地址和端口号
    client_addrlen = sizeof(client_addr);
    client_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_addrlen);
    if (client_sockfd < 0) {
        perror("Accepting connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // 接收客户端发送的数据
    char buffer[BUFFER_SIZE]={0};
    if (recv(client_sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }
    printf("Received from client: %s\n", buffer);//打印收到的内容

    // 发送数据给客户端
    strcpy(buffer, "Hello, client!");
    if (send(client_sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    // 关闭客户端套接字连接
    close(client_sockfd);


    // 关闭服务器套接字
    close(sockfd);

    return 0;
}
