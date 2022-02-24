#include<stdio.h>
int size,stack[10],tos = -1;
void push(int);
void pop();
void display();
int isFull();
int isEmpty();

void push(int x)
{
    if(isFull())
    {
        printf("Stack is Full ");
    }
    else
    {
        tos = tos + 1;
        stack[tos] = x;
    }
}

void pop()
{
    int de;
    if(isEmpty())
     {
        printf(" \nStack is empty ");
     }
    else
     {
        de = stack[tos];
        tos = tos - 1;
     }
    printf("\n Element '%d' deleted",de);
}

int isEmpty()
{
    if(tos == -1)
    return 1;

    else return 0;
}

int isFull()
{
    if(tos +1 == size)
    return 1;

    else return 0;
}

void display()
{
    int i;
    if(isEmpty())
    {
        printf("\nStack is empty ");
    }
    else
       {
           printf("\n Stack:");
           for(i=0;i<=tos;i++)
             {
            printf(" %d",stack[i]);
             }
       }
}

void main()
{
    printf(" Enter the size of the stack: ");
    scanf("%d",&size);
    int c,x;
    do
    {
        printf("\n Enter your choice: \n 1.Push an element \n 2.Pop an element \n 3.Display the stack. choice= ");
        scanf("%d",&c);

        switch(c)
        {
        case 1:
            printf("\n Enter the element to be pushed:");
            scanf("%d",&x);
            push(x);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        default: printf(" \nExited successfully ");
        }
      }
      while(c<4);
    }


