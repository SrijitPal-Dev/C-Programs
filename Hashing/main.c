#include <stdio.h>
#include <stdlib.h>
#define n 999
struct node
{
    int info;
    int index;
    struct node *next;
}*head;
int key=0,i,rkey=0,val; int arr[n];
void insert(int size,int ch,int y)
{
    int hkey=0;
    for(i=0;i<size;i++)
    arr[i]=NULL;
    printf("Enter %d values :\n",size);
    for(i=0;i<size;i++)
    {
        scanf("%d",&val);
        key=val%size;
        if(arr[key]!=NULL)
        {
                for(int j=0;j<size;j++)
                {
                    if(ch==1)
                        rkey=(key+j)%size;
                    else if(ch==2)
                        rkey=(key+(j*j))%size;
                    else
                    {
                        hkey=1+(val%y);
                        rkey=(key+j*hkey)%size;
                    }
                    if(arr[rkey]==NULL)
                        break;
                }
                arr[rkey]=val;
        }
        else
            arr[key]=val;
        for(int p=0;p<size;p++)
            printf("%d -- >%d\n",p,arr[p]);
    }
}
void chain(int size,int val)
{
    struct node *p=head;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=val;
    newnode->index=val%size;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        while(p->next!=NULL)
        p=p->next;
        p->next=newnode;
    }
}
void display(int size)
{
    struct node *p=head;
    printf("Elements are :\n");
    for(i=0;i<size;i++)
    {
        p=head;
        printf("%d --> ",i);
        while(p!=NULL)
        {
            if(p->index==i)
                    printf("%d ",p->info);
            p=p->next;
        }
        printf("\n");
    }
}
int main()
{
    int ch,ch1,n1,y;
    printf("Enter size : ");
    scanf("%d",&n1);
    printf("SIZE : %d\n",n1);
    printf("HASH FUNCTION = Value Mod %d\n",n1);
    printf("Enter 1 for Open Addressing\n");
    printf("Enter 2 for Chaining\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("Enter 1 for Linear Probing [Rehash key=(hash(value)+i) Mod size for i=0,1,...size-1]\nEnter 2 for Quadratic Probing [Rehash key=(hash(value)+i*i) Mod size for i=0,1,...size-1]\nEnter 3 for Double Hashing [Rehash key=(hash(value)+i*hash2(vaue)) Mod size for i=0,1,...size-1]\n");
        scanf("%d",&ch1);
        switch(ch1)
        {
        case 1:
            insert(n1,ch1,0);
            break;
        case 2:
            insert(n1,ch1,0);
            break;
        case 3:
            printf("Enter H2 Key Value : ");
            scanf("%d",&y);
            printf("H2[KEY] = 1 + (Value Mod %d)\n",y);
            insert(n1,ch1,y);
            break;
        default:
            printf("Wrong choice!");
        }
    }
    else
    {
        while(1)
        {
            printf("Enter 1 for insertion\nEnter 2 for exit\n");
            scanf("%d",&ch1);
            switch(ch1)
            {
                case 1:
                    printf("Enter value : ");
                    scanf("%d",&val);
                    chain(n1,val);
                    display(n1);
                    break;
                case 2:
                    exit(0);
                    break;
                default:
                    printf("Wrong choice!");
            }
        }
    }
    return 0;
}
