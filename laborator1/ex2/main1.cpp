#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;
int convert_to_nr(char s[])
{
    int l=strlen(s);
    int nr=0;
    int p=1;
    for(int i=l-1; i>=0; i--)
    {
        int cifra=s[i]-'0';
        nr=cifra*p+nr;
        p*=10;

    }
    return nr;

}
int main()
{
  FILE *f;
  f=fopen("fisier.int", "r");
  int sum=0;
   if (f==NULL)
	{
		printf("Eroare. Nu am putut deschide fisierul\n");
	}
	else
    {printf("Am deschis fisierul cu success!\n");
		char myString[200];
        while (fgets(myString, 200, f))
		{
			myString[strlen(myString) - 1] = '\0';
			sum+=convert_to_nr(myString);
		}
		fclose(f);

	}

printf("suma numerelor este: %d\n", sum);

    return 0;
}
