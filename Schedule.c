#include<stdio.h>
int main()
{
    char id[10]="11193";
    schedule(id);
    return 0;
}
void schedule(char id[])
{

    FILE *fp;
    fp=fopen("schedule.txt","r");
    char ch;
    printf("\t\t\t\t*****Schedule*****\n\n");
    while(!feof(fp))
    {
       fscanf(fp,"%c",&ch);
        printf("%c",ch);
    }
    printf("\b ");
fclose(fp);
}
