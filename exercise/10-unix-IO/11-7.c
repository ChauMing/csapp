#include "../../common/csapp.h"

int main() {
  int n;
  rio_t rio;
  char buf[MAXBUF];
  printf("%d\n",MAXBUF);

  rio_readinitb(&rio, STDIN_FILENO);
  while((n = rio_readnb(&rio, buf, MAXBUF)) != 0)
    rio_writen(STDOUT_FILENO, buf, n);
  return 0;
  return 0;
}