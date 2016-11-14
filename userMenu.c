void userMenu()
{
    system("cls");
    printf("\n\t1.New user\n\t2.Old User\n\t3.Event Information\n\t4.Event Schedule\n\t5.Main Menu");
    int choice;
    printf("\n\tEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        system("cls");
        newUser();
        break;
    case 2:
        system("cls");
        oldUser();
        break;
    case 3:
        system("cls");
        viewEventInfo(0,"");
        break;
    case 4:
        schedule("",0);
        break;
    case 5:
        system("cls");
        mainMenu();
    }
return;
}
