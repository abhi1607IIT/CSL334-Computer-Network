#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

#define MAXLINE 4096
	

int
main()
{
	int			i, listenfd, connfd;
	char			buff[MAXLINE];
	time_t			ticks;


        ticks = time(NULL);
        snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
	printf("%s", buff);


}

