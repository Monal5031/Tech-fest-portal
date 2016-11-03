void adminMenu(int skipper)
    {
        if(skipper==1)
            goto skip;
        int j;
        FILE *adminpass;
        adminpass=fopen("AdminPassword.txt","r");
        int passer=0;
        char pass[13];
        fscanf(adminpass,"%s",pass);
        decrypt(pass);
        fclose(adminpass);
        passer=authenticate(1,pass);
            if(passer==0)
                {
                  system("cls");
                    printf("\n\tLimit Exceeded!! \n\tTry Again!!");
                    return;
                }
            else
                {
                    skip:
                    system("cls");
                    int choice;
                    printf("\n\n\t1.Create Event\n\t2.Modify Event Information\n\t3.Change Password\n\t4.Access User List(All Events)\n\t5.Access Event Wise List\n\t6.Log Out");
                    printf("\n\tEnter your Choice:");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                    case 1:
                        createEvent();
                        break;
                    case 2:
                       modifyEventInfo();
                        break;
                    case 3:
                        changePassword(pass);
                        break;
                    case 4:
                        accessUserList();
                    break;
                    case 5:
                        accessEventWiseList();
                        break;
                    case 6:
                        system("cls");
                        printf("Loading");
                        for(j=0;j<=6;j++)
                            {
                            fordelay(100000000);
                            printf(".");
                            }
                            mainMenu();
                            break;
                    }
                }


             return;
    }
