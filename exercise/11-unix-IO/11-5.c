#include <csapp.h>

int main() {
  int fd1, fd2;
  char c;
  fd1 = open("foobar.txt", O_RDONLY, 0);
  fd2 = open("foobar.txt", O_RDONLY, 0);
  read(fd2, c, 1);
  dup2(fd2, fd1);
  read(fd1, c, 1);
  printf("%c\n", c);
  return 0;
}

/**
 * 答案 o
 * dup2 将 fd1指向 fd2的文件表项, 所以读 fd1 会从 fd2 读过的部分继续读
 */