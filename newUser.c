#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    newUser();
    return 0;
}
void newUser()
{
    printf("\n\t*************Enter following Details*************\n\t");
    FILE *master;
    master=fopen("MasterList.txt","a");
    printf("\n\tEnter your first name(10 letters max) : ");
    char name[21],lastname[10];
    scanf("%s",name);
    printf("\n\tEnter your last name(10 letters max) : ");
    scanf("%s",lastname);
    strcat(name," ");
    strcat(name,lastname);
    fprintf(master,"%s\n",name);
    printf("\n\tEnter your College name : ");
    char college[30];
    scanf("%s",college);
    fprintf(master,"%s\n",college);
    printf("\n\tEnter a password for your account (13 characters maximum):");
    char pass[13];
    scanf("%s",pass);
    fprintf(master,"%s\n",pass);
    srand(time(NULL));
    int x=rand();
    printf("\n\tYour ID is: %d",x);
    fprintf(master,"%d\n",x);
    fclose(master);
    system("cls");
    printf("\t********REGISTRATION SUCCESSFULL*******");
    printf("\n\tEnter which event you want to register for:\n\t");
    printf("\n\n\t*****************WARNING: ENTER THE NAME OF EVENT AS IT IS!**************************");
   // displayEvents();
    FILE *event;
    while(1)
    {
    printf("\n\tEnter name of event:");
    char eventname[20];
    scanf("%s",eventname);
    strcat(eventname,".txt");
    event=fopen(eventname,"a");
    fprintf(event,"%s\n",name);
    printf("\n\n\tDo you wish to continue?\n\t1.Yes 2.No\n\t");
    printf("Enter: ");
    int choice;
    scanf("%d",&choice);
    fclose(event);
    if(choice==2)
        break;
    }
    printf("\n\n\t*******Events successfully Registered*******");
}
