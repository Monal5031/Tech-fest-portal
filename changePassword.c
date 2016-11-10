void changePassword(char pass[])
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
    password=fopen("AdminPassword.txt","w");
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
    encrypt(pass);
    fprintf(password,"%s",pass);
    fclose(password);
    system("cls");
    printf("\t\t**********PASSWORD CHANGE SUCCESSFULL**********");
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    fordelay(100000000);
    adminMenu(1);
}
