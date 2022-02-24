#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *llink;
    int data;
    struct node *rlink;
};

struct node *head;
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
            display();
            break;

            case 2:
            delete();
            display();
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);
            break;

            default:
            printf("\nEnter valid choice.");
        }
    }
}


void insert()
{
   struct node *ptr,*temp;
   int item;
   ptr = (struct node *) malloc(sizeof(struct node));
   if(ptr == NULL)
   {
       printf("\nList is FULL ");
   }
   else
   {
       printf("\nEnter element: ");
       scanf("%d",&item);
        ptr->data=item;
       if(head == NULL)
       {
           ptr->rlink = NULL;
           ptr->llink = NULL;
           head = ptr;
       }
       else
       {
          temp = head;
          while(temp->rlink!=NULL)
          {
              temp = temp->rlink;
          }
          temp->rlink = ptr;
          ptr ->llink=temp;
          ptr->rlink = NULL;
          }

       }
     printf("\n Node inserted ");
}

void delete()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("\n List is EMPTY ");
    }
    else if(head->rlink == NULL)
    {
        head = NULL;
        free(head);
        printf("\nNode deleted ");
    }
    else
    {
        ptr = head;
        head = head -> rlink;
        head -> llink = NULL;
        free(ptr);
        printf("\nNode deleted ");
    }

}

void display()
{
    struct node *ptr;
    printf("\n List: ");
    ptr = head;
    if(ptr == NULL)
    {
        printf("\n List is EMPTY ");
    }
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->rlink;
    }
}
