#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *llink;
    int data;
    struct node *rlink;
};

struct node *head;
void insertstart();
void insertlast();
void insertatpos();
void deletestart();
void deletelast();
void deleteatpos();
void display();

void main ()
{
int ch=0;
    do
    {
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert a node after a given node \n4.Delete from Beginning\n5.Delete from last\n6.Delete the node after a given data\n7.Exit\n");
        printf("\nEnter your choice: ");
        scanf("\n%d",&ch);
        switch(ch)
        {
            case 1:
            insertstart();
            display();
            break;

            case 2:
            insertlast();
            display();
            break;

            case 3:
            insertatpos();
            display();
            break;

            case 4:
            deletestart();
            display();
            break;

            case 5:
            deletelast();
            display();
            break;

            case 6:
            deleteatpos();
            display();
            break;

            case 7:
            exit(0);
            break;

            default:
            printf("\nWrong Choice.");
        }
    }while(ch< 8);
}

  void insertstart()
  {
   struct node *ptr;
   int item;
   ptr = (struct node *)malloc(sizeof(struct node));
   if(ptr == NULL)
   {
       printf("\nOVERFLOW");
   }
   else
   {
    printf("\nEnter element value: ");
    scanf("%d",&item);

   if(head==NULL)
   {
       ptr->rlink = NULL;
       ptr->llink=NULL;
       ptr->data=item;
       head=ptr;
   }
   else
   {
       ptr->data=item;
       ptr->llink=NULL;
       ptr->rlink = head;
       head->llink=ptr;
       head=ptr;
   }
   printf("\nNode inserted");
}

}

void insertlast()
{
   struct node *ptr,*temp;
   int item;
   ptr = (struct node *) malloc(sizeof(struct node));
   if(ptr == NULL)
   {
       printf("\nOVERFLOW");
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

void insertatpos()
{
   struct node *ptr,*temp;
   int item,key,i;
   ptr = (struct node *)malloc(sizeof(struct node));
   if(ptr == NULL)
   {
       printf("\n OVERFLOW");
   }
   else
   {
       temp=head;
       printf("Enter the key element after which insertion should happend ");
       scanf("%d",&key);
       while (key!=temp->data)
       {
           temp = temp->rlink;
       }

       if(temp == NULL)
           {
               printf("\n Insertion not possible ");
               return;
           }
       }
       printf("Enter element: ");
       scanf("%d",&item);
       ptr->data = item;
       ptr->rlink = temp->rlink;
       ptr -> llink = temp;
       temp->rlink = ptr;
       temp->rlink->llink=ptr;
       printf("\nNode inserted ");
   }


void deletestart()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf("\n UNDERFLOW");
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
void deletelast()
{
    struct node *ptr,*temp;
    if(head == NULL)
    {
        printf("\n UNDERFLOW");
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
        while(ptr->rlink != NULL)
        {
            temp = ptr;
            ptr = ptr -> rlink;
        }
        temp->rlink = NULL;
        free(ptr);
        printf("\nNode deleted ");
    }
}
void deleteatpos()
{
    struct node *ptr, *temp;
    int val;
    printf("\n Enter the data after which the node is to be deleted : ");
    scanf("%d", &val);
    ptr = head;
    while(ptr -> data != val)
    ptr = ptr -> rlink;
    if(ptr -> rlink == NULL)
    {
        printf("\nCan't delete ");
    }
    else if(ptr -> rlink -> rlink == NULL)
    {
        ptr ->rlink = NULL;
    }
    else
    {
        temp = ptr -> rlink;
        ptr -> rlink = temp -> rlink;
        temp -> rlink -> llink = ptr;
        free(temp);
        printf("\nNode deleted");
    }
}
void display()
{
    struct node *ptr;
    printf("\n List: ");
    ptr = head;
    while(ptr != NULL || head == NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->rlink;
    }
}
