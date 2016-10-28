void inputInfo(char name[])
{

int i=0;
    char ch;
    do{
        scanf("%c",&ch);
        if(ch=='\n')
            break;
        name[i]=ch;
        i++;
    }
    while(1);
}
