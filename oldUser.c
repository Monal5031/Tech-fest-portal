void oldUser()
{
    system("cls");
    printf("\n\n\n\t\tEnter User Id:");
    char user[10];
    loop:
    scanf("%s",user);
    FILE *search;
    int finder=0;
    search=fopen("MasterList.txt","r");
    char pass[15];
    while(!feof(search))
    {
        char id[10];
        fscanf(search,"%s",id);
        if(strcmp(id,user)==0)
        {
            char ch;
            fscanf(search,"%c",&ch);
            fscanf(search,"%s",pass);
            finder=1;
            break;
        }
    }
    if(finder==0)
    {
        printf("\n\tWrong ID! Please Enter a correct ID");
        goto loop;
    }
    loop1:
    system("cls");
    char userpass[13];
    enterPass(userpass);
    printf("Verifying");
    int i;
    for(i=0;i<6;i++)
    {
        printf(".");
        fordelay(100000);
    }
    if(strcmp(userpass,pass)!=0)
    {
        printf("\n\tWrong Password! Enter Correct Password\n\tEnter:");
        goto loop1;
    }
   FILE *passf;
    passf=fopen("CurrentPassword.txt","w");
    fprintf(passf,"%s",pass);
    fclose(passf);
    OldUserMenu(user);
}
