#include<stdio.h>

int i,n;
int cqueue[10];
int front = 0;
int rear = 0;
void enqueueCQ(int);
void dequeueCQ();
int isFullCQ();
int isEmptyCQ();
void displayCQ();

void enqueueCQ(int x)
{
    if(isFullCQ())
    {
        printf("\n C Queue is FULL ");
    }
    else
        {
            rear = (rear+1)%n;
            cqueue[rear] = x;
        }
}


void dequeueCQ()
{
    int de;
    if(isEmptyCQ())
    {
        printf("\n C Queue is EMPTY ");
    }
    else
        {
            front = (front+1)%n;
            de = cqueue[front];


        }
   printf("\n Element '%d' deleted",de);
}

void displayCQ()
{

    if(isEmptyCQ())
    {
        printf("\n C Queue is EMPTY ");
    }
     else
        {
            printf("\n C Queue:");
            for( i=(front+1)%n; i != (rear+1)%n ; i=(i+1)%n )
              {
              printf(" %d",cqueue[i]);

              }
        }
}

int isEmptyCQ()
{
    if(front == rear)
    return 1;

    else
        return 0;
}

int isFullCQ()
{
    if((rear +1)%n == front)
    return 1;

    else return 0;
}



void main()
{
    printf(" Enter the size of the Circular queue: ");
    scanf("%d",&n);
    n=n+1;
    int c,x;
    do
    {
        printf(" Enter your choice: \n 1.Push an element \n 2.Pop an element \n 3.Display the Queue. \n 4.Check if queue is FULL \n 5.Check if queue is EMPTY. \n 6.Exit. choice= ");
        scanf("%d",&c);

        switch(c)
        {
        case 1:
            printf("\n Enter the element to be pushed:");
            scanf("%d",&x);
            enqueueCQ(x);
            break;

        case 2:
            dequeueCQ();
            break;

        case 3:
            displayCQ();
            break;

        case 4:
            if(isFullCQ())
            {
                printf("\n Queue is FULL ");
            }
            else
                printf("\n Queue is NOT FULL ");

            break;

        case 5:
            if(isEmptyCQ())
                {
                    printf("\n Queue is EMPTY ");

                }
                else
                    printf("\n Queue is NOT EMPTY ");
            break;

        default: printf(" \nExited successfully ");
        }
      }
      while(c<6);
}
