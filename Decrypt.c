#include<stdio.h>
#include<string.h>
void decrypt(char pass[])
{
    int i;
    for(i=0;i<strlen(pass);i++)
            pass[i]-=10;
}

int main()
{
    FILE *p;
    p=fopen("AdminPassword.txt","r");
    char pass[13];
    fscanf(p,"%s",pass);
    decrypt(pass);
    printf("%s",pass);
    fclose(p);
    return 0;
}

