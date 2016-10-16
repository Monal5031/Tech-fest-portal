#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
int main()
    {
    int choice,i=0;
    printf(("\n\n\n\tEnter which one you want to select:\n\n"));
    printf("\t1.Admin Login\n");
    printf("\t2.User Login\n");
    printf("\t3.Exit\n");
    scanf("%d",&choice);
    printf("\tOk! You chose choice no.:%d\n\tLoading",choice);
    for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }

    switch(choice)
    {
    case 1:
        //adminMenu();
        break;
    case 2:
        //userMenu();
        break;
    case 3:
        printf("\n\n\tThanks for visiting! Please visit again!");
    }
    return 0;
    }
