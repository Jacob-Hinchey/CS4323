//Name: Jacob Hinchey
//EMail: Jacob.hinchey@okstate.edu
//Date: 02/27/2019
// This is where the user does their inputs. The user enters anything and the
// server returns a fortune

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

int main(){
    //Declare variables
    int clientSocket;
    int ret;
    struct sockaddr_in serverAddr;
    char buffer[1024];
    
    //Create a socket and make sure it is valid
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(clientSocket < 0){
        printf("Connection Error");
        exit(1);
    }
    
    //give the socket attributes and detail where it connects
    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    //Test the connection
    ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(ret <0){
        printf("Connection Error");
        exit(1);
    }
    
    //Where the user inputs
    while(1){
        printf("Connected to server!\n");
        printf("Type anything to get your fortune: ");
        scanf("%s", &buffer[0]);
        //sends the server a random user char array
        send(clientSocket, buffer, strlen(buffer), 0);
        //recieves the message from the server and makes sure it is valid
        if(recv(clientSocket, buffer, 1024, 0)<0){
            printf("Error in recieving");
        }
        else{
            printf("Server: \t%s\n", buffer);
        }
        // sends thank you to the server and disconnects
        send(clientSocket, "Thank You", strlen(buffer), 0);
        close(clientSocket);
        printf("Disconnected");
        exit(1);
        bzero(buffer, sizeof(buffer));
    }
    return 0;
}

