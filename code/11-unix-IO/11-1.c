#include <csapp.h>
// #include <sys/types.h> 
// #include <sys/stat.h> 
// #include <fcntl.h> 
// #include <unistd.h>

int main(int argc, char const *argv[])
{
  int fd1, fd2;
  fd1 = open("foo.txt", O_RDONLY, 0);
  close(fd1);
  fd2 = open("baz.txt", O_RDONLY, 1);
  printf("fd2 = %d\n", fd2);
  return 0;
}

// 答案是3 
// 因为 文件描述符总是用最小的 
// (stdio 是0, stdout 是1, stderr 是2) 
// fd1打开文件时 是3 关闭以后3就没了, 
// fd2就用了3