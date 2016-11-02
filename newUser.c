void newUser()
{
    printf("\n\t*************Enter following Details*************\n\t");
    FILE *master;
    FILE *user;
    user=fopen("UserList.txt","a");
    master=fopen("MasterList.txt","a");
    printf("\n\tEnter your first name(15 letters max) : ");
    char name[21],lastname[10];
    scanf("%s",name);
    printf("\n\tEnter your last name(10 letters max) : ");
    scanf("%s",lastname);
    strcat(name," ");
    strcat(name,lastname);
    fprintf(master,"%s\n",name);
    fprintf(user,"%s\n",name);
    fclose(user);
    printf("\n\tEnter your College name : ");
    char college[30];
    scanf("%s",college);
    fprintf(master,"%s\n",college);
    printf("\n\tEnter a password for your account \n\t(Min.8 Max. 13 characters..Must contain: a special character [@,_,#,$,%,^,&,*] ,a uppercase letter,a lower case letter and a number)\n\tEnter::");
    int checker=0;
    char pass[13];
    while(checker!=1)
    {
    scanf("%s",pass);
    checker=checkPassword(pass);
    if(checker==1)
        printf("\n\tPassword Acceptable!");
    else
        printf("\n\tINVALID PASSWORD!!!\n\tEnter different password:");
    }
    srand(time(NULL));
    int x=rand();
    printf("\n\tYour ID is: %d",x);
    fprintf(master,"%d\n",x);

    fprintf(master,"%s\n",pass);
    fclose(master);
    printf("\n\tPlease NOTE this ID down for future use\n\tEnter 1 when Ready to Continue");
    int go;
    scanf("%d",&go);
    system("cls");
    printf("\t********REGISTRATION SUCCESSFULL*******");
    printf("\n\tEnter which event you want to register for one by one:\n\t");
    printf("\n\n\t*****************WARNING: ENTER THE NAME OF EVENT AS IT IS!**************************\n");
    viewList();
    FILE *event;
    while(1)
    {
    printf("\n\tEnter name of event:");
    char eventname[20];
    scanf("%s",eventname);
    strcat(eventname,".txt");
    event=fopen(eventname,"a");
    fprintf(event,"%s\n",name);
    printf("\n\n\tDo you wish to register for more events?\n\t1.Yes 2.No\n\t");
    printf("Enter: ");
    int choice;
    scanf("%d",&choice);
    fclose(event);
    if(choice==2)
        break;
    }
    printf("\n\n\t*******Events successfully Registered*******");
    printf("\n\tDo you wish to continue?\n\t1.Yes\n\t2.No");
    int next;
    scanf("%d",&next);
    if(next==1)
        userMenu();
    return;
}
