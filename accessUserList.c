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
    printf("\n\tAre you ready to continue?\n\tEnter 1 when you are!");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
        adminMenu();
}
