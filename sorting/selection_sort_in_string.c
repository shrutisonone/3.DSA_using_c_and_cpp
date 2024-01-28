#include<stdio.h>
#include<string.h>

int main()
{
    int i=0,j=0;
    char str[5][15];
    char p[5];

    //array of strings 
    printf("Enter a names \n");
    for(i=0;i<5;i++)
    {
        gets(str[i++]);
    }
    
    //before sorting the display of array
    printf("Before Sorting \n"); 
    for(i=0;i<5;i++)
    {
        puts(str[i]);
    }

    
    return 0;
}