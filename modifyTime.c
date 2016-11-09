void modifyTime(char event[])
{
    FILE *change;
    change=fopen("EventInfo.txt","r+");
    printf("Enter the New time of the event(e.g.08:00am): ");
    char newtime[50],newtime1[50];
    scanf("%s",newtime);
    strcpy(newtime1,newtime);
    strcat(newtime,"                   ");
    char eventname[50]="Name:";
    strcat(eventname,event);
    char check[30];
    while(!feof(change))
    {
        fscanf(change,"%s",check);
        if(strcmp(eventname,check)==0)
        {
            char ch;
            fscanf(change,"%c",&ch);
            fscanf(change,"%s",check);
            fseek(change,-strlen(check), SEEK_CUR);
            fprintf(change,"Time:%s",newtime);
            break;
        }
    }
    system("cls");
    printf("\t\t*******EVENT TIME SUCCESSFULLY CHANGED*******");
    printf("\n\tOld time:%s\n",check);
    printf("\tNew Time:%s",newtime1);
    fordelay(1000000);
    fordelay(1000000);
    fordelay(1000000);
    fordelay(1000000);

}
