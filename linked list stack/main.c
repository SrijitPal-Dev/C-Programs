#include <stdio.h>
#include <stdlib.h>
#define n 10
struct node
{
    int info;
    struct node* next;
};
struct node* head;
int l=0;
void push()
{
    if(l==n)
        printf("Overflow!\n");
    else
    {
        int data;
    struct node *p;
    p=head;
    printf("Enter the element : ");
    scanf("%d",&data);
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=data;
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
    l++;
    }
}
void pop()
{
    if(l==0)
        printf("Underflow!\n");
    else
    {
        struct node *p=head;
    struct node *q;
    if(head!=NULL)
    {
        if(head->next!=NULL)
    {
        while((p->next)->next!=NULL)
            p=p->next;
        q=p;
        printf("%d\n",(p->next)->info);
        free(p->next);
        q->next=NULL;
    }
    else
    {
        free(head);
        head=NULL;
    }
    }
    l--;
        if(l==0)
            printf("Stack is Empty\n");
    }
}
void display()
{
    struct node *p;
    p=head;
    printf("Elements are :\n");
    while(p!=NULL)
    {
        printf("%d ",p->info);
        p=p->next;
    }
}

int main()
{
    int ch;
    printf("1.To Push\n2.To Pop\n3.To exit\n");
    do
    {
        //printf("\nArray size is %d and remaining space is %d\n",n,(n-top-1));
        printf("\nEnter choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push();
                display();
                break;
            case 2:
                pop();
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
