#include<stdio.h>
//#include<conio.h>

void main() {
   char password[25], ch;
   int i,j;


   puts("Enter password : ");

   while (1) {
      if (i < 0) {
         i = 0;
      }
      ch = getc(stdin);

      if (ch == 13)
         break;
      if (ch == 8)
      {
         putc('\b',stdout);
         putc('\b',stdout);
         i--;
         system("cls");
         puts("Enter password : ");
         for(j=0;j<i;j++)
         printf("*");

         continue;
      }

      password[i++] = ch;
      ch = '*';
      putc(ch,stdout);
   }

   password[i] = '\0';
   printf("\nPassword Entered : %s", password);

   getc(stdin);
}
