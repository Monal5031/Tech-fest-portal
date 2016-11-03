void modifyEventInfo()
{
    loop:
    system("cls");
    viewList();
    printf("\t\t****Enter which event you want to modify*******\n");
    char event[30];
    printf("\nEnter Which do you want to modify:");
    scanf("%s",&event);
    printf("\tEnter what do you want to modify:\n\t");
    printf("1.Name\n\t2.Time\n\t3.Information\n\tEnter:");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        modifyName(event);
        break;
    case 2:
        modifyTime(event);
        break;
    case 3:
        modifyInfo(event);
    }
    printf("\n\n\n\tDo you wish to modify any more events?\n\t1.Yes\n\t2.No");
    int looper;
    scanf("%d",&looper);
    if(looper==1)
        goto loop;
    adminMenu(1);
    return;
}
