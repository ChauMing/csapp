#include <stdio.h>
#include <csapp.c>

int main(int argc, char const *argv[])
{
  if(Fork() == 0) {
    printf("a");
    fflush(stdout);
  } else {
    printf("b");
    fflush(stdout);
    waitpid(-1, NULL, 0); // -1等待所有子进程返回
  }
  printf("c");
  fflush(stdout);
  return 0;
}
/**
可能的结果有
acbc
abcc
bacc
bacc
 */