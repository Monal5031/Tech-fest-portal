void changeUserPass(char user[],char pass[])
{
    system("cls");
    up:
    printf("");
    char checkpass[13];
    printf("\tEnter Your Old Password:");
    scanf("%s",checkpass);
    if(strcmp(checkpass,pass)!=0)
    {
        printf("WRONG PASSWORD!! ENTER AGAIN:\n\t");
        goto up;
    }
    FILE *password;
    password=fopen("CurrentPassword.txt","w");
    system("cls");
    upper:
    printf("\n\t*************Enter New Password**********\nPassword must contain: an uppercase letter, a lowercase letter a number and \na special character[@,#,$,^,%,&,*,]\nEnter:");
    re:
    scanf("%s",pass);
    int check=checkPassword(pass);
    if(check!=1)
    {
        printf("\tINVALID PASSWORD\n\tPLEASE ENTER A VALID PASSWORD\n");
        printf("ENTER:");
        goto re;
    }
    printf("\n**VALID PASSWORD**\n");
    printf("\nEnter Password Again:");
    scanf("%s",checkpass);
    if(strcmp(checkpass,pass)!=0)
    {
        printf("PASSWORDS DO NOT MATCH ENTER NEW AGAIN");
        goto upper;
    }
    //encrypt(pass);
    fprintf(password,"%s",pass);
    fclose(password);
    system("cls");
    printf("\t\t**********PASSWORD CHANGE SUCCESSFULL**********");
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    FILE *master,*copy;
    master=fopen("MasterList.txt","r");
    copy=fopen("COPY1.txt","w");
    char checkid[100];
    while(!feof(master))
    {
        fgets(checkid,100,master);
        //fscanf(master,"%s",checkid);
        if(strncmp(checkid,user,strlen(user))==0)
        {
            fprintf(copy,"%s",checkid);
            fprintf(copy,"%s\n",pass);
            fgets(checkid,100,master);
        }
        else
        fprintf(copy,"%s",checkid);
    }
    fclose(password);
    fclose(master);
    fclose(copy);
    fordelay(10000000000000);
    int rem=remove("MasterList.txt");
    printf("\n\n\t\t%d",rem);
    rename("COPY1.txt","MasterList.txt");
    OldUserMenu(user);
}
