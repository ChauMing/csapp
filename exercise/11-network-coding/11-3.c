#include <csapp.c>

int main(int argc, char **argv) {
  unsigned int i_addr;
  struct in_addr inaddr;

  if(argc != 2) {
    fprintf(stderr, "usage: %s <char[16]>\n", argv[0]);
    exit(0);
  }

  inet_aton(argv[1], &inaddr);
  i_addr = htonl(inaddr.s_addr);

  printf("%x\n", i_addr);

  return 0;
}