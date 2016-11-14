void schedule(char id[],int skip)
{
    system("cls");
    FILE *fp;
    fp=fopen("schedule.txt","r");
    char ch;
    printf("\t\t\t\t*****Schedule*****\n\n");
    while(!feof(fp))
    {
       fscanf(fp,"%c",&ch);
        printf("%c",ch);
    }
    printf("\b ");
fclose(fp);
fordelay(100000000);
fordelay(100000000);
fordelay(100000000);
fordelay(100000000);
fordelay(100000000);
fordelay(100000000);
fordelay(100000000);
fordelay(100000000);
fordelay(100000000);
fordelay(100000000);
if(skip==1)
    OldUserMenu(id);
if(skip==0)
    userMenu();
}
