void modifyName(char event[])
{
    FILE *change;
    change=fopen("EventInfo.txt","r+");
    printf("Enter the New Name of the event: ");
    char newname[50],newname1[50];
    scanf("%s",newname);
    strcpy(newname1,newname);
    strcat(newname,"                   ");
    while(!feof(change))
    {
        char check[30];
        fscanf(change,"%s",check);
        if(strcmp(newname,check)==0)
        {
            fseek(change, -strlen(check), SEEK_CUR);
            fprintf(change,"%s",newname);
            break;
        }
    }
    system("cls");
    printf("\t\t*******EVENT NAME SUCCESSFULLY CHANGED*******");
    printf("\n\tOld Name:%s\n",event);
    printf("\tNew Name:%s",newname1);
   // fordelay(1000000);
    //fordelay(1000000);
    //fordelay(1000000);
    //fordelay(1000000);
    //adminMenu(1);

}
