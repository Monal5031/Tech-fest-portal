#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int eventCount(int change)
{
    FILE *count;
    int counter;
    if(change==1)
        {

            count=fopen("EventCount.txt","r");
            fscanf(count,"%d",&counter);
            counter++;
            fclose(count);
            count=fopen("EventCount.txt","w");
            fprintf(count,"%d",counter);
            fclose(count);
            return counter;
        }
    else
        {
            count=fopen("EventCount.txt","r");
            fscanf(count,"%d",&counter);
            fclose(count);
            return counter;
        }


}


void modifyInfo(char event[])
{
    FILE *change;
    change=fopen("EventInfo.txt","r+");
    printf("Enter the New Information of the event: ");
    char newinfo[100],newinfo1[100];
    char ch1; int i=0;
    while(1)
    {
        scanf("%c",&ch1);
        if(ch1=='\n')
            break;
        newinfo[i]=ch1;
        i++;
    }
    strcpy(newinfo1,newinfo);
    strcat(newinfo,"                   ");
    char eventname[50]="Name:";
    strcat(eventname,event);
    char check[30];
    while(!feof(change))
    {
        fscanf(change,"%s",check);
        if(strcmp(eventname,check)==0)
        {
            char ch;
            fscanf(change,"%c",&ch);
            fscanf(change,"%s",check);
            fscanf(change,"%c",&ch);
            fprintf(change,"\n%s",newinfo);
            break;
        }
    }
    system("cls");
    printf("\t\t*******EVENT INFORMATION SUCCESSFULLY CHANGED*******\n");
    printf("\tNew Information:%s",newinfo);
    fordelay(1000000);
    fordelay(1000000);
    fordelay(1000000);
    fordelay(1000000);
}



void modifyTime(char event[])
{
    FILE *change;
    change=fopen("EventInfo.txt","r+");
    printf("Enter the New time of the event(e.g.08:00am): ");
    char newtime[50],newtime1[50];
    scanf("%s",newtime);
    strcpy(newtime1,newtime);
    strcat(newtime,"                   ");
    char eventname[50]="Name:";
    strcat(eventname,event);
    char check[30];
    while(!feof(change))
    {
        fscanf(change,"%s",check);
        if(strcmp(eventname,check)==0)
        {
            char ch;
            fscanf(change,"%c",&ch);
            fscanf(change,"%s",check);
            fseek(change,-strlen(check), SEEK_CUR);
            fprintf(change,"Time:%s",newtime);
            break;
        }
    }
    system("cls");
    printf("\t\t*******EVENT TIME SUCCESSFULLY CHANGED*******");
    printf("\n\tOld time:%s\n",check);
    printf("\tNew Time:%s",newtime1);
    fordelay(1000000);
    fordelay(1000000);
    fordelay(1000000);
    fordelay(1000000);

}



void modifyName(char event[])
{
    FILE *change;
    change=fopen("EventInfo.txt","r+");
    printf("Enter the New Name of the event: ");
    char newname[50],newname1[50];
    scanf("%s",newname);
    strcpy(newname1,newname);
    strcat(newname,"                   ");
    while(!feof(change))
    {
        char check[30];
        fscanf(change,"%s",check);
        if(strcmp(newname,check)==0)
        {
            fseek(change, -strlen(check), SEEK_CUR);
            fprintf(change,"%s",newname);
            break;
        }
    }
    system("cls");
    printf("\t\t*******EVENT NAME SUCCESSFULLY CHANGED*******");
    printf("\n\tOld Name:%s\n",event);
    printf("\tNew Name:%s",newname1);
    fordelay(1000000);
    fordelay(1000000);
    fordelay(1000000);
    fordelay(1000000);
}



