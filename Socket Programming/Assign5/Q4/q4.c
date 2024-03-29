#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>


#define SERVER_ADDR "173.194.72.94"
#define SERVER_PORT 80

int main(int argc,char** argv)
{
	char myIP[16];
	unsigned int myPort;
	struct sockaddr_in server_addr, my_addr;
	int sockfd;

	if(argc != 2){
		perror("usage : ./q2 <IP ADDRESS> ");
		exit(1);
	}


	// Connect to server
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("Can't open stream socket.");
		exit(-1);
	}

	// Set server_addr
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	inet_aton(argv[1],&server_addr.sin_addr);
	server_addr.sin_port = htons(SERVER_PORT);

	// Connect to server
	if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
		perror("Connect server error");
		close(sockfd);
		exit(-1);
	}

	// Get my ip address and port
	bzero(&my_addr, sizeof(my_addr));
	int len = sizeof(my_addr);
	getsockname(sockfd, (struct sockaddr *) &my_addr, &len);
	printf("%s\n", inet_ntoa(my_addr.sin_addr) );
	inet_ntop(AF_INET, &my_addr.sin_addr, myIP, sizeof(myIP));
	myPort = ntohs(my_addr.sin_port);

	printf("Local ip address: %s\n", myIP);
	printf("Local port : %u\n", myPort);

	return 0;
}