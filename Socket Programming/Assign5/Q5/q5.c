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
    printf("Press 1 for gethostbyname and 2 for gethostbyaddr \n");
    int d;
    scanf("%d",&d);
    if(d==1){
        int argument;
        printf("Enter the number of the hostname to be considered \n");
        scanf("%d",&argument);
        struct hostent *lh = gethostbyname(argv[argument]);

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
    }
    else if (d==2){
        int argument;
        printf("Enter the number of the ip address to be considered \n");
        scanf("%d",&argument);
        struct in_addr addr;
        inet_pton(AF_INET,argv[argument],&addr);
        struct hostent *rh = gethostbyaddr(&addr,sizeof addr,AF_INET);
        if (rh){
            printf("%s\n",rh->h_name);
            printf("%d\n",rh->h_addrtype);
            printf("%d\n",rh->h_length);
            int i=0;
            while((rh->h_aliases)[i]){
                printf("%s\n",(rh->h_aliases)[i]);
                i++;
            }
            i=0;
            while((rh->h_addr_list)[i]){
                printf("%s\n",(rh->h_addr_list)[i]);
                i++;
            }
        }
        else{
            herror("gethostbyname");
        }
    }
    else{
        printf("Enter proper choice\n");
    }
        
    return 0;
}