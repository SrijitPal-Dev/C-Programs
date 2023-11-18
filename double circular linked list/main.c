#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node* left;
    struct node* right;
};
struct node* head;
int l=0,data,ps;
int insert_beg()
{
    struct node *p;
    if(l==1)
        p=head;
    int data;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        head=newnode;
        newnode->left=head;
        newnode->right=head;
    }
    else
    {
        p=head;
        while(p->right!=head)
            p=p->right;
        p->right=newnode;
        newnode->left=p;
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
    struct node *p=head;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=data;
    if(head==NULL)
    {
        head=newnode;
        newnode->right=head;
        newnode->left=head;
    }
    else
    {
        while(p->right!=head)
        p=p->right;
        p->right=newnode;
        newnode->left=p;
        newnode->right=head;
        head->left=newnode;
    }
    l++;
    return 0;
}
int insert_any()
{
    int i;
    struct node *p,*r;
    p=head; r=head;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=data;
    if(head!=NULL)
    {
    if(ps==1)
    insert_beg();
    else if(ps==l+1)
    {
        p=head;
        while(p->right!=head)
            p=p->right;
        p->right=newnode;
        newnode->left=p;
        newnode->right=head;
        head->left=newnode;
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
        newnode->right=head;
        newnode->left=head;
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
/*int del_end()
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
        printf("Invalid position");
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
}*/
int display()
{
    struct node *p;
    p=head;
    printf("Elements are :\n");
    if(p!=NULL)
    {
        while(p->right!=head)
    {
        printf("|%d|",p->left);
        printf("|%d:%d|",p->info,p);
        printf("|%d|-->>",p->right);
        p=p->right;
    }
    printf("|%d|",p->left);
    printf("|%d:%d|",p->info,p);
    printf("|%d|-->>",p->right);
    }
    else
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
            printf("Enter the element : ");
            scanf("%d",&data);
            insert_beg();
            display();
            break;
        }
    case 2:
        {
            printf("Enter the element : ");
            scanf("%d",&data);
            insert_end();
            display();
            break;
        }
    case 3:
        {
            printf("Enter the element : ");
            scanf("%d",&data);
            printf("Enter the position of insertion : ");
            scanf("%d",&ps);
            insert_any();
            display();
            break;
        }
 /*   case 4:
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
        }*/
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
