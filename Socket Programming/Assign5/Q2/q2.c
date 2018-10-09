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


int main(int argc,char ** argv){

	struct in_addr addr;
	if(argc != 2){
		perror("usage : ./q2 <IP ADDRESS> ");
		exit(1);
	}
	inet_aton(argv[1],&addr);
	printf("%s\n",inet_ntoa(addr));
}

