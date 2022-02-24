#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *front;
struct node *rear;
void insert();
void delete();
void display();
void main ()
{
    int ch;
    while(ch != 4)
    {
        printf("\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
        printf("\nEnter your choice:");
        scanf("%d",& ch);
        switch(ch)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("\nEnter valid choice");
        }
    }
}
void insert()
{
    struct node *ptr;
    int item;

    ptr = (struct node *) malloc (sizeof(struct node));
    if(ptr == NULL)
    {
        printf("\nList is FULL");
        return;
    }
    else
    {
        printf("\nEnter the element: ");
        scanf("%d",&item);
        ptr -> data = item;
        if(front == NULL)
        {
            front = ptr;
            rear = ptr;
            front -> link = NULL;
            rear -> link = NULL;
        }
        else
        {
            rear -> link = ptr;
            rear = ptr;
            rear->link = NULL;
        }
    }
}
void delete ()
{
    struct node *ptr;
    if(front == NULL)
    {
        printf("\nList is EMPTY");
        return;
    }
    else
    {
        ptr = front;
        front = front -> link;
        free(ptr);
    }
}
void display()
{
    struct node *ptr;
    ptr = front;
    if(front == NULL)
    {
        printf("\nEmpty queue\n");
    }
    else
    {   printf("\nQueue: ");
        while(ptr != NULL)
        {
            printf("%d ",ptr -> data);
            ptr = ptr -> link;
        }
    }
}
