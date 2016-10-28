#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void createEvent()
{
    char name[30];
    system("cls");
    printf("\n\tPlease Enter the name of event you want to create (Max Size 30): ");
    inputInfo(name);
    FILE *create;
    FILE *registerevent;
    registerevent=fopen("EventListInfo.txt","a");
    fprintf(registerevent,"Name:%s\n",name);
    printf("\n\tCongratulations! Event Created \n\tPlease Enter Following Information about the event\n\t");
    char time[10];
    printf("Enter Time(with am or pm) **(8 size max)**: ");
    inputInfo(time);
    fprintf(registerevent,"%s\n",time);
    char info[1000];
    printf("\n\tEnter some Info about the event:");
    inputInfo(info);
    fprintf(registerevent,"%s\n",info);
    printf("\n\tCongratulations! Event Successfully Registered");
    fclose(registerevent);
    strcat(name,".txt");
    create=fopen(name,"w");
    fclose(create);
}


void inputInfo(char name[])
{

int i=0;
    char ch;
    do{
        scanf("%c",&ch);
        if(ch=='\n')
            break;
        name[i]=ch;
        i++;
    }
    while(1);
    name[i]='\0';
return;
}


void changePassword(char pass[])
{
    FILE *password;
    password=fopen("AdminPassword.txt","w");

    system("cls");
    printf("\n\tEnter New Password of only 13 letters:");
    scanf("%s",pass);
    encrypt(pass);
    fprintf(password,"%s",pass);
    fclose(password);
}


void encrypt(char pass[])
{
    int i;
    for(i=0;i<strlen(pass);i++)
            pass[i]=pass[i]+10;
}
void decrypt(char pass[])
{
    int i;
    for(i=0;i<strlen(pass);i++)
            pass[i]-=10;
}
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
        int j;
        FILE *adminpass;
        adminpass=fopen("AdminPassword.txt","r");
        int passer=0;
        char pass[13];
        fscanf(adminpass,"%s",pass);
        decrypt(pass);
        passer=authenticate(1,pass);
            if(passer==0)
                {
                  system("cls");
                    printf("\n\tLimit Exceeded!! \n\tTry Again!!");
                    return;
                }
            else
                {
                    system("cls");
                    int choice;
                    printf("\n\n\t1.Create Event\n\t2.Modify Event Information\n\t3.Change Password\n\t4.Main Menu");
                    printf("\n\tEnter your Choice:");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                    case 1:
                       // createEvent();
                        break;
                    case 2:
                       // modifyEvent();
                        break;
                    case 3:
                        changePassword(pass);
                        break;
                    case 4:
                        system("cls");
                        printf("Loading");
                        for(j=0;j<=6;j++)
                            {
                            fordelay(100000000);
                            printf(".");
                            }
                            mainMenu();
                    }
                }
            fclose(adminpass);
            printf("\n\tDO you want to continue?\n\t1.Yes\n\t2.No\n\t");
            scanf("%d",&j);
            if(j==1)
                mainMenu();
            else
            {
                printf("\n\n\tThanks for visiting! Please visit again!\n\n");
             return;
            }
    }
void mainMenu()
    {
    system("cls");
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
        break;
    default:
        printf("\n\tInvalid Option!!!!! \n\t Give Valid Input");
        fordelay(100000000000);
        mainMenu();
    }
    }
int main()
    {
    mainMenu();
    return 0;
    }
