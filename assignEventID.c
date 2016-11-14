long int assignEventID()
 {

 long int count;
  FILE *fp;
         fp=fopen("eventid.txt","r");
         fscanf(fp,"%ld",&count);
        fclose(fp);
        count++;
         fp=fopen("eventid.txt","w");
         fprintf(fp,"%ld\n",count);
         fclose(fp);
 return count;
 }
