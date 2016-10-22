#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}


int authenticate(int caser,char pass[])
    {
        int passer=0,count=4;
        char userpass[13];
    switch(caser)
    {
     case 1:
            printf("\n\tEnter Admin Password:");
            scanf("%s",userpass);
            passer=strcmp(pass,userpass);
            while(passer!=0&&count>=0)
            {
                system("cls");
                printf("\n\tWrong Password\n\tEnter again:");
                scanf("%s",userpass);
                passer=strcmp(pass,userpass);
                count--;
            }
            if(passer==0)
                return 1;
            else if(passer!=0||count==0)
                return 0;
            else
                return 1;
            break;
    case 2:
            printf("\n\tEnter User Password");
            scanf("%s",userpass);
            passer=strcmp(pass,userpass);
            while(passer!=0&&count>=0)
            {
                system("cls");
                printf("\n\tWrong Password\n\tEnter again:");
                scanf("%s",userpass);
                passer=strcmp(pass,userpass);
                count--;
            }
            if(passer==0)
                return 1;
            else if(passer!=0||count==0)
                return 0;
            else
                return 1;
    }
    }

void adminMenu()
    {
        int passer=0;

        passer=authenticate(1,"AdminWillPass");
            if(passer==0)
                {
                    system("cls");
                    printf("\n\tLimit Exceeded!! \n\tTry Again!!");
                    return;
                }
            else
                {

                }

    }
void mainMenu()
    {
    int choice,i=0;
    printf(("\n\n\n\tEnter which one you want to select:\n\n"));
    printf("\t1.Admin Login\n");
    printf("\t2.User Login\n");
    printf("\t3.Exit\n\tEnter:");
    scanf("%d",&choice);
    printf("\tOk! You chose choice no.:%d",choice);
    fordelay(100000000);
    system("cls");
    printf("Loading");
    for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
    system("cls");
    switch(choice)
    {
    case 1:
        adminMenu();
        break;
    case 2:
        //userMenu();
        break;
    case 3:
        printf("\n\n\tThanks for visiting! Please visit again!\n\n");
    }
    }
int main()
    {
    mainMenu();
    return 0;
    }
