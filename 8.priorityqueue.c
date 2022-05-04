#include<stdio.h>

int i,j,size;
int front = -1;
int rear = -1;
void enqueuePQ(int, int);
void dequeuePQ();
void displayPQ();
int isFullPQ();
int isEmptyPQ();

struct elePQ
{
  int value;
  int priority;
}pq[10],tp;


void enqueuePQ(int x, int p)
{
    if(isFullPQ())
    {
        printf(" Queue is Full ");
    }

    else if(front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            pq[rear].value = x;
            pq[rear].priority = p;

        }
        else{
        rear = rear + 1;
        pq[rear].value = x;
        pq[rear].priority = p;
      }

}

void dequeuePQ()
{
    int de,dep;
    if(isEmptyPQ())
     {
        printf(" \n Queue is empty ");
     }
    else
     {
        for(i=0;i<size-1;i++)
        {
            for(j=0;j<size-i-1;j++)
            {
                if(pq[j].priority<pq[j+1].priority)
                {
                    tp=pq[j];
                    pq[j]=pq[j+1];
                    pq[j+1]=tp;
                }

            }
        }

        de = pq[front].value;
        dep = pq[front].priority;
        printf("\nElement %d with priority %d deleted \n",de,dep);
        front=front+1;


     }

    }

    void displayPQ()
    {
    int i;
    if(isEmptyPQ())
    {
        printf("\n Queue is empty ");
    }
    else
       {
        for(i=0;i<size-1;i++)
        {
            for(j=0;j<size-i-1;j++)
            {
                if(pq[j].priority<pq[j+1].priority)
                {
                    tp=pq[j];
                    pq[j]=pq[j+1];
                    pq[j+1]=tp;
                }
            }
        }

           printf("\n Queue:");
           for(i=front;i<=rear;i++)
           printf(" %d P[%d] ",pq[i].value, pq[i].priority);
    }
}

    int isEmptyPQ()
    {
    if((rear == -1 && front == -1) || front>rear)
    return 1;

    else return 0;
    }

    int isFullPQ()
    {
    if(rear +1 == size)
    return 1;

    else return 0;
    }

    void main()
{
    printf(" Enter the size of the Priority queue: ");
    scanf("%d",&size);
    int c,x,p;
    do
    {
        printf("\n Enter your choice: \n 1.Push an element \n 2.Pop an element \n 3.Display the Queue. \n 4.Check if queue is FULL \n 5.Check if queue is EMPTY. \n 6.Exit. choice: ");
        scanf("%d",&c);

        switch(c)
        {
        case 1:
            printf("\n Enter the element to be pushed:");
            scanf("%d",&x);
            printf("\n Enter the PRIORITY of the element:");
            scanf("%d",&p);
            enqueuePQ(x,p);
            break;

        case 2:
            dequeuePQ();
            break;

        case 3:
            displayPQ();
            break;

        case 4:
            if(isFullPQ())
            {
                printf("\n Queue is FULL ");
            }
            else
                printf("\n Queue is NOT FULL ");

            break;

        case 5:
            if(isEmptyPQ())
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
