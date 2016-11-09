#include<stdio.h>
#include<string.h>
int main()
{
    char id[1000000];
    scanf("%s",id);
    registerUserEvent(id);
    return 0;
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
            return 0;
        }
    else
        {
            count=fopen("EventCount.txt","r");
            fscanf(count,"%d",&counter);
            fclose(count);
            return counter;
        }


}

void registerUserEvent(char id[])
{
    //char name[30];
    //printf("Enter Your First Name and Last Name separated by a space as registered: ");
    //gets(name);
    FILE *master;
    master=fopen("MasterList.txt","r");
    char eventid[20];
    char faltu[13];
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
    for( i=1;i<n+1;i++)
    {
        if(eventid[i]=='0')
        {
            char event[20];
            char ev[2];
            ev[0]=i+48;
            ev[1]='.';
            strcat(event,ev);
            char check[20];
            eventfile=fopen("EventList.txt","r");
                while(!feof(eventfile))
                {
                    fscanf(eventfile,"%s",check);
                    if(strcmp(check,ev)==0)
                        {
                        fscanf(eventfile,"%s",event);
                        printf("%d. %s",i,event);
                        break;
                        }
                }
        }
        printf("SUCCESSFULL");
    }
     fclose(eventfile);
    printf("SUCCESS");
/*
    printf("\n\tEnter which event you want to register for one by one:\n\t");
    printf("\n\n\t*****************WARNING: ENTER THE NAME OF EVENT AS IT IS!**************************\n");
    viewList();
    while(1)
    {
        FILE *eventfile1;
    printf("\n\tEnter event number and the name of event (separated by space):");
    char eventname[20];
    int i;
    scanf("%d",&i);
    eventid[i]='1';
    scanf("%s",eventname);
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

    master=fopen("MasterList.txt","r+");
    while(!feof(master))
    {
        fscanf(master,"%s",checkid);
        if(strcmp(checkid,id)==0)
        {
            fscanf(master,"%c",&ch);
            fscanf(master,"%s",faltu);
            fscanf(master,"%c",&ch);
            fprintf(master,"%s",eventid);
            break;
        }
    }
    fclose(master);*/
}
