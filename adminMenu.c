
void adminMenu()
    {
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

                }
            fclose(adminpass);
    }
