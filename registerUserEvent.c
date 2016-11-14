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
