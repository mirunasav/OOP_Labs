#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
struct
{
    char content[50];
    int length;
}word[50];
void ordonare (int i)
{
    for(int j=1; j<i; j++)
        for(int k=j+1; k<=i; k++)
    {
        if(word[j].length<word[k].length)
        {
            swap(word[j].length,word[k].length);
            char ch[50];
            strcpy(ch, word[j].content);
            strcpy(word[j].content, word[k].content);
            strcpy(word[k].content, ch);
        }
        else
            if (word[j].length==word[k].length)
        {
            if(strcmp(word[j].content,word[k].content)<0)
            {
            char ch[50];
            strcpy(ch, word[j].content);
            strcpy(word[j].content, word[k].content);
            strcpy(word[k].content, ch);
            }
        }
    }


}

int main()
{
  char *p;
  char mystring[200];
  int i=0;
  printf ("Scrieti un enunt: ");
  scanf("%[^\n]",mystring);

  p=strtok(mystring," ");
  while (p!=NULL)
  { i++;
      strcpy(word[i].content, p);
      word[i].length=strlen(word[i].content);

      p=strtok(NULL, " ");
  }

ordonare(i);
  for (int j=1; j<=i; j++) printf("%s\n", word[j].content);
  return 0;
}
