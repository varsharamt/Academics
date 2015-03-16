#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<unistd.h>

main()
{
    int sd,len,bi,nsd,port,res,c1,c2,i,n;
  
    int first[7],first1[7];
    struct sockaddr_in ser,cli;

    if((sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==-1)
    {
        printf("\nSocket problem");
        return 0;
    }

    printf("\nSocket created\n");
    bzero((char*)&cli,sizeof(ser));
    printf("ENTER PORT NO:\n");
    scanf("%d",&port);
    printf("\nPort Address is %d\n:",port);
    ser.sin_family=AF_INET;
    ser.sin_port=htons(port);
    ser.sin_addr.s_addr=htonl(INADDR_ANY);
    bi=bind(sd,(struct sockaddr *)&ser,sizeof(ser));

    n=sizeof(cli);
    listen(sd,5);
    nsd = accept(sd,((struct sockaddr *)&cli),&i);

    if(nsd==-1)
    {
        printf("\nCheck the description parameter\n");
        return 0;
    }

    printf("\nConnection accepted!");

	for(i=0;i<7;i++) {
	  n = recv(nsd,&c1,1,0);
	  first[i]=n;
	  n = recv(nsd,&c2,1,0);
	  first1[i]=n;
	}
	for(i=0;i<7;i++) {
		res=first[i]+first1[i];
		send(nsd,&res,sizeof(res),0);
	}

	

	close(sd);
        close(nsd);
        return 0;

   
}
