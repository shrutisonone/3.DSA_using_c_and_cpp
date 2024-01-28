#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<conio.h>

int i = 0;
int top = -1;
char arr[20],stack[20];
void push(char);

void pop();

int main()
{
  printf("Enter the Expression\n");
  scanf("%s",&arr);
 
 for(i=0;arr[i]!='\0';i++)
 {
    if(arr[i] == '(')
    {
        push(arr[i]);
    }
    elseif(arr[i] == ')');
    {
        pop();
    }
    if(top == -1)
    {
        printF("The expression is valid\n");
    }
    else
    {
        printf("The expression is invalid\n");
    }
 }
}

void push(char arr)
{
  top = top + 1;
  stack[top] =arr;
}

void pop()
{
    top = top -1;
}