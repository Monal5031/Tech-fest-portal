void viewList(int skipper,char id[])
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
}
