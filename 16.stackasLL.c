#include <stdio.h>
#include <stdlib.h>

void push();
void pop();
void display();
void status();

struct node
{
int data;
struct node *link;
};

struct node *head;

void main ()
{
    int ch=0;
    do
    {
        printf("\n1.Push\n2.Pop\n3.Display Status \n4.Exit");
        printf("\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push();
                display();
                break;

            case 2:
                pop();
                display();
                break;

            case 3:
                display();
                status();

                break;

            case 4:

                printf("Exited Successfully.");
                break;

            default:
                printf("Please Enter valid choice ");
          }
  }while(ch<5);
}

void push ()
{
    int val;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
        printf("not able to push the element");
    }
    else
    {
        printf("Enter the Element: ");
        scanf("%d",&val);
        if(head==NULL)
        {
            ptr->data = val;
            ptr -> link = NULL;
            head=ptr;
        }
        else
        {
            ptr->data = val;
            ptr->link = head;
            head=ptr;

        }
        printf("Element pushed ");

    }
}

void pop()
{
    int item;
    struct node *ptr;
    if (head == NULL)
    {
        printf(" Stack is EMPTY ");
    }
    else
    {
        item = head->data;
        ptr = head;
        head = head->link;
        free(ptr);
        printf("Element popped ");

    }
}
void display()
{
    int i;
    struct node *ptr;
    ptr=head;
    if(ptr == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("\n\nStack: ");
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr = ptr->link;
        }
    }
}

void status()
{
    int i,c=0;
    struct node *ptr;
    ptr=head;
    if(ptr == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
      int p = head->data;
      while(ptr!=NULL)
      {
          ptr = ptr->link;
          c++;
      }


      printf("\nElement at Top of Stack is '%d' ",p);
      printf("\nStack contains '%d' elements ",c);
    }
  }
