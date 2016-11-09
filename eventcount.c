int eventCount(int change)
{
    FILE *count;
    if(change==1)
        {
            int counter;
            count=fopen("EventCount.txt","r");
            fscanf(count,"%d",&counter);
            counter++;
            fclose(count);
            count=fopen("EventCount.txt","w");
            fprintf(count,"%d",counter);
            fclose(count);
            return 0;
        }
    else
        {
            count=fopen("EventCount.txt","r");
            fscanf(count,"%d",&counter);
            fclose(count);
            return counter;
        }


}
