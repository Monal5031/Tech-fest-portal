int checkEventNumber(int i)
{
    FILE *check;
    int checkn;
    check=fopen("TEMPN.txt","r");
    while(!feof(check))
    {
        fscanf(check,"%d",&checkn);
        if(checkn==i)
            return 0;

    }
    return 1;
}
