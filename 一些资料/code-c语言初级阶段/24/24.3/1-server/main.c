#pragma comment(lib, "ws2_32.lib")

#include <stdio.h>
#include <winsock2.h>
#include <windows.h>


int main(int argc, char *argv[]) {
    //初始化WSA，加载winsock库，windows需要的步骤，Mac和Linux不需要这一步
    WORD sockVersion = MAKEWORD(2, 2);
    WSADATA wsaData;
    if (WSAStartup(sockVersion, &wsaData) != 0) {//初始化失败,退出
        return -1;
    }

    //创建套接字,ipv4,SOCK_STREAM代表初始化tcp套接字,TCP协议。如果是SOCK_DGRAM则是udp套接字
    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (slisten == INVALID_SOCKET) {
        printf("socket error !");
        return -1;
    }

    //绑定IP和端口
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;//代表进行ipv4,如果是ipv6,则为AF_INET6
    sin.sin_port = htons(9999);//端口号,字节序转换，小端转大端
    //127.0.0.1是本地回环地址，用于本地网络通信测试，也可以改为本机的IP地址
    sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//作用是将一个点分十进制的IP转换成一个网络字节序整数型数
    if (bind(slisten, (LPSOCKADDR) &sin, sizeof(sin)) == SOCKET_ERROR) {
        printf("bind error !");
        return -1;
    }

    //开始监听
    if (listen(slisten, 5) == SOCKET_ERROR) {
        printf("listen error !");
        return -1;
    }


    SOCKET sClient;//accept返回的新的套接字，使用sClient进行保存
    struct sockaddr_in remoteAddr;
    int nAddrlen = sizeof(remoteAddr);//计算remoteAddr的大小
    printf("Waiting for connection\n");//等待连接...
    //接受连接,返回一个新的套接字,这个套接字用于同连接的客户端通信，对方的地址信息保存在remoteAddr中
    sClient = accept(slisten, (SOCKADDR *) &remoteAddr, &nAddrlen);//这里完成了3次握手

    if (sClient == INVALID_SOCKET) {
        printf("accept error !");
        return -1;
    }
    //接受到一个连接,打印客户端的IP地址和端口号
    printf("Client connected from %s:%d\n", inet_ntoa(remoteAddr.sin_addr), ntohs(remoteAddr.sin_port));
    char revData[255];
    //接收数据，recv函数接收数据到缓冲区revData中，返回值是实际接收到的字节数，失败返回-1
    int ret = recv(sClient, revData, 255, 0);
    if (ret > 0) {
        revData[ret] = 0;//字符串放结束符
        printf("Received: %s\n",revData);//打印接收到的数据
    }
    //发送数据
    char *sendData = "hi,TCP Client";
    send(sClient, sendData, strlen(sendData), 0);//发送数据给客户端
    // 关闭套接字
    closesocket(sClient);//断开与客户端的连接，这里完成了4次挥手
    closesocket(slisten);//关闭监听，客户端不能connect了
    WSACleanup();//清理Winsock库,释放相关资源
    return 0;
}