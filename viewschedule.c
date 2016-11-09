void schedule()
{

    FILE*fp;
    fp=fopen("schdule.txt","r");
    char ch;
    printf("\t\t\t\t*****Schedule*****\n\n");
    while(!feof(fp))
    {
       fscanf(fp,"%c",&ch);
        printf("%c",ch);

    }
fclose(fp);



}

