#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int sd,con,port,l,r,i=0,j,p,n1=0,n2=0,k=1,c1,c2,quotient,quo,m,res;
    int a[4],bin[7],bin1[7],text[7];
    struct sockaddr_in cli;

    if((sd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP))==-1)
    {
        printf("\nSocket problem");
        return 0;
    }

    bzero((char*)&cli,sizeof(cli));
    cli.sin_family = AF_INET;
    printf("ENTER PORT NO:\n");
    scanf("%d",&port);
    cli.sin_port=htons(port);
    cli.sin_addr.s_addr=htonl(INADDR_ANY);

    con=connect(sd,(struct sockaddr*)&cli,sizeof(cli));

    if(con==-1)
    {
        printf("\nConnection error");
        return 0;
    }

	 printf("Enter the numbers b1 and b2");
        scanf("%d%d",&b1,&b2);
	printf("Enter Values for p,q1,q2,r1,r2, respectively..");
	for(r=0;r<5;r++) {	
	   scanf("%d",&a[l]);
        }
		
	quotient = n1;
	printf("\nrr\n");
	printf("quott: %d\n",quotient);
	while(quotient!=0){

         bin[i++]= quotient % 2;

         quotient = quotient / 2;
	printf("quotient : %d\n",quotient);
        }
	quo = n2;
	printf("quo: %d\n",quo);
	i=0;
	while(quo!=0){
	printf("ssss\n");
         bin1[i++]= quo % 2;
	 printf("%d\n",quo);
         quo = quo / 2;
	printf("%d\n",quo);

        }
	printf("Sending the cipher to server");
	p=a[0];
	for(j = 7 ; j> 0 ; j--){
		c1=(a[0]*a[1])+(2*a[3])+bin[j];
		c2=(a[0]*a[2])+(2*a[4])+bin1[j];
		 send(sd,&c1,sizeof(c1),0);
		 send(sd,&c2,sizeof(c2),0);
	}
	for(m=0;m<7;m++) {

	  l=recv(sd,&res,sizeof(res),0);
	  text[m] = l;
	}
	for(m=0;m<7;m++) {
		printf("%d",text);
	}
	close(sd);
    	return 0;  
   
}