void modifyEventInfo()
{
    loop:
    system("cls");
    viewList();
    printf("\t\t****Enter which event you want to modify*******\n");
    char event[30];
    printf("\nEnter Which do you want to modify:");
    scanf("%s",&event);
    printf("\tEnter what do you want to modify:\n\t");
    printf("1.Name\n\t2.Time\n\t3.Information\n\tEnter:");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        modifyName(event);
        break;
    case 2:
        modifyTime(event);
        break;
    case 3:
        modifyInfo(event);
    }
    printf("\n\n\n\tDo you wish to modify any more events?\n\t1.Yes\n\t2.No");
    int looper;
    scanf("%d",&looper);
    if(looper==1)
        goto loop;
    adminMenu(1);
    return;
}


void accessEventWiseList()
{
    system("cls");
    viewList();
    while(1)
    {
        FILE *access;
        printf("\n\tEnter which Event's List you want (exactly same)\n");
        char event[20];
        scanf("%s",event);
        strcat(event,".txt");
        access=fopen(event,"r");
        char ch;
        printf("\n\t\t*********List of Registered Users*********\n");
        while(!feof(access))
            {
            fscanf(access,"%c",&ch);
            printf("%c",ch);
            }
        printf("\n\tDo you wish to view another event's list?\n");
        printf("\t1.Yes\n\t2.No");
        int choice;
        scanf("%d",&choice);
        if(choice==2)
            break;
    }
    system("cls");
    adminMenu(1);
}


int checkPassword(char pass[])
{
    int special=0,up=0,low=0,no=0;
    int i;
    for(i=0;i<strlen(pass);i++)
    {
        if(pass[i]=='@'||pass[i]=='_'||pass[i]=='#'||pass[i]=='$'||pass[i]=='%'||pass[i]=='^'||pass[i]=='&'||pass[i]=='*')
            special++;

        else if(pass[i]>=65&&pass[i]<=90)
            up++;
        else if(pass[i]>=97&&pass[i]<=122)
            low++;
        else if(pass[i]>=48&&pass[i]<=57)
            no++;
    }
    if(special>0&&up>0&&low>0&&no>0&&strlen(pass)>=8)
        return 1;
    else
        return 0;
}


void accessUserList()
{
    FILE *access;
    char ch;
    printf("\n\t********LIST OF ALL THE PARTICIPANTS IN THE TECHFEST*******\n");
    access=fopen("UserList.txt","r");
    while(!feof(access))
    {
        fscanf(access,"%c",&ch);
        printf("%c",ch);
    }
    fclose(access);
    printf("\n\tAre you ready to continue?\n\tEnter 1 when you are!");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
        adminMenu(1);
}



void viewEventInfo()
{
    FILE *info;
    info=fopen("EventInfo.txt","r");
    char ch;
    while(!feof(info))
    {
        fscanf(info,"%c",&ch);
        printf("%c",ch);
    }
    printf("\b ");
    fclose(info);
    printf("\n\tWhere do you want to go:\n\t1.Main Menu\n\t2.User Menu\n\t3.Exit");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        system("cls");
        mainMenu();
        break;
    case 2:
        system("cls");
        userMenu();
        break;
    case 3:
        system("cls");
    }
}

void fillEventInfo(char name[],char time[],char infor[])
{
    FILE *info;
    info=fopen("EventInfo.txt","a");
    fprintf(info,"\n");
    fprintf(info,"Name:%s\n",name);
    fprintf(info,"Time:%s\n",time);
    fprintf(info,"Information:%s\n",infor);
    fclose(info);
}



void credits()
{
    FILE *credit;
    credit=fopen("Credits.txt","r");
    while(!feof(credit))
    {
        char ch;
        fscanf(credit,"%c",&ch);
        fordelay(10000001);
        printf("%c",ch);
    }
    printf("\b ");
    fclose(credit);
}


void viewList()
{
    FILE *view;
    view=fopen("EventList.txt","r");
    while(!feof(view))
    {
        char event[20];
        fscanf(view,"%s",event);
        printf("%s\n",event);

    }
}


