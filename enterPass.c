#include<stdio.h>

void enterPass(char password[])
 {
char password[13],ch;
int i=0,j;

puts("Enter password : ");

while (1)
{
if (i < 0) {
i = 0;
}

  ch = getch();

  if (ch == 13)
     break;

  if (ch == 8)
  {
     printf("\b\b");
     i--;
     system("cls");
     puts("Enter password :");
     for(j=0;j<i;j++)
     printf("*");
     continue;
  }
  password[i] = ch;
  i++;
  ch = '*';
  printf("%c",ch);

}

password[i] = '\0';
}

