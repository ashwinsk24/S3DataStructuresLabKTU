#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* link;
};
struct node *head;

void insertbegin();
void insertlast();
void insertatkey();
void deletebegin();
void deletelast();
void deleteatkey();
void display();

void main()
{
  int ch;
  do
  {
    printf("\n1.Insert in begining\n2.Insert at last\n3.Insert node after a key element\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after a key element\n7.Display \n8.Exit\n");
    printf("\nEnter your choice?\n");
    scanf(" %d", &ch);
    switch (ch)
    {
      case 1:
      insertbegin();
      break;

      case 2:
      insertlast();
      break;

      case 3:
      insertatkey();
      break;

      case 4:
      deletebegin();
      break;

      case 5:
      deletelast();
      break;

      case 6:
      deleteatkey();
      break;

      case 7:
      display();
      break;

      default: printf(" Exited Successfully. ");
    }
  }while (ch<8);

}


void insertbegin()
{
  struct node *ptr;
  int x;
  ptr = (struct node*)malloc(sizeof(struct node*));
  if(ptr == NULL)
  {
    printf(" List is Full ");
  }
  else
  {
    printf(" Enter the node element: ");
    scanf("%d", &x);
    ptr->data = x;
    ptr->link = head;
    head = ptr;
    printf(" Node inserted ");
  }
}

void insertlast()
{
  struct node *ptr, *ptr1;
  int x;
  ptr = (struct node*)malloc(sizeof(struct node));
  if(ptr == NULL)
  {
    printf(" List is Full ");
  }
  else
  {
    printf(" Enter the node element: ");
    scanf("%d", &x);

    ptr->data = x;
    ptr->link = head;

    if(head == NULL)
    {
      ptr->link = NULL;
      head = ptr;
      printf(" Node inserted ");
    }
    else
    {
      ptr1 = head;
      while (ptr1->link != NULL)
      {
        ptr1 = ptr1->link;
      }
      ptr1->link = ptr;
      ptr->link = NULL;
      printf(" Node inserted ");

    }
  }
}

void insertatkey()
{
    int i,key,x;
    struct node *ptr, *ptr1;
    ptr = (struct node *) malloc (sizeof(struct node));
    if(ptr == NULL)
    {
        printf("List is Full ");
    }

    else
    {
        printf("Enter the key element after which insertion should happend ");
        scanf("%d",&key);
        printf("\nEnter node element: ");
        scanf("%d",&x);
        ptr1=head;
        while (key!=ptr1->data)
        {
            ptr1 = ptr1->link;
        }
        ptr->data = x;
        ptr->link = ptr1->link;
        ptr1 ->link = ptr;
        printf(" Node element %d inserted at %d",x);
    }
}

void deletebegin()
{
    struct node *ptr;
    if(head == NULL)
    {
        printf(" List is empty ");
    }
    else
    {
        ptr = head;
        head = ptr->link;
        free(ptr);
        printf(" Node deleted ");
    }
}

void deletelast()
{
    struct node *ptr,*ptr1;
    if(head == NULL)
    {
        printf(" List is empty ");
    }
    else if(head ->link == NULL)
    {
        head = NULL;
        free(head);
        printf(" Node Deleted ");
    }

    else
    {
        ptr = head;
        while(ptr->link != NULL)
        {
            ptr1 = ptr;
            ptr = ptr ->link;
        }
        ptr1->link = NULL;
        free(ptr);
        printf(" Node Deleted ");
    }
}

void deleteatkey()
{
    struct node *ptr,*ptr1;
    int key,i;
    printf(" Enter the key element which you want to perform deletion \n");
    scanf("%d",&key);
    if(ptr == NULL)
     {
         printf(" Deletion not possible ");
         return;
     }
    ptr1=head;
    while (key!=ptr1->data)
    {
        ptr1 = ptr1->link;
    }
    ptr = ptr1->link;
    ptr1 ->link = ptr ->link;
    ptr->link = NULL;
    int de = ptr->data;
    free(ptr);
    printf(" Node element %d deleted",de);
}

void display()
{
    struct node *ptr;
    ptr = head;
    if(ptr == NULL)
    {
        printf(" List Empty ");
    }
    else
    {
        printf(" List: ");
        while (ptr!=NULL)
        {
            printf(" %d ",ptr->data);
            ptr = ptr -> link;
        }
    }
}
