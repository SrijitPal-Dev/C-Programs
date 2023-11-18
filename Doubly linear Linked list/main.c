#include <stdio.h>
#include <stdlib.h>
struct node
{
struct node *left;
struct node *right;
int data;
}*start;
int c=0;
void insert_beg(int n)
{
struct node *newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->left=NULL;
newnode->right=NULL;
newnode->data=n;
if(start==NULL)
start=newnode;
else
{
newnode->right=start;
start=newnode;
}
c++;
}
void insert_end(int n)
{
struct node *p,*newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->left=NULL;
newnode->right=NULL;
newnode->data=n;
if(start==NULL)
start=newnode;
else
{
p=start;
while(p->right!=NULL)
p=p->right;
p->right=newnode;
newnode->left=p;
}
c++;
}
void insert_any(int n)
{
struct node *p=start,*newnode; int pos,i;
printf("Enter position of insertion : ");
scanf("%d",&pos);
if(pos<=0||pos>c+1)
printf("Invalid Position!\n");
else
{
if(pos==1)
insert_beg(n);
else if(pos==c+1)
insert_end(n);
else if(pos>1&&pos<=c)
{
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=n;
for(i=1;i<pos-1;i++)
p=p->right;
newnode->right=p->right;
newnode->left=p;
p->right=newnode;
c++;
}
}
}
void del_beg()
{
struct node *p=start,*q=start;
if(start==NULL)
printf("Nothing to Delete\n");
else
{
if(start->right==NULL)
{
free(q);
start=NULL;
}
else
{
start=p->right;
start->left=NULL;
free(p);
}
c--;
}
}
void del_end()
{
struct node *p=start,*q=start,*r=start;
if(start==NULL)
printf("Nothing to Delete\n");
else
{
if(start->right==NULL)
{
free(r);
start=NULL;
}
else
{
while(p->right!=NULL)
{
q=p;
p=p->right;
}
q->right=NULL;
free(p);
}
c--;
}
}
int del_any()
{
    struct node *p,*r;
    p=start; r=start;
    int ps,i=0;
    printf("Enter the position of deletion : ");
    scanf("%d",&ps);
    if(ps<=0||ps>c)
        printf("Invalid position\n");
    else if(ps==1)
        del_beg();
    else if(ps==c)
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
        c--;
    }
    return 0;
}
void  count()
{
printf("No. of Nodes : %d\n",c);
}
void display()
{
struct node *p=start;
if(start==NULL)
printf("Empty\n");
else
{
printf("NULL");
while(p!=NULL)
{
printf("<--%d-->",p->data);
p=p->right;
}
printf("NULL\n");
}
}
int main()
{
int ch,n;
printf("Press 1 to insert first\nPress 2 to insert last\nPress 3 to insert intermediate\nPress 4 to delete first\nPress 5 to delete last\nPress 6 to delete any position\nPress 7 to count\nPress 8 to display\nPress 9 to exit\n");
while(1)
{
printf("Enter choice : ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("Enter a value : ");
scanf("%d",&n);
insert_beg(n);
break;
case 2:
printf("Enter a value : ");
scanf("%d",&n);
insert_end(n);
break;
case 3:
printf("Enter a value : ");
scanf("%d",&n);
insert_any(n);
break;
case 4:
del_beg();
break;
case 5:
del_end();
break;
case 6:
del_any();
break;
case 7:
count();
break;
case 8:
display();
break;
case 9:
exit(0);
default:
printf("Invalid!!\n");
}
}
return 0;
}


