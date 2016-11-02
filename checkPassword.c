int checkPassword(char pass[])
{
    int special=0,up=0,low=0,no=0;
    int i;
    for(i=0;i<strlen(pass);i++)
    {
        if(pass[i]=='@'||pass[i]=='_'||pass[i]=='#'||pass[i]=='$'||pass[i]=='%'||pass[i]=='^'||pass[i]=='&'||pass[i]=='*')
            special++;

        else if(pass[i]>=65&&pass[i]<=90)
            up++;
        else if(pass[i]>=97&&pass[i]<=122)
            low++;
        else if(pass[i]>=48&&pass[i]<=57)
            no++;
    }
    if(special>0&&up>0&&low>0&&no>0)
        return 1;
    else
        return 0;
}
