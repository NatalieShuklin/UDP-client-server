////
//// Created by natashashuklin on 2/22/23.
////
//
//#include <iostream>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <unistd.h>
//#include <netdb.h>
//#include <cstring>
//#include<stdlib.h>
//#include <sys/types.h>
//#include <stdio.h>
//#include <arpa/inet.h>
//
//
//#include <climits>
//
//#define PORT 8080
//
//int main() {
//
//    char buffer[100];
//    char *hello = "Hello from client";
//    int sockfd, n;
//
//    struct sockaddr_in server;
//
//    if( (sockfd = socket(AF_INET, SOCK_DGRAM,0))< 0) {
//        perror("socket creation failed");
//        exit(EXIT_FAILURE);
//    }
//
//    memset(&server, 0, sizeof(struct sockaddr_in));
//
//    //fill server info
//
//    server.sin_family = AF_INET;
//    server.sin_port = htons(8080);
//    server.sin_addr.s_addr = inet_addr("127.0.0.1");
//
//
//    socklen_t len;
//    // while(true) {
//    sendto(sockfd, (char *) hello, strlen(hello), MSG_CONFIRM, (struct sockaddr *) &server,
//           sizeof(struct sockaddr_in));
//
//    std::cout << "Hello message sent." << std::endl;
//
//    n = recvfrom(sockfd, (char *) buffer, 1000,
//                 MSG_WAITALL, (struct sockaddr *) &server,
//                 &len);
//    buffer[n] = '\0';
//    std::cout << "Server :" << buffer << std::endl;
//    // }
//    close(sockfd);
//    return 0;
//
//}
//
//