void newUser()
{
    printf("\n\t*************Enter following Details*************\n\t");
    FILE *master;
    FILE *user;
    user=fopen("UserList.txt","a");
    master=fopen("MasterList.txt","a");
    printf("\n\tEnter your first name(15 letters max) : ");
    char name[21],lastname[10];
    scanf("%s",name);
    printf("\n\tEnter your last name(10 letters max) : ");
    scanf("%s",lastname);
    strcat(name," ");
    strcat(name,lastname);
    fprintf(master,"\n%s\n",name);
    fprintf(user,"%s\n",name);
    fclose(user);
    fflush(stdin);
    printf("\n\tEnter your College name : ");
    char college[100];
    gets(college);
    fprintf(master,"%s\n",college);
    printf("\n\tEnter a password for your account \n\t(Min.8 Max. 13 characters..Must contain: a special character [@,_,#,$,%,^,&,*] ,a uppercase letter,a lower case letter and a number)\n\tEnter::");
    int checker=0;
    char pass[13];
    while(checker!=1)
    {
    scanf("%s",pass);
    checker=checkPassword(pass);
    if(checker==1)
        printf("\n\tPassword Acceptable!");
    else
        printf("\n\tINVALID PASSWORD!!!\n\tEnter different password:");
    }
    srand(time(NULL));
    int x=rand();
    printf("\n\tYour ID is: %d",x);
    fprintf(master,"%d\n",x);

    fprintf(master,"%s\n",pass);

    printf("\n\tPlease NOTE this ID down for future use\n\tEnter 1 when Ready to Continue");
    int go;
    scanf("%d",&go);
    system("cls");
    printf("\t********REGISTRATION SUCCESSFULL*******");
    printf("\n\tEnter which event you want to register for one by one:\n\t");
    printf("\n\n\t*****************WARNING: ENTER THE NAME OF EVENT AS IT IS!**************************\n");
    viewList();
    int eventid[20]={0};
    while(1)
    {
        FILE *event;
    printf("\n\tEnter event number and the name of event:");
    char eventname[20];
    int i;
    scanf("%d",&i);
    eventid[i]=1;
    scanf("%s",eventname);
    strcat(eventname,".txt");
    event=fopen(eventname,"a");
    fprintf(event,"%s\n",name);
    printf("\n\n\tDo you wish to register for more events?\n\t1.Yes 2.No\n\t");
    printf("Enter: ");
    int choice;
    scanf("%d",&choice);
    fclose(event);
    if(choice==2)
        break;
    }
    int i;
    for( i=0;i<sizeof(eventid)/sizeof(eventid[0]);i++)
            fprintf(master,"%d",eventid[i]);
    fclose(master);
    printf("\n\n\t*******Events successfully Registered*******");
    printf("\n\tDo you wish to continue?\n\t1.Yes\n\t2.No");
    int next;
    scanf("%d",&next);
    if(next==1)
        userMenu();
    return;
}



void userMenu()
{
    system("cls");
    printf("\n\t1.New user\n\t2.Old User\n\t3.Event Information\n\t4.Main Menu");
    int choice;
    printf("\n\tEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        system("cls");
        newUser();
        break;
    case 2:
        system("cls");
        //oldUser();
        break;
    case 3:
        system("cls");
        viewEventInfo();
        break;
    case 4:
        system("cls");
        mainMenu();
    }
return;
}

void createEvent()
{
    char name[30];
    system("cls");
    printf("\n\tPlease Enter the name of event you want to create (Max Size 30): ");
    fflush(stdin);
    gets(name);
    fflush(stdin);
    FILE *create;
    FILE *registerevent;
    registerevent=fopen("EventList.txt","a");
    int number=eventCount(1);
    fprintf(registerevent,"\n\t%d. %s",number,name);
    printf("\n\tCongratulations! Event Created \n\tPlease Enter Following Information about the event\n\t");
    char time[10];
    printf("Enter Time(with am or pm without spacing) **(8 size max)**: ");
    scanf("%s",time);
    char info[1000];
    printf("\n\tEnter some Info about the event:");
    fflush(stdin);
    gets(info);
    fillEventInfo(name,time,info);
    printf("\n\tCongratulations! Event Successfully Registered");
    fclose(registerevent);
    strcat(name,".txt");
    create=fopen(name,"w");
    fclose(create);
    fordelay(1000000);
    fordelay(1000000);
    fordelay(1000000);
    fordelay(1000000);
    fordelay(1000000);
    fordelay(1000000);
    fordelay(1000000);
    adminMenu(1);
    }


