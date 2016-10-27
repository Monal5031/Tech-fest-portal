#include<stdio.h>
#include<string.h>

int main()
{
    createEvent();
    return 0;
}
void createEvent()
{
    char name[30];
    system("cls");
    printf("\n\tPlease Enter the name of event you want to create (Max Size 30): ");
    inputInfo(name);
    FILE *create;
   // strcat(name,".txt");
    create=fopen("name.txt","w+");
    fprintf(create,"Name: %s\n",name);
    printf("\n\tCongratulations! Event Created \n\tPlease Enter Following Information about the event\n\t");
    char time[10];
    printf("Enter Time(with am or pm): ");
    inputInfo(time);
    fprintf(create,"%s",time);
    printf("\n\tCongratulations! Event Successfully Registered");
    fclose(create);
}


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
    name[i]='\0';
return;
}


