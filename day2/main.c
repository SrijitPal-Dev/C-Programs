#include<stdio.h>
void swap(int x,int y);
int main()
{
    int a,b;
    printf("Enter two numbers");
    scanf("%d%d",&a,&b);
    swap(a,b);
    return 1;
}
void swap(int x,int y)
{
    int c;
    c=x;
    x=y;
    y=c;
    printf("\n%d %d",x,y);

}
