char characrepeat(char *str)
{
   int i;
   int len = strlen(str);
   int count[256];

   for(i=0;i<256;i++)
   {
    count[i]=0;
   }

   for(i=0;i<len;i++)
   {
     if(count[str[i]]==1)
     {
        printf("%c",str[i]);
        break;
     }
     else
     count[str[i]]++;
   }
   if(i==len)
   {
    printf("No Repeatative Characters\n");
   }
   return 0;
}