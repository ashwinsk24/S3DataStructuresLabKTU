#include<stdio.h>

int size,queue[10];
int front;
int rear = -1;
void deletefront();
void insertrear(int);
void deleterear();
void insertfront(int);
void display();
int isFullque();
int isEmptyque();

void deletefront()
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

void insertfront(int x)
{
      front = front - 1;
      queue[front] = x;

}

void deleterear()
{
    int de;
    if(isEmptyque())
     {
        printf(" \n Queue is empty ");
     }
    else
     {
        de = queue[rear];
        rear = rear - 1;
     }
    printf("\n Element '%d' deleted",de);
}


void insertrear(int x)
{
    if(isFullque())
    {
        printf(" Queue is Full ");
    }

    else
    {
      rear = rear + 1;
      queue[rear] = x;
    }
}


int isEmptyque()
{
    if((rear == -1 && front == -1))
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
           for(i=front ;i <= rear ;i++)
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
        printf("\n Enter your choice: \n1.Push an element from rear\n2.Pop an element from front\n3.Push an element from front\n4.Pop an element from rear \n 5.Display the Queue. choice= ");
        scanf("%d",&c);

        switch(c)
        {
        case 1:
            printf("\n Enter the element to be pushed from rear :");
            scanf("%d",&x);
            insertrear(x);
            display();
            break;

        case 2:
            deletefront();
            display();
            break;

        case 3:
            printf("\n Enter the element to be pushed from front :");
            scanf("%d",&x);
            insertfront(x);
            display();
            break;

        case 4:
            deleterear();
            display();
            break;


        case 5:
            display();
            break;

        default: printf(" \nExited successfully ");
        }
      }
      while(c<6);
    }
