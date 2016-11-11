 #include<stdio.h>
 #include<conio.h>

 long int eventid()
 {

 int m,q,count;

 q=0;
 count=20160001;
  FILE *fp1;
         fp1=fopen("eventid.txt","r");


        for(m=fgetc(fp1);m!=EOF;m=fgetc(fp1))
        {
         if(m=='\n')
          q++;

        }
        fclose(fp1);
        count+=q;
  FILE *fp2;
         fp2=fopen("eventid.txt","a");
         fprintf(fp2,"%ld\n",count);
         fclose(fp2);

         sprintf(usrid,"ifest_%ld",count);

        FILE *ee;
        ee=fopen(usrid,"w");

        fclose(ee);
 return (count)
 }
