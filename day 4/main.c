#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[100];
    char s[100];
    int z=0,flag=0,k=0;
     for(int i=0;i<100;i++)
                s[i]='\0';
      for(int i=0;i<100;i++)
                str[i]='\0';
    printf("Enter a string: ");
    gets(str);
    str[strlen(str)]=' ';
    k=strlen(str);

     /*printf("Enter string to be found");
     gets(s);*/
     for(int i=0;i<k;i++)
     {



          if(str[i]=='\0'||str[i]==' ')
          {
        printf("%s",s);

          flag=revcheck(s);
           if (flag==1)
            printf("*%s*",s);

 //           for(int i=0;i<strlen(s);i++)
 //               s[i]='\0';
           z=0;
          }
          else

            {
             s[z]=str[i];
             z++;

         }
     }



    return 0;
}
int revcheck(char s2[])
{
  char s1[100];
     for(int i=0;i<100;i++)
                s1[i]='\0';
  int k=0,l=strlen(s2);
  for(int i=l-1;i>=0;i--)
  {
          s1[k]=s2[i];
          k++;
         // puts(s1);

  }
  //puts(s1);
  //puts(s2);
  printf("The original string is %s\n",s2);
  printf("The reverse string is %s\n",s1);
  if(strcasecmp(s1,s2)==0)
    return 1;
  else
    return 0;


}
