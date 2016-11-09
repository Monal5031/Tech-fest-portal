#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    oldUserMenu();
    return 0;
}

void OldUserMenu(char id[])
{
    system("cls");
    printf("\t***********Congratulations! Login Successful!*******");
    printf("\n\n\t1.Register for new Events\n\t2.List of Events Registered\n\t3.Display Event Information\n\t");
    printf("4.View Event List\n\t5.LogOut");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        registerUserEvent(id);
        break;
    case 2:
        viewRegisteredList(id);
        break;
    case 3:
        viewEventInfo();
        break;
    case 4:
        viewList();
        break;
    case 5:
        mainMenu();
        break;
    }
}
