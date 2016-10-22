void mainMenu()
    {
    int choice,i=0;
    printf(("\n\n\n\tEnter which one you want to select:\n\n"));
    printf("\t1.Admin Login\n");
    printf("\t2.User Login\n");
    printf("\t3.Exit\n\tEnter:");
    scanf("%d",&choice);
    printf("\tOk! You chose choice no.:%d",choice);
    fordelay(100000000);
    system("cls");
    printf("Loading");
    for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
    system("cls");
    switch(choice)
    {
    case 1:
        adminMenu();
        break;
    case 2:
        //userMenu();
        break;
    case 3:
        printf("\n\n\tThanks for visiting! Please visit again!\n\n");
    }
    }
