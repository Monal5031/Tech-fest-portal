
void accessEventWiseList()
{
    system("cls");
    viewList();
    while(1)
    {
        FILE *access;
        printf("\n\tEnter which Event's List you want (exactly same)\n");
        char event[20];
        scanf("%s",event);
        strcat(event,".txt");
        access=fopen(event,"r");
        char ch='0';
        printf("\n\t\t*********List of Registered Users*********\n");
        while(!feof(access))
            {
            fscanf(access,"%c",&ch);
            printf("%c",ch);
            }
        printf("\n\tDo you wish to view another event's list?\n");
        printf("\t1.Yes\n\t2.No");
        int choice;
        scanf("%d",&choice);
        fclose(access);
        if(choice==2)
            break;
    }
    system("cls");
    adminMenu(1);
}
