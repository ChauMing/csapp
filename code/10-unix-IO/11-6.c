#include <csapp.h>

int main() {
  int fd1, fd2;
  fd1 = open("foo.txt", O_RDONLY, 0);
  fd2 = open("baz.txt", O_RDONLY, 0);
  close(fd2);
  fd2 = open("baz.txt", O_RDONLY, 0);
  printf("%d\n", fd2); // 4
  return 0;
}