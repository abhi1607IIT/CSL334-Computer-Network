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

int main(int argc, char *argv[])
{
    struct hostent *lh = gethostbyname(argv[1]);

    if (lh){
    	printf("%s\n",lh->h_name);
    	printf("%d\n",lh->h_addrtype);
    	printf("%d\n",lh->h_length);
    	int i=0;
    	while((lh->h_aliases)[i]){
    		printf("%s\n",(lh->h_aliases)[i]);
    		i++;
    	}
    	i=0;
    	while((lh->h_addr_list)[i]){
    		printf("%s\n",(lh->h_addr_list)[i]);
    		i++;
    	}
    }
    else{
        herror("gethostbyname");
    }

    return 0;
}