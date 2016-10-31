void userMenu()
{
    system("cls");
    printf("\n\t1.New user\n\t2.Old User\n\t3.Main Menu");
    int choice;
    printf("\n\tEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        system("cls");
        //newUser();
        break;
    case 2:
        system("cls");
        //oldUser();
        break;
    case 3:
        system("cls");
        mainMenu();
    }
return;
}
