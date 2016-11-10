void fillEventInfo(char name[],char time[],char infor[])
{
    FILE *info;
    info=fopen("EventInfo.txt","a");
    fprintf(info,"\n");
    fprintf(info,"Name:%s\n",name);
    fprintf(info,"Time:%s\n",time);
    fprintf(info,"Information:%s\n",infor);
    fclose(info);
}
