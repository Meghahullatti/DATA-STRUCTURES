#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX];
int top=-1;
void push ()
{
    int value;
    if (top==MAX-1)
    {
        printf("\n stack overflow");

    }
    else{
        printf("enter value to push:\n");
        scanf("%d",&value);
        top++;
        stack[top]=value;
        printf("%d pushed into stack\n",value);
    }
}
void pop()
{
    if(top==-1)
    {
        printf("\n stack is underflow");
    }
    else{
        printf("\npopped from stack \n",stack[top]);
        top--;
    }
}
void display()
{
    if(top==-1)
    {
        printf("stack is empty");
    }
    else{
        printf("\n stack elemnts are:");
        for(int i=top;i>=0;i++)
        {
            printf("%d",stack[i]);
        }
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("stack operations are:\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.display \n");
        printf("4.exit \n");
        printf("enter your choice:\n");
        scanf("%d",&choice);
    switch(choice)
    {
        case 1:
         push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\n Inavlid value");

    }
    }
    return 0;
}
# DATA-STRUCTURES