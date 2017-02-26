#include <csapp.c>

int main(int argc, char **argv) {
  struct in_addr inaddr;
  unsigned int addr;

  if(argc != 2) {
    fprintf(stderr, "usage: %s <hex number>\n", argv[0]);
  }

  sscanf(argv[1], "%x", &addr);
  inaddr.s_addr = htonl(addr); // 小端字节序转大端字节序
  printf("%s\n", inet_ntoa(inaddr));

  return 0;
}