void changePassword(char pass[])
{
    system("cls");
    up:
    printf("");
    char checkpass[13];
    printf("\tEnter Your Old Password:");
    scanf("%s",checkpass);
    if(strcmp(checkpass,pass)!=0)
    {
        printf("WRONG PASSWORD!! ENTER AGAIN:\n\t");
        goto up;
    }
    FILE *password;
    password=fopen("AdminPassword.txt","w");
    system("cls");
    upper:
    printf("\n\t*************Enter New Password**********\nPassword must contain: an uppercase letter, a lowercase letter a number and \na special character[@,#,$,^,%,&,*,]\nEnter:");
    re:
    scanf("%s",pass);
    int check=checkPassword(pass);
    if(check!=1)
    {
        printf("\tINVALID PASSWORD\n\tPLEASE ENTER A VALID PASSWORD\n");
        printf("ENTER:");
        goto re;
    }
    printf("\n**VALID PASSWORD**\n");
    printf("\nEnter Password Again:");
    scanf("%s",checkpass);
    if(strcmp(checkpass,pass)!=0)
    {
        printf("PASSWORDS DO NOT MATCH ENTER NEW AGAIN");
        goto upper;
    }
    encrypt(pass);
    fprintf(password,"%s",pass);
    fclose(password);
    system("cls");
    printf("\t\t**********PASSWORD CHANGE SUCCESSFULL**********");
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    adminMenu(1);
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

void adminMenu(int skipper)
    {
        if(skipper==1)
            goto skip;
        int j;
        FILE *adminpass;
        adminpass=fopen("AdminPassword.txt","r");
        int passer=0;
        char pass[13];
        fscanf(adminpass,"%s",pass);
        decrypt(pass);
        fclose(adminpass);
        passer=authenticate(1,pass);
            if(passer==0)
                {
                  system("cls");
                    printf("\n\tLimit Exceeded!! \n\tTry Again!!");
                    return;
                }
            else
                {
                    skip:
                    system("cls");
                    int choice;
                    printf("\n\n\t1.Create Event\n\t2.Modify Event Information\n\t3.Change Password\n\t4.Access User List(All Events)\n\t5.Access Event Wise List\n\t6.Log Out");
                    printf("\n\tEnter your Choice:");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                    case 1:
                        createEvent();
                        break;
                    case 2:
                        modifyEventInfo();
                        break;
                    case 3:
                        changePassword(pass);
                        break;
                    case 4:
                        accessUserList();
                    break;
                    case 5:
                        accessEventWiseList();
                        break;
                    case 6:
                        system("cls");
                        printf("Loading");
                        for(j=0;j<=6;j++)
                            {
                            fordelay(100000000);
                            printf(".");
                            }
                            mainMenu();
                            break;
                    }
                }


             return;
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
            fordelay(11111111);
            printf(".");
        }
    system("cls");
    switch(choice)
    {
    case 1:
        adminMenu(0);
        break;
    case 2:
        userMenu();
        break;
    case 3:
        break;
    default:
        printf("\n\tInvalid Option!!!!! \n\t Give Valid Input");
        fordelay(100000000);
        mainMenu();
    }
    }
int main()
    {
    mainMenu();
    system("cls");
    printf("\n\n\tThanks for visiting! Please visit again!\n\n");
    printf("\n\t*****PROJECT BY:******\n");
    credits();
    return 0;
    }
