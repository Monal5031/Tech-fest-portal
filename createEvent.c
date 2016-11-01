void createEvent()
{
    char name[30];
    system("cls");
    printf("\n\tPlease Enter the name of event you want to create (Max Size 30): ");
    scanf("%s",name);
    FILE *create;
    FILE *registerevent;
    registerevent=fopen("EventList.txt","a");
    fprintf(registerevent,"\n\t-%s\n",name);
    printf("\n\tCongratulations! Event Created \n\tPlease Enter Following Information about the event\n\t");
    char time[10];
    printf("Enter Time(with am or pm without spacing) **(8 size max)**: ");
    scanf("%s",time);
    char info[1000];
    printf("\n\tEnter some Info about the event:");
    scanf("%s",info);
    fillEventInfo(name,time,info);
    printf("\n\tCongratulations! Event Successfully Registered");
    fclose(registerevent);
    strcat(name,".txt");
    create=fopen(name,"w");
    fclose(create);
}
