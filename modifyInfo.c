void modifyInfo(char event[])
{
    FILE *change;
    change=fopen("EventInfo.txt","r+");
    printf("Enter the New Information of the event: ");
    char newinfo[100],newinfo1[100];
    char ch1; int i=0;
    while(1)
    {
        scanf("%c",&ch1);
        if(ch1=='\n')
            break;
        newinfo[i]=ch1;
        i++;
    }
    strcpy(newinfo1,newinfo);
    strcat(newinfo,"                   ");
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
            fscanf(change,"%c",&ch);
            fprintf(change,"\n%s",newinfo);
            break;
        }
    }
    system("cls");
    printf("\t\t*******EVENT INFORMATION SUCCESSFULLY CHANGED*******\n");
    printf("\tNew Information:%s",newinfo);
    fordelay(1000000);
    fordelay(1000000);
    fordelay(1000000);
    fordelay(1000000);
}
