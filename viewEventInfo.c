void viewEventInfo()
{
    FILE *info;
    info=fopen("EventInfo.txt","r");
    char ch;
    while(!feof(info))
    {
        fscanf(info,"%c",&ch);
        printf("%c",ch);
    }
    fclose(info);
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
