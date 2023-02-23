#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <netdb.h>
#include <cstring>

#include <climits>

#define PORT 8080

int main() {

    int sockfd;
    char myname[HOST_NAME_MAX+1];
    struct sockaddr_in server_add, client_add;
    struct hostent * hp;
    const char *hello = "Hello from server";
    char buffer[255];

//
//    //get hostname
//    gethostname(myname, HOST_NAME_MAX);
//    hp = gethostbyname(myname);  //get my ip

    //1 - STEP "buying a phone"
    memset(&server_add, 0 , sizeof(struct sockaddr_in));

   // memset(&client_add, 0 , sizeof(struct sockaddr_in));

//    server_add.sin_family = hp->h_addrtype;  //(af_inet)   //filling server info
//
//    //inet_aton(SRV_IP, &si_other.sin_addr) #define SRV_IP "999.999.999.999" || INADDR_ANY
//    memcpy(&server_add.sin_addr.s_addr, hp->h_addr, hp->h_length);

    server_add.sin_addr.s_addr = htonl(INADDR_ANY);
    server_add.sin_family =AF_INET;

    //convert port num from host to network byte order
    server_add.sin_port = htons(PORT);

    if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ){
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
   bind(sockfd, (struct sockaddr*)&server_add, sizeof(struct sockaddr_in));

    //2 - STEP "enter sim to phone", bind address to socket
//    if((b = bind(sockfd, (struct sockaddr*)&server_add, sizeof(struct sockaddr_in))) < 0){
//        perror("bind failed");
//        exit(EXIT_FAILURE);
//    }

    socklen_t len;
    int n;

    len = sizeof(client_add);
    while(true) {
        n = recvfrom(sockfd, (char *) buffer, 255, MSG_WAITALL, (struct sockaddr *) &client_add, &len);
        buffer[n] = '\0';

        printf("Client : %s\n", buffer);

        sendto(sockfd, (const char *) hello, strlen(hello),
               MSG_CONFIRM, (const struct sockaddr *) &client_add,
               len);
        std::cout << "Hello message sent." << std::endl;
    }
    return 0;
}
