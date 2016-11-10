#include<stdio.h>
#include<string.h>
int main()
{
    char id[10];
    scanf("%s",id);
    viewRegisteredList(id);
    return 0;
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

void viewRegisteredList(char id[])
{
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
}
