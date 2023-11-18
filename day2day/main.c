#include <stdio.h>
#include <conio.h>
void swap(int,int);
void main()
{
    int a,b;
    printf("Enter two numbers");
    scanf("%d %d",&a,&b);
    swap(a,b);
    printf("\nThe first number is :%d ",a);
    printf("\nThe second number is :%d ",b);

}
void swap(int x,int y)
{
    int c;
    c=x;
    x=y;
    y=c;
    printf("\nThe first number is :%d ",x);
    printf("\nThe second number is :%d ",y);
}
