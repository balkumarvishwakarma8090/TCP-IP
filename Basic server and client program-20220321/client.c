/****TCP client******/
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
#include<strings.h>
int main()
{
  int sfd;
  struct sockaddr_in cln;
  char wrbuf[128];
  /***1) create a socket **********/
  printf("Creating a socket^^^^^^^^^.\n");
  sfd= socket(AF_INET,SOCK_STREAM,0);
  if(sfd<0)
  {
    perror("socket");
    return 0;
  }
  printf("Socket created successfully!!!!!!!!!!!!!!!!!!!.\n");
  /*****end of socket creation******/

  /*2) assign address information to the socket address structure members****/
    cln.sin_family      = AF_INET;
    cln.sin_addr.s_addr = inet_addr("127.0.0.1");
    cln.sin_port        = htons(2030); 
  /**************************************************************/

 /**3) establish the connection with server ******/
   if(connect(sfd,(struct sockaddr *)&cln,sizeof(cln))==0)
      printf("Connection established successfully....\n");
   else
    {
      perror("connect");
      return 0;
    }
 /**********************************************/

  /***4) client scan the input from keyboard and write to server***/
   printf("enter the data:");
   scanf("%[^\n]",wrbuf);
   write(sfd,wrbuf,strlen(wrbuf)+1);
  /****************************************************************/

}
