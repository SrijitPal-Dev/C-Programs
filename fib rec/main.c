#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k;
  printf("Enter the limit");
  scanf("%d",&n);
  printf("0 1 ");
  for(int i=1;i<=n-2;i++)
  {


  printf("%d ",fib(i));
  }


    return 0;
}
int fib(int n)
{
    if(n==1)
        return 1;
    if(n==0)
        return 1;
    else
        return fib(n-1)+fib(n-2);

}
