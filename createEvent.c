void createEvent()
{
    char name[30];
    system("cls");
    printf("\n\tPlease Enter the name of event you want to create (Max Size 30): ");
    scanf("%s",name);
    FILE *create;
    FILE *registerevent;
    registerevent=fopen("EventList.txt","a");
    fprintf(registerevent,"\n\t-%s",name);
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
    printf("\n\tDO You want to continue?");
    printf("\n\t1.Yes\n\t2.No\n\tEnter:");
    int tp;
    scanf("%d",&tp);
    if(tp==1)
    {
        system("cls");
        printf("\n\tWhere do you want to go?\n");
        printf("1.Main Menu\n\t2.Admin Menu\n\t");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            mainMenu();
            break;
        case 2:
            adminMenu(1);
        }
    }
}
