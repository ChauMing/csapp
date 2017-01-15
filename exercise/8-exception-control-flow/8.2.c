#include <csapp.c>

int main(int argc, char const *argv[])
{
  int x = 1;
  if(Fork() == 0)
    printf("printf1: x = %d\n", ++x);
  printf("printf2: x = %d\n", --x);
  return 0;
}
/*
  输出
  printf2: x = 0
  printf1: x = 2
  printf2: x = 1
 */