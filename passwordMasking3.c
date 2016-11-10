

#include<stdio.h>
#include<conio.h>

void main() {
   char password[25], ch;
   int i,j;


   puts("Enter password : ");

   while (1) {
      if (i < 0) {
         i = 0;
      }
      ch = getch();

      if (ch == 13)
         break;
      if (ch == 8)
      {
         putch('\b');
         putch('\b');
         i--;
         system("cls");
         puts("Enter password : ");
         for(j=0;j<i;j++)
         printf("*");

         continue;
      }

      password[i++] = ch;
      ch = '*';
      putch(ch);
   }

   password[i] = '\0';
   printf("\nPassword Entered : %s", password);

   getch();
}
