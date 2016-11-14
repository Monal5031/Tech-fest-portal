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
