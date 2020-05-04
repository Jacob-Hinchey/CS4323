//Name: Jacob Hinchey
//EMail: Jacob.hinchey@okstate.edu
//Date: 02/27/2019
// This acts as the server for the fortune teller it takes the input file and extracts
// the fortunes from it to send to the user on the other terminal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 4444

int main(){
    //Declare variables
    int sockfd, ret;
    struct sockaddr_in serverAddr;

    int newSocket;
    struct sockaddr_in newAddr;

    socklen_t addr_size;

    char buffer[1024];
    pid_t childpid;

    //setup socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        printf("Connection Error");
        exit(1);
    }

    //give the socket attributes and detail where it connects
    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //Test the connection
    ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(ret <0){
        printf("Binding error");
        exit(1);
    }

    //Waits for input from client program
    //Ensures up to 50 clients can be connected at once
    if(listen(sockfd, 50)==0){
        printf("Waiting for client\n");
    }
    else{
        printf("Binding error");
    }

    while(1){
        //ensures newsocket is valid
        newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
        if(newSocket < 0){
            exit(1);
        }
        //tells where the connection is coming from
        printf("Connection accepted from %s:%d\n",inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
        if((childpid = fork())==0){
                //opens the fortunes file
                FILE *IN_FILE;
                IN_FILE = fopen("fortunes.txt", "r");
                close(sockfd);
                recv(newSocket, buffer, 1024, 0);
                //makes a true random number
                srand(time(NULL));
                int random = rand() % 10;
                //scans the correct file line for random number generated
                if(random == 0){
                    char fortune[47];
                    fgets(fortune, 47, IN_FILE);
                    send(newSocket, fortune, sizeof(fortune), 0);
                }
                else if(random == 1){
                    char fortune[47];
                    for(int i =0; i<2; i++){
                        fgets(fortune, 47, IN_FILE);
                    }
                    send(newSocket, fortune, sizeof(fortune), 0);
                }
                else if(random == 2){
                    char fortune[47];
                    for(int i =0; i<3; i++){
                        fgets(fortune, 47, IN_FILE);
                    }
                    send(newSocket, fortune, sizeof(fortune), 0);
                }
                else if(random == 3){
                    char fortune[47];
                    for(int i =0; i<4; i++){
                        fgets(fortune, 47, IN_FILE);
                    }
                    send(newSocket, fortune, sizeof(fortune), 0);
                }
                else if(random == 4){
                    char fortune[47];
                    for(int i =0; i<5; i++){
                        fgets(fortune, 47, IN_FILE);
                    }
                    send(newSocket, fortune, sizeof(fortune), 0);
                }
                else if(random == 5){
                    char fortune[47];
                    for(int i =0; i<6; i++){
                        fgets(fortune, 47, IN_FILE);
                    }
                    send(newSocket, fortune, sizeof(fortune), 0);
                }
                else if(random == 6){
                    char fortune[47];
                    for(int i =0; i<7; i++){
                        fgets(fortune, 47, IN_FILE);
                    }
                    send(newSocket, fortune, sizeof(fortune), 0);
                }
                else if(random == 7){
                    char fortune[47];
                    for(int i =0; i<8; i++){
                        fgets(fortune, 47, IN_FILE);
                    }
                    send(newSocket, fortune, sizeof(fortune), 0);
                }
                else if(random == 8){
                    char fortune[47];
                    for(int i =0; i<9; i++){
                        fgets(fortune, 47, IN_FILE);
                    }
                    send(newSocket, fortune, sizeof(fortune), 0);
                }
                else if(random == 9){
                    char fortune[47];
                    for(int i =0; i<10; i++){
                        fgets(fortune, 47, IN_FILE);
                    }
                    send(newSocket, fortune, sizeof(fortune), 0);
                }
                fclose(IN_FILE);
                //recieves "Thank You" from the client and prints to then
                //prints that it has disconnected
                recv(newSocket, buffer, 15, 0);
                printf("Client: %s\n", buffer);
                bzero(buffer, sizeof(buffer));
                printf("Disconnected from %s:%d\n",inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
        }
    }
    close(newSocket);
    return(0);

}
