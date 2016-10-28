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
