void enterPass(char pass[])
 {
char ch;
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
  pass[i] = ch;
  i++;
  ch = '*';
  printf("%c",ch);

}

pass[i] = '\0';
}
