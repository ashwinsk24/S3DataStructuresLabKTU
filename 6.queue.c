#include<stdio.h>
int size,queue[10];
int front = -1;
int rear = -1;
void enqueue(int);
void dequeue();
void display();
int isFullque();
int isEmptyque();

void enqueue(int x)
{
    if(isFullque())
    {
        printf(" Queue is Full ");
    }

    else if( front ==-1 && rear == -1)
        {
            front = 0;
            rear =0;
        }
        else
        rear = rear + 1;

   queue[rear] = x;

}

void dequeue()
{
    int de;
    if(isEmptyque())
     {
        printf(" \n Queue is empty ");
     }
    else
     {
        de = queue[front];
        front = front + 1;
     }
    printf("\n Element '%d' deleted",de);
}

int isEmptyque()
{
    if((rear == -1 && front == -1)|| (front > rear) )
    return 1;

    else return 0;
}

int isFullque()
{
    if(rear +1 == size)
    return 1;

    else return 0;
}

void display()
{
    int i;
    if(isEmptyque())
    {
        printf("\n Queue is empty ");
    }
    else
       {
           printf("\n Queue:");
           for(i=front;i<=rear;i++)
             {
            printf(" %d",queue[i]);
             }
       }
}

void main()
{
    printf(" Enter the size of the queue: ");
    scanf("%d",&size);
    int c,x;
    do
    {
        printf("\n Enter your choice: \n 1.Push an element \n 2.Pop an element \n 3.Display the Queue. choice= ");
        scanf("%d",&c);

        switch(c)
        {
        case 1:
            printf("\n Enter the element to be pushed:");
            scanf("%d",&x);
            enqueue(x);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        default: printf(" \nExited successfully ");
        }
      }
      while(c<4);
    }
