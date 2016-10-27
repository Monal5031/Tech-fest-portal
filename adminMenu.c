void adminMenu()
    {
        int j;
        FILE *adminpass;
        adminpass=fopen("AdminPassword.txt","r");
        int passer=0;
        char pass[13];
        fscanf(adminpass,"%s",pass);
        decrypt(pass);
        passer=authenticate(1,pass);
            if(passer==0)
                {
                  system("cls");
                    printf("\n\tLimit Exceeded!! \n\tTry Again!!");
                    return;
                }
            else
                {
                    system("cls");
                    int choice;
                    printf("\n\n\t1.Create Event\n\t2.Modify Event Information\n\t3.Change Password\n\t4.Main Menu");
                    printf("\n\tEnter your Choice:");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                    case 1:
                       // createEvent();
                        break;
                    case 2:
                       // modifyEvent();
                        break;
                    case 3:
                        changePassword(pass);
                        break;
                    case 4:
                        system("cls");
                        printf("Loading");
                        for(j=0;j<=6;j++)
                            {
                            fordelay(100000000);
                            printf(".");
                            }
                            mainMenu();
                    }
                }
            fclose(adminpass);
            printf("\n\tDO you want to continue?\n\t1.Yes\n\t2.No\n\t");
            scanf("%d",&j);
            if(j==1)
                mainMenu();
            else
            {
                printf("\n\n\tThanks for visiting! Please visit again!\n\n");
             return;
            }
    }
