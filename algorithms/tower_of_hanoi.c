#include<stdio.h>
#include<conio.h>

int tower(int n,char beg,char aux,char end)
{
    if(n<=0)
    {
        return -1;
    }
    else if( n==1)
    {
        printf("Move the dics from %c to %c \n ",beg,end);

    }
    else
    {
        tower(n-1,beg,end,aux);
        tower(1,beg,aux,end);
        tower(n-1,aux,beg,end);
    }
}

void main()
{
    int n;
    int a,b,c;
    printf("Enter the number of disc\n");
    scanf("%d",&n);
    printf("Tower of hanoi of %d disc\n",n);
     tower(n,'a','b','c');
}

