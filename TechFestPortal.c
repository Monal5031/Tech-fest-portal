#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void changeUserPass(char user[],char pass[])
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
    password=fopen("CurrentPassword.txt","w");
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
    //encrypt(pass);
    fprintf(password,"%s",pass);
    fclose(password);
    system("cls");
    printf("\t\t**********PASSWORD CHANGE SUCCESSFULL**********");
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    FILE *master,*copy;
    master=fopen("MasterList.txt","r");
    copy=fopen("COPY1.txt","w");
    char checkid[100];
    while(!feof(master))
    {
        fgets(checkid,100,master);
        //fscanf(master,"%s",checkid);
        if(strncmp(checkid,user,strlen(user))==0)
        {
            fprintf(copy,"%s",checkid);
            fprintf(copy,"%s\n",pass);
            fgets(checkid,100,master);
        }
        else
        fprintf(copy,"%s",checkid);
    }
    fclose(password);
    fclose(master);
    fclose(copy);
    fordelay(10000000000000);
    int rem=remove("MasterList.txt");
    printf("\n\n\t\t%d",rem);
    rename("COPY1.txt","MasterList.txt");
    OldUserMenu(user);
}


 long int assignEventID()
 {

 long int count;
  FILE *fp;
         fp=fopen("eventid.txt","r");
         fscanf(fp,"%ld",&count);
        fclose(fp);
        count++;
         fp=fopen("eventid.txt","w");
         fprintf(fp,"%ld\n",count);
         fclose(fp);
 return count;
 }


int checkEventName(char event[])
{
    FILE *ev;
    ev=fopen("TEMPE.txt","r");
    char check[30];
    while(!feof(ev))
    {
        fscanf(ev,"%s",check);
        if(strcmp(check,event)==0)
            return 0;
    }
    return 1;
}


int checkEventNumber(int i)
{
    FILE *check;
    int checkn;
    check=fopen("TEMPN.txt","r");
    while(!feof(check))
    {
        fscanf(check,"%d",&checkn);
        if(checkn==i)
            return 0;

    }
    return 1;
}


void schedule(char id[],int skip)
{
    system("cls");
    FILE *fp;
    fp=fopen("schedule.txt","r");
    char ch;
    printf("\t\t\t\t*****Schedule*****\n\n");
    while(!feof(fp))
    {
       fscanf(fp,"%c",&ch);
        printf("%c",ch);
    }
    printf("\b ");
fclose(fp);
fordelay(100000000);
fordelay(100000000);
fordelay(100000000);
fordelay(100000000);
fordelay(100000000);
fordelay(100000000);
fordelay(100000000);
fordelay(100000000);
fordelay(100000000);
fordelay(100000000);
if(skip==1)
    OldUserMenu(id);
if(skip==0)
    userMenu();
}



void viewRegisteredList(char id[])
{
    system("cls");
    FILE *master;
    master=fopen("MasterList.txt","r");
    char eventid[20];
    char faltu[20];
    char ch;
    char checkid[1000000];
    int skipper=0;
    while(!feof(master))
    {
        fscanf(master,"%s",checkid);
        if(strcmp(checkid,id)==0)
        {
            fscanf(master,"%c",&ch);
            fscanf(master,"%s",faltu);
            fscanf(master,"%c",&ch);
            fscanf(master,"%s",eventid);
            skipper=1;
            break;
        }
    }
    if(skipper==0)
    {
        printf("Wrong ID! Enter Valid one!");
        return;
    }
    fclose(master);
    FILE *eventfile;
    int i;
    int n=eventCount(0);
    eventfile=fopen("EventList.txt","r");
    printf("\t\t*******REGISTERED EVENTS********\n");
    for( i=1;i<n+1;i++)
    {
        if(eventid[i]=='1')
        {
            char event[20];
            char ev[2];
            ev[0]=i+48;
            ev[1]='.';
            while(!feof(eventfile))
            {
                char check[20];
                fscanf(eventfile,"%s",check);
                if(check[0]==ev[0]&&check[1]==ev[1])
                    {
                    fscanf(eventfile,"%s",event);
                    strcat(check,event);
                    printf("%s\n",check);
                    break;
                    }
            }
        }
        rewind(eventfile);
    }
    fclose(eventfile);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    OldUserMenu(id);
}


