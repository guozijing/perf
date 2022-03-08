#include <stdio.h>

void test_little(void)
{
  int i,j;

  for(i = 0; i < 30000000; i++) 
    j=i; 
}

void test_mdedium(void)
{
  int i,j;

  for(i = 0; i < 60000000; i++) 
    j=i; 
}

void test_high(void)
{
  int i,j;

  for(i = 0; i < 90000000; i++) 
    j=i; 
}

void test_hi(void)
{
  int i,j;

  for(i = 0; i < 120000000; i++) 
    j=i; 
}

int main(void)
{
  int i, pid, result;

  for(i = 0; i<2; i++) {
    result = fork();
    if(result>0)
      printf("i=%d parent parent=%d current=%d child=%d\n", i, getppid(), getpid(), result);
    else
      printf("i=%d child parent=%d current=%d\n", i, getppid(), getpid());

    if(i==0)
    {
      test_little();
      sleep(1);
    } else {
      test_mdedium();
      sleep(1);
    }
  }

  pid = wait(NULL);
  test_high();
  printf("pid=%d wait=%d\n", getpid(), pid);
  sleep(1);
  pid = wait(NULL);
  test_hi();
  printf("pid=%d wait=%d\n", getpid(), pid);
  return 0;
}
