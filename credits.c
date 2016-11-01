void credits()
{
    FILE *credit;
    credit=fopen("Credits.txt","r");
    while(!feof(credit))
    {
        char ch;
        fscanf(credit,"%c",&ch);
        fordelay(10000001);
        printf("%c",ch);
    }
    printf("\b ");
    fclose(credit);
}