void registerUserEvent(char id[])
{
    printf("\n\t***********EVENT REGISTRATION*************\n");
    char name[50],lastname[20];
    printf("Enter Your First Name and Last Name separated by a space as registered: ");
    scanf("%s%s",name,lastname);
    strcat(name,lastname);
    FILE *master;
    master=fopen("MasterList.txt","r");
    char eventid[20];
    char faltu[20];
    char ch;
    char checkid[1000000];
    int skipper=0;
    while(!feof(master))
    {
        fscanf(master,"%s",checkid);
        if(strcmp(checkid,id)==0)
        {
            fscanf(master,"%c",&ch);
            fscanf(master,"%s",faltu);
            fscanf(master,"%c",&ch);
            fscanf(master,"%s",eventid);
            skipper=1;
            break;
        }
    }
    if(skipper==0)
    {
        printf("Wrong ID! Enter Valid one!");
        return;
    }
    fclose(master);
    FILE *eventfile;
    int i;
    int n=eventCount(0);
    //printf("%d",n);
    eventfile=fopen("EventList.txt","r");
    FILE *eventcheck;
    eventcheck=fopen("TEMPE.txt","w");
    for( i=1;i<n+1;i++)
    {
        if(eventid[i]=='0')
        {
            char event[20];
            char ev[2];
            ev[0]=i+48;
            ev[1]='.';
            while(!feof(eventfile))
            {
                char check[20];
                fscanf(eventfile,"%s",check);
                if(check[0]==ev[0]&&check[1]==ev[1])
                    {
                    fscanf(eventfile,"%s",event);
                    strcat(check,event);
                    printf("%s\n",check);
                    fprintf(eventcheck,"%s\n",event);
                    break;
                    }
            }
        }
        rewind(eventfile);
    }
    fclose(eventfile);
    fclose(eventcheck);
    FILE *numcheck;
    numcheck=fopen("TEMPN.txt","w");
    int j;
    for(j=0;j<=n;j++)
    {
        if(eventid[j]=='0')
        {
            fprintf(numcheck,"%d\n",j);
        }
    }
    fclose(numcheck);
    eventfile=fopen("EventList.txt","r");
    eventcheck=fopen("TEMPE.txt","r");
    printf("\n\tEnter which event you want to register for one by one:\n\t");
    printf("\n\n\t*****************WARNING: ENTER THE NAME OF EVENT AS IT IS!**************************\n");
    while(1)
    {
        rewind(eventcheck);
        rewind(numcheck);
        rewind(eventfile);
        FILE *eventfile1;
        fflush(stdin);
    printf("\n\tEnter event number and the name of event (separated by space):");
    char eventname[30];
    int i;
    scanf("%d",&i);
    scanf("%s",eventname);
    if(checkEventNumber(i))
    {
        printf("\n\tEvent Number Not Valid!!\n\tPlease Enter a Valid EVENT number");
        continue;
    }
    if(checkEventName(eventname))
    {
        printf("\n\tEvent Name Not Valid!!\n\tPlease Enter a Valid EVENT name");
        continue;
    }
    eventid[i]='1';
    strcat(eventname,".txt");
    eventfile1=fopen(eventname,"a");
    fprintf(eventfile1,"%s\n",name);
    printf("\n\n\tDo you wish to register for more events?\n\t1.Yes 2.No\n\t");
    printf("Enter: ");
    int choice;
    scanf("%d",&choice);
    fclose(eventfile1);
    if(choice==2)
        break;
    }
    //printf("%s",eventid);
    master=fopen("MasterList.txt","r");
    FILE *copy;
    copy=fopen("COPY.txt","w");

    while(!feof(master))
    {
        fgets(checkid,100,master);
        //fscanf(master,"%s",checkid);
        if(strncmp(checkid,id,strlen(id))==0)
        {
            fprintf(copy,"%s",checkid);
            fgets(checkid,100,master);
            fprintf(copy,"%s",checkid);
            printf("%s",eventid);
            fprintf(copy,"%s\n",eventid);
            fgets(checkid,100,master);

        }
        else
        fprintf(copy,"%s",checkid);
    }
    fclose(master);
    fclose(copy);
    fclose(numcheck);
    fclose(eventcheck);
    remove("MasterList.txt");
    remove("TEMPE.txt");
    remove("TEMPN.txt");
    rename("COPY.txt","MasterList.txt");
    printf("\t\t******EVENTS SUCCESSFULLY REGISTERED********");
    OldUserMenu(id);
}



int OldUserMenu(char id[])
{
    char pass[13];
    FILE *passf;
    passf=fopen("CurrentPassword.txt","r");
    fscanf(passf,"%s",pass);
    system("cls");
    printf("\t***********LOGGED IN*******");
    printf("\n\n\t1.Register for new Events\n\t2.List of Events Registered\n\t3.Display Event Information\n\t");
    printf("4.View Event List\n\t5.Event Schedule\n\t6.Change password\n\t7.LogOut\n\tEnter:");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        registerUserEvent(id);
        system("cls");
        break;
    case 2:
        viewRegisteredList(id);
        system("cls");
        break;
    case 3:
        viewEventInfo(1,id);
        system("cls");
        break;
    case 4:
        viewList(1,id);
        system("cls");
        break;
    case 5:
        schedule(id,1);
        system("cls");
        break;
    case 6:
        changeUserPass(id,pass);
        break;
    case 7:
        system("cls");
        int i;
        printf("Loading");
        for(i=0;i<=6;i++)
        {
            printf(".");
            fordelay(1000000);
            fordelay(1000000);
            fordelay(1000000);
        }
        mainMenu();
        break;
    }
    return 0;
}



