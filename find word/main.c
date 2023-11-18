#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[100];
    char f[50];
    char p[62];
    int k,l,i,flag=0;
    printf("Enter the string");
    gets(s);
    printf("Enter the word to find");
    gets(f);

    k=strlen(s);
    printf("%s",s);
    /*for(int i=0;i<k;i++)
        printf("%c")*/
    l=strlen(f);
    for(int i=0;i<k;i++)
    {
       if(s[i]=='/0')

        for(int j=0;j<l;j++)
        {
            if(s[i]==f[j])
                flag=1;
            else
                flag=0;
            if(flag==0)
                break;
                i++;
        }
        if(flag==1)
        {
         printf("\nThe  string is found");
         break;

        }

    }








    return 0;
}
