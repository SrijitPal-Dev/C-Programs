#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node* left;
    struct node* right;
};
struct node* head;
int l=0;
int insert_beg()
{
    int data;
    printf("Enter the element : ");
    scanf("%d",&data);
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        newnode->left=NULL;
        newnode->right=NULL;
    }
    else
    {
        newnode->left=NULL;
        newnode->right=head;
        head->left=newnode;
    }
    newnode->info=data;
    head=newnode;
    l++;
    return 0;
}
int insert_end()
{
    int data;
    struct node *p;
    p=head;
    printf("Enter the element : ");
    scanf("%d",&data);
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=data;
    newnode->right=NULL;
    if(head==NULL)
    {
        head=newnode;
        newnode->right=NULL;
        newnode->left=NULL;
    }
    else
    {
        while(p->right!=NULL)
        p=p->right;
        p->right=newnode;
        newnode->left=p;
    }
    l++;
    return 0;
}
int insert_any()
{
    int data,ps,i;
    struct node *p,*r;
    p=head; r=head;
    printf("Enter the element : ");
    scanf("%d",&data);
    printf("Enter the position of insertion : ");
    scanf("%d",&ps);
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=data;
    if(head!=NULL)
    {
    if(ps==1)
    {
        newnode->right=head;
        head->left=newnode;
        head=newnode;
    }
    else if(ps==l+1)
    {
        p=head;
        while(p->right!=NULL)
            p=p->right;
        p->right=newnode;
        newnode->left=p;
        newnode->right=NULL;
    }
    else if(ps>1&&ps<=l)
    {
        p=head; r=head;
        for(i=1;i<=ps-1;i++)
            p=p->right;
        while((r->right)!=p)
            r=r->right;
        newnode->right=p;
        p->left=newnode;
        r->right=newnode;
        newnode->left=r;
    }
    else
        printf("Wrong Position!");
    }
    else
    {
        if(ps<1||ps>l+1)
            printf("Wrong Position\n");
        else
        {
        head=newnode;
        newnode->right=NULL;
        newnode->left=NULL;
        }
    }
    l++;
    return 0;
}
int del_beg()
{
    struct node *p;
    if(head!=NULL)
    {
        p=head->right;
        free(head);
        head=p;
    }
    else
        printf("No elements to delete");
    l--;
    return 0;
}
int del_end()
{
    struct node *p=head;
    struct node *q;
    if(head!=NULL)
    {
        if(head->right!=NULL)
    {
        while((p->right)->right!=NULL)
            p=p->right;
        q=p;
        free(p->right);
        q->right=NULL;
    }
    else
    {

        free(head);
        head=NULL;
    }
    }
    l--;
    return 0;
}
int del_any()
{
    struct node *p,*r;
    p=head; r=head;
    int ps,i=0;
    printf("Enter the position of deletion : ");
    scanf("%d",&ps);
    if(ps<=0||ps>l)
        printf("Invalid position\n");
    else if(ps==1)
        del_beg();
    else if(ps==l)
        del_end();
    else
    {
        for(i=1;i<=ps-1;i++)
        p=p->right;
        while((r->right)!=p)
            r=r->right;
        r->right=p->right;
        (p->right)->left=r;
        free(p);
        l--;
    }
    return 0;
}
int reverse()
{
    if(head!=NULL)
    {
        if(head->right!=NULL)
    {
        struct node *p=head;
        struct node *q=p->right;
        p->right=NULL;
        p->left=q;
        p=q;
        while(p->right!=NULL)
        {
            p=p->right;
            q->right=head;
            q->left=p;
            head=q;
            q=p;
        }
        p->right=head;
        p->left=NULL;
        head=p;
    }
    }
    return 0;
}
int display()
{
    struct node *p;
    p=head;
    printf("Elements are :\n");
    while(p!=NULL)
    {
        printf("%d-->>",p->info);
        p=p->right;
    }
    printf("NULL\n");
    return 0;
}
int main()
{
    int ch;
    printf("1 to insert from beginning\n2 to insert from end\n3 to insert from any position\n4 to delete from beginning\n5 to delete from end\n6 to delete from any position\n7 to reverse\n8 to exit\n");
    do
    {
        printf("Enter a choice : ");
    scanf("%d",&ch);
        switch(ch)
    {
    case 1:
        {
            insert_beg();
            display();
            break;
        }
    case 2:
        {
            insert_end();
            display();
            break;
        }
    case 3:
        {
            insert_any();
            display();
            break;
        }
    case 4:
        {
            del_beg();
            display();
            break;
        }
    case 5:
        {
            del_end();
            display();
            break;
        }
    case 6:
        {
            del_any();
            display();
            break;
        }
    case 7:
        {
            reverse();
            display();
            break;
        }
    case 8:
        {
            exit(0);
            break;
        }
    default:
        printf("Wrong choice!Input again\n");

    }
    }while(1);
}
