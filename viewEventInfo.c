void viewEventInfo(int skipper,char id[])
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
}
