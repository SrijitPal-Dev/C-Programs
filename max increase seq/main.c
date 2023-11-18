#include <stdio.h>
#include <stdlib.h>
#define n 11
int arr[n]; int a[999];
void input()
{
    printf("Enter array elements\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
}
int max()
{
    int c=1,max=1;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i+1]>arr[i])
        {
            c++;
            if(c>max)
                max=c;
        }
        else
            c=1;
    }
    return max;
}
int main()
{
    int i,j,c=0,x=0;
    input();
    printf("Max seq : %d \n",max());
    for(i=0;i<n;i++)
    {
        a[c++]=arr[i];
        for(j=i;j<n-1;j++)
        {
            if(arr[j+1]>arr[j])
                a[c++]=arr[j+1];
            else
                break;
        }
        if(c==max())
        {
            for(x=0;x<c;x++)
                printf("%d ",a[x]);
            printf("\n");
        }
        c=0;
    }
    return 0;
}
