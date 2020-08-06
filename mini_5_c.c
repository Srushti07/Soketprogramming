#include<stdlib.h>
#include<stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
//#include<netinet/in.h>
#include <arpa/inet.h>

int main()

{

    int isockfd;

    char carrbuf[100];

    char carrsenddata[100]="SYIT";

  isockfd=socket(AF_INET,SOCK_DGRAM,0);


    struct sockaddr_in serveraddr;


    int iserverlength=sizeof(serveraddr);



    serveraddr.sin_family=AF_INET;

    serveraddr.sin_port=htons(9000);

    serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");

    

    

   sendto(isockfd,carrsenddata,sizeof(carrsenddata),0,(struct sockaddr *)&serveraddr,iserverlength);

    recvfrom(isockfd,carrbuf,sizeof(carrbuf),0,(struct sockaddr *)&serveraddr,&iserverlength);

    printf("%s",carrbuf);




    close(isockfd);



} 