void oldUser()
{
    system("cls");
    printf("\n\n\n\t\tEnter User Id:");
    char user[10];
    loop:
    scanf("%s",user);
    FILE *search;
    int finder=0;
    search=fopen("MasterList.txt","r");
    char pass[15];
    while(!feof(search))
    {
        char id[10];
        fscanf(search,"%s",id);
        if(strcmp(id,user)==0)
        {
            char ch;
            fscanf(search,"%c",&ch);
            fscanf(search,"%s",pass);
            finder=1;
            break;
        }
    }
    if(finder==0)
    {
        printf("\n\tWrong ID! Please Enter a correct ID");
        goto loop;
    }
    loop1:
    system("cls");
    char userpass[13];
    enterPass(userpass);
    printf("Verifying");
    int i;
    for(i=0;i<6;i++)
    {
        printf(".");
        fordelay(100000);
    }
    if(strcmp(userpass,pass)!=0)
    {
        printf("\n\tWrong Password! Enter Correct Password\n\tEnter:");
        goto loop1;
    }
   FILE *passf;
    passf=fopen("CurrentPassword.txt","w");
    fprintf(passf,"%s",pass);
    fclose(passf);
    OldUserMenu(user);
}


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



int viewEventInfo(int skipper,char id[])
{
    FILE *info;
    info=fopen("EventInfo.txt","r");
    char ch;
    system("cls");
    printf("\t\t************EVENT INFORMATION***********\n");
    while(!feof(info))
    {
        fscanf(info,"%c",&ch);
        printf("%c",ch);
    }
    printf("\b ");
    fclose(info);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    if(skipper==1)
        OldUserMenu(id);
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
    return 0;
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


int viewList(int skipper,char id[])
{

    if(skipper==1)
        system("cls");
    printf("\t\t***********LIST OF ALL EVENTS***********\n");
    FILE *view;
    view=fopen("EventList.txt","r");
    while(!feof(view))
    {
        char event[20];
        fscanf(view,"%s",event);
        printf("%s\n",event);

    }
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    if(skipper==1)
        OldUserMenu(id);
return 0;
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
    int x=assignEventID();
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
    viewList(0,"");
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



int userMenu()
{
    system("cls");
    printf("\n\t1.New user\n\t2.Old User\n\t3.Event Information\n\t4.Event Schedule\n\t5.Main Menu");
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
        oldUser();
        break;
    case 3:
        system("cls");
        viewEventInfo(0,"");
        break;
    case 4:
        schedule("",0);
        break;
    case 5:
        system("cls");
        mainMenu();
    }
return 0;
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
    int length;
    int flag=0;
    printf("\n%s\n",pass);
    length=strlen(checkpass);
    int i;
    for(i=0;i<length;i++)
      {
           if(checkpass[i]!=pass[i])
              {
                   flag=1;
                   break;
              }
      }
    if(flag!=0)
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



int encrypt(char pass[])
{
    int i;
    for(i=0;i<strlen(pass);i++)
            pass[i]=pass[i]+10;
return 0;
}
int decrypt(char pass[])
{
    int i;
    for(i=0;i<strlen(pass);i++)
            pass[i]-=10;
return 0;
}
int fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
return 0;
}

int enterPass(char pass[])
 {
char ch;
int i=0,j;

puts("Enter password : ");

while (1)
{
if (i < 0) {
i = 0;
}

  ch = getch();

  if (ch == 13)
     break;

  if (ch == 8)
  {
     printf("\b\b");
     i--;
     system("cls");
     puts("Enter password :");
     for(j=0;j<i;j++)
     printf("*");
     continue;
  }
  pass[i] = ch;
  i++;
  ch = '*';
  printf("%c",ch);

}

pass[i] = '\0';
return 0;
}


int authenticate(int caser,char pass[])
    {

        int passer=0,count=4;
        char userpass[13];
    switch(caser)
    {
     case 1:
            enterPass(userpass);
            passer=strcmp(pass,userpass);
            while(passer!=0&&count>=0)
            {
                system("cls");
                printf("\n\tWrong Password\n\tEnter again:");
                enterPass(userpass);
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
            enterPass(userpass);
            passer=strcmp(pass,userpass);
            while(passer!=0&&count>=0)
            {
                system("cls");
                printf("\n\tWrong Password\n\tEnter again:");
                enterPass(userpass);
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

int adminMenu(int skipper)
    {
        if(skipper==1)
            goto skip;
        int j;
        FILE *adminpass;
        FILE *adminpass1;
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


                      adminpass1=fopen("AdminPassword.txt","r");

                      char pass2[13];
                      fscanf(adminpass1,"%s",pass2);
                      decrypt(pass2);
                      fclose(adminpass1);
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
                        changePassword(pass2);
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


             return 0;
    }

int mainMenu()
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
    return 0;
    }

int main()
    {
    system("COLOR 0A");
    mainMenu();
    system("cls");
    printf("\n\n\tThanks for visiting! Please visit again!\n\n");
    printf("\n\t*****PROJECT BY:******\n");
    credits();
    return 0;
    }
