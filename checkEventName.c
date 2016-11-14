int checkEventName(char event[])
{
    FILE *ev;
    ev=fopen("TEMPE.txt","r");
    char check[30];
    while(!feof(ev))
    {
        fscanf(ev,"%s",check);
        if(strcmp(check,event)==0)
            return 0;
    }
    return 1;
}
