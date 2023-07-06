#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
  int data;
};
int main()
{
  struct data mhs[10];
  for(int i = 0; i<10; i++)
  {
    printf("%d ", mhs[i].data);
  }
  printf("\n");
  memset(&mhs->data, 0, sizeof(mhs));
  for(int i = 0; i<sizeof(mhs); i++)
  {
    printf("%d ", mhs[i].data);
  }
  return 0;
}