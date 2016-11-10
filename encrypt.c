void encrypt(char pass[])
{
    int i;
    for(i=0;i<strlen(pass);i++)
            pass[i]=pass[i]+10;
}


int main()
{
    char pass[13];
    scanf("%s",pass);
    encrypt(pass);
    printf("%s",pass);

    return 0;

}
