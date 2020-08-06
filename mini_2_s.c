#include<stdlib.h>
#include<stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
//#include<netinet/in.h>
#include <arpa/inet.h>



int main()
 {
  int isockfd,port=8001; 
  char carrbuf[100];
  char carrsend_data[100]="START";
 while(1) {
  isockfd=socket(AF_INET,SOCK_STREAM,0);
  int dummysockfd;
  struct sockaddr_in serveraddr,clientaddr; 
  
  int iclientlength=sizeof(clientaddr);

      	serveraddr.sin_family=AF_INET; 
        serveraddr.sin_port=htons(port); 
        serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
  
    bind(isockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
     
     listen(isockfd,10); 

     dummysockfd=accept(isockfd,(struct sockaddr*)&clientaddr,&iclientlength); 
      send(dummysockfd,carrsend_data,sizeof(carrsend_data),0);

      recv(dummysockfd,carrbuf,sizeof(carrbuf),0);
      printf("%s",carrbuf);
  	  
      
      exit(dummysockfd);
      port++;}

  }
     
      
   
