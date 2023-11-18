#include <stdio.h>
int StrLen(char []);
void Concat(char [],char []);
int StrCmp(char [],char []);
int main()
{
    int ch;
    printf("Enter 1 for String Length\nEnter 2 for concatenation\nEnter 3 for String Compare\n");
    printf("Enter Choice : ");
    scanf("%d",&ch);
    fflush(stdin);
    switch(ch)
    {
        case 1:
        {
            char st[999999];
            printf("Enter a String : ");
            gets(st);
            printf("%d",StrLen(st));
            break;
        }
        case 2:
        {
            char st[999999]; char ss[999999];
            printf("Enter 1st String : ");
            gets(st);
            printf("Enter 2nd String : ");
            gets(ss);
            Concat(st,ss);
            puts(st);
            break;
        }
        case 3:
        {
            char st[999999]; char ss[999999];
            printf("Enter 1st String : ");
            gets(st);
            printf("Enter 2nd String : ");
            gets(ss);
            printf("%d",StrCmp(st,ss));
            break;
        }
        default:
            printf("Wrong Choice !!");
    }
    return 0;
}

int StrLen(char s[])
{
    int i;
    for(i=0;s[i]!='\0';i++);
    return i;
}
void Concat(char s[],char s1[])
{
    int i,j,k=0;
    for(i=0;s[i]!='\0';i++);
    k=i;
    for(j=0;s1[j]!='\0';j++)
    {
        s[k]=s1[j];
        k++;
    }
}
int StrCmp(char s[],char s1[])
{
    int i,c=0,p=0;
    if(StrLen(s)>StrLen(s1))
        p=StrLen(s);
    else
        p=StrLen(s1);
    for(i=0;i<p;i++)
    {
        if(s[i]==s1[i])
            continue;
        else
        {
            if(((int)(s[i])-(int)(s1[i]))>0)
                c=1;
            else
                c=-1;
            break;
        }
    }
    return c;
}
