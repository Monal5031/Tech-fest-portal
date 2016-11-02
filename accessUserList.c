void accessUserList()
{
    FILE *access;
    char ch;
    printf("\n\t********LIST OF ALL THE PARTICIPANTS IN THE TECHFEST*******\n");
    access=fopen("UserList.txt","r");
    while(!feof(access))
    {
        fscanf(access,"%c",&ch);
        printf("%c",ch);
    }
    fclose(access);
    printf("\n\tWhere do you want to go?\n\t1.Main Menu\n\t2.Admin Menu\n\t");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        mainMenu();
        break;
    case 2:
        adminMenu(1);
        break;
    }
}
