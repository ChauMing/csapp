#include <csapp.h>

int main() {
  int fd1, fd2;
  char c;

  fd1 = open("foobar.txt", O_RDONLY, 0);
  fd2 = open("foobar.txt", O_RDONLY, 0);


  printf("fd1=%d, fd2=%d\n", fd1, fd2); // fd1 = 3, fd2 = 4
  
  read(fd1, &c, 1);
  read(fd2, &c, 1);
  printf("c=%c\n", c);
  return 0;
}

// 答案 f
// open 打开一个文件以后, 总是创建一个可用的最小的文件描述符
// 第一次 open foobar 时返回的是3
// 第二次 open foobar 时返回4
// 所以read fd1和 fd2时文件描述符不一样, 所以 c 第二次被写入为 fd2 文件描述符的第一个字节