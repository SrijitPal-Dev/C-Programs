#include <stdio.h>
#include <stdlib.h>
int *a,*b,*c;
int p,q;
sort(int *arr,int k)
{
int i,j,temp=0;
for(i=0;i<k;i++)
{
for(j=0;j<k-i;j++)
{
if(arr[j]>arr[j+1])
{
temp=arr[j+1];
arr[j+1]=arr[j];
arr[j]=temp;
}
}
}
}
int main()
{
int i=0,k=0;
printf("Enter array 1 size : ");
scanf("%d",&p);
a=(int *)malloc(p*sizeof(int));
printf("Enter array 1 elements : ");
for(i=0;i<p;i++)
scanf("%d",&a[i]);
printf("Enter array 2 size : ");
scanf("%d",&q);
b=(int *)malloc(q*sizeof(int));
printf("Enter array 2 elements : ");
for(int i=0;i<q;i++)
scanf("%d",&b[i]);
c=(int *)malloc((p+q)*sizeof(int));
for(i=0;i<p;i++)
{
c[k]=a[i];
k++;
}
for(i=0;i<q;i++)
{
c[k]=b[i];
k++;
}
sort(c,k-1);
for(i=0;i<k;i++)
    printf("%d ",c[i]);
if(k%2==1)
printf("Median : %d",c[(k+1)/2-1]);
else
printf("Median : %f",(c[k/2-1]+c[(k/2)])/2.0);
return 0;
}
