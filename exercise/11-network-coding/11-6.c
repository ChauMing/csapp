#include <csapp.c>

void doit(int fd);
void read_requesthdrs(rio_t *rp, char *header);
void read_requestbody(rio_t *rp, char *body);

int main(int argc, char const *argv[])
{
  int listenfd, connfd, port, clientlen;
  struct sockaddr_in clientaddr;

  if(argc != 2) {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(0);
  }

  port = atoi(argv[1]);

  listenfd = Open_listenfd(port);

  while(1) {
    clientlen = sizeof(clientaddr);
    connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);
    doit(connfd);
    Close(connfd);
  }

  return 0;
}

void doit(int fd) {
  char res_header[MAXLINE], req_header[MAXLINE], body[MAXLINE];
  rio_t rio;

  Rio_readinitb(&rio, fd);
  read_requesthdrs(&rio, req_header);
  sprintf(res_header, "HTTP/1.1 200 OK\r\n");
  sprintf(res_header, "%sContent-type: text/html\r\n", res_header);
  sprintf(res_header, "%sContent-length: %lu\r\n\r\n",res_header, strlen(req_header));
  Rio_writen(fd, res_header, strlen(res_header));
  Rio_writen(fd, req_header, strlen(req_header));
}


void read_requesthdrs(rio_t *rp, char *header) {
  char buf[MAXLINE] = "hello world";

  while(strcmp(buf, "\r\n")) {
    Rio_readlineb(rp, buf, MAXLINE);
    sprintf(header, "%s%s", header, buf);
  }
  return;
}