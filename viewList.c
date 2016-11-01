void viewList()
{
    FILE *view;
    view=fopen("EventList.txt","r");
    while(!feof(view))
    {
        char *event;
        fscanf(view,"%s",event);
        printf("%s\n",event);

    }
}
