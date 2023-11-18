#include <stdio.h>
#include <stdlib.h>
#define n 5
int arr[n],front=-1,rear=-1;
void enqueue()
{
    int item;
    if((rear==(front-1))||(front==0&&rear==n-1))
    {
        printf("Queue overflow");
        return;
    }
    printf("Enter the element : ");
    scanf("%d",&item);
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        arr[front]=item;
    }
    else
    {
        rear=(rear+1)%n;
        arr[rear]=item;
    }
}
void dequeue()
{
    if((front==-1) && (rear==-1))
    {
        printf("\nQueue is underflow");
        return;
    }
    else if((front==rear)&&(front!=-1))
    {
        front=rear=-1;
    }
    else
        front=(front+1)%n;
}
void display()
{
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty..");
    }
    else
    {
        printf("\nElements in a Queue are :");
        for(int i=front;i<=rear;i++)
            printf("%d ",arr[i]);
    }
}
int main()
{
    int ch;
    printf("1.To Enqueue\n2.To Dequeue\n3.To exit\n");
    do
    {
        printf("front=%d  rear=%d",front,rear);
        printf("\nEnter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                enqueue();
                display();
                break;
            case 2:
                dequeue();
                display();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Wrong input!\n");
        }
    }while(1);
    return 0;
}
