void OldUserMenu(char id[])
{
    char pass[13];
    FILE *passf;
    passf=fopen("CurrentPassword.txt","r");
    fscanf(passf,"%s",pass);
    system("cls");
    printf("\t***********LOGGED IN*******");
    printf("\n\n\t1.Register for new Events\n\t2.List of Events Registered\n\t3.Display Event Information\n\t");
    printf("4.View Event List\n\t5.Event Schedule\n\t6.Change password\n\t7.LogOut\n\tEnter:");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        registerUserEvent(id);
        system("cls");
        break;
    case 2:
        viewRegisteredList(id);
        system("cls");
        break;
    case 3:
        viewEventInfo(1,id);
        system("cls");
        break;
    case 4:
        viewList(1,id);
        system("cls");
        break;
    case 5:
        schedule(id,1);
        system("cls");
        break;
    case 6:
        changeUserPass(id,pass);
        break;
    case 7:
        system("cls");
        int i;
        printf("Loading");
        for(i=0;i<=6;i++)
        {
            printf(".");
            fordelay(1000000);
            fordelay(1000000);
            fordelay(1000000);
        }
        mainMenu();
        break;
    }
}
