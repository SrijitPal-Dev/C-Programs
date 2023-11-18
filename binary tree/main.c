#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    int b_f;
    struct node* left;
    struct node* right;
}*root;
int l=0;
int insertion()
{
    int data; struct node *p=root,*q;
    printf("Enter the element : ");
    scanf("%d",&data);
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->info=data;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL)
        root=newnode;
    else
    {
        while(p!=NULL)
        {
            q=p;
            if(data>p->info)
                p=p->right;
            else if(data<p->info)
                p=p->left;
        }
        if(data>q->info)
            q->right=newnode;
        else if(data<q->info)
            q->left=newnode;
    }
    return 0;
}
void inorder(struct node *new)
{
    if(new==NULL)
        return;
    inorder(new->left);
    printf("%d -> ",new->info);
    inorder(new->right);
}
void preorder(struct node *new)
{
    if(new==NULL)
        return;
    printf("%d -> ",new->info);
    preorder(new->left);
    preorder(new->right);
}
void postorder(struct node *new)
{
    if(new==NULL)
        return;
    postorder(new->left);
    postorder(new->right);
    printf("%d -> ",new->info);
}
int search(int info)
{
    struct node *p=root; int f=0;
    if(p==NULL)
        return -1;
    else
    {
        while(p!=NULL)
        {
            if(info>p->info)
                p=p->right;
            else if(info<p->info)
                p=p->left;
            if(p->info==info)
            {
                f=1;
                break;
            }
        }
        if(f==0)
            return -1;
        else
        {
            if(p->right!=NULL)
                l++;
            if(p->left!=NULL)
                l++;
            return l;
        }
    }
}
void del()
{
int x;
printf("Enter element to be deleted\n");
scanf("%d",&x);
struct node *p=root;
struct node *b;
struct node *q;
int k=search(x);
if(k==-1){
printf("Element not found");
return;
}
while(p->info!=x)
{
	q=p;
	if(x>p->info)
	p=p->right;
	else
	p=p->left;
}
if(k==0)
{

	if(p==root)
	root=NULL;
	else
	{
	free(p);
	if(x>q->info)
	q->right=NULL;
	else
	q->left=NULL;
}

}
else if(k==1)
{
	if(p==root)
	{
		if(p->left!=NULL)
		     root=p->left;
        else
            root=p->right;

	}
if(p->right==NULL)
b=p->left;
else
b=p->right;
if(x>q->info)
	q->right=b;
else
    q->left=b;
    free(p);
}
else
{
		struct node* n = p;
        struct node* s = p->right;
        struct node* r = p->right;
        struct node* l=p->left;
        struct node* a;
        while (s->left != NULL) {
            n = s;
            s = s->left;
		}
		free(p);
		if(n!=p)
		{
		a=s->right;

		if(x<q->info)
		q->left=s;
		else
		q->right=s;
		s->left=l;
		s->right=r;
		n->left=a;
		}
		else
		{
		if(x<q->info)
		q->left=s;
		else
		q->right=s;
		s->left=l;
		if(x==root->info)
            root=s;
	}
}
}
int main()
{
    int ch;
    printf("1.To Insert\n2.To display Inorder Traversal\n3.To display Preorder Traversal\n4.To display Postorder Traversal\n5.To delete an element\n6.To exit\n");
    do
    {
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insertion();
                break;
            case 2:
                inorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                postorder(root);
                break;
            case 5:
                del();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Wrong Choice!\n");
        }
    }while(1);
    return 0;
}

