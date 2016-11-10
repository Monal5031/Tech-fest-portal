#include<stdio.h>
int main()
{
    passwordMasking1();
    return 0;
}

void passwordMasking1()
{
    char pass[30];
    int passlen=0;
    char newpass[13];
    printf("enter password:");
    int i=0,j; char ch,star='*';
    while(1)
    {
        //system("cls");
        ch=getc(stdin);
        fflush(stdin);
        printf("\b%c",star);
        if(ch=='\b')
        passlen++;

            passlen--;
        if(ch=='\n')
            break;
        pass[i]=ch;
        i++;

    }
    for(i=0;i<passlen-1;i++)
    printf("%c",pass[i]);
}
