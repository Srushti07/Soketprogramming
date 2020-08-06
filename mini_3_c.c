#include<stdlib.h>
#include<stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
//#include<netinet/in.h>
#include <arpa/inet.h>

int main() 
{ 
	int mainsockfd; 
	char carrbuf[100]; 
	char carrsend_data[100]="Done";
	
	mainsockfd=socket(AF_INET,SOCK_STREAM,0); 
	
	struct sockaddr_in serveraddr,clientaddr;
	
	int iclientlength=sizeof(clientaddr); 
	
	serveraddr.sin_family=AF_INET; 
	serveraddr.sin_port=htons(8001);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1"); 
	
	connect(mainsockfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr));
	
    recv(mainsockfd,carrbuf,sizeof(carrbuf),0); 
	send(mainsockfd,carrsend_data,sizeof(carrsend_data),0); 
    
    printf("%s",carrbuf); 
    
    exit(mainsockfd); 
}