#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* link;
};
struct node *create(struct node*,int);
void display(struct node*);
void search(struct node*,int);
struct node *merge(struct node*, struct node*);
void main()
{
  int i,ch,x,y,l,n;
    struct node *list1 = NULL;
    struct node *list2 = NULL;
    struct node *list3 = NULL;

  do
  {
    printf("\n1.Insert element of L1\n2.Insert element of L2 \n3.Merge \n4.Search \n5.Exit Choice: ");
    scanf("%d",&ch);
        switch(ch)
        {
            case 1:

            printf(" Enter the Element of L1 ");
            scanf("%d",&x);
            list1 = create(list1, x);
            display(list1);
            break;

            case 2:
            printf(" Enter the Element of L2 ");
            scanf("%d",&x);
            list2 = create(list2, x);
            display(list2);
            break;

            case 3:
            list3 = merge(list1,list2);
            display(list3);
            break;

            case 4:
            printf("\nEnter element to be searched: ");
            int s;
            scanf("%d",&s);
            search(list3,s);
            break;

            default:
            printf("Wrong choice.");
        }

    }while(ch < 5);

}

struct node *create(struct node *ptr,int x)
{

    struct node *temp;
    if(ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        if (ptr==NULL)
        {
          printf(" List is FULL");
          exit(0);
        }
        ptr->data = x;
        ptr->link = ptr;

    }
    else
        {
            temp = ptr;
            while(temp ->link != ptr)
            {
                temp = temp ->link;
            }
            temp->link = (struct node *) malloc(sizeof(struct node)); //new
            if (temp->link == NULL)
            {
              printf("Error, List is FULL.");
              exit(0);
            }
            temp =  temp-> link;
            temp->data = x;
            temp -> link = ptr;
        }

    printf("\nNode Inserted");
    return (ptr);
    }




void display(struct node *ptr)
{
    struct node *temp;
    temp = ptr;
    printf("List: ");
    if(ptr == NULL)
    {
        printf("List is empty");
    }
    else
    {
      do
      {
          printf("%d ", temp->data);
          temp = temp->link;

      } while(temp!=ptr);
    }
}

void search(struct node *sptr, int n)
{
    struct node *ptr;
    int i=0;
    ptr = sptr;
    while (ptr->data != n)
    {
      ptr = ptr->link;
      i++;
    }
    if (ptr->data == n)
    {
      printf("%d found at position %d",ptr->data,i+1);
    }
  }

struct node *merge(struct node *a, struct node *b)
    {
      struct node *ptr1=NULL;
      struct node *ptr2=NULL;
      ptr1 = a;
      ptr2 = a;
      while (ptr2->link != a)
      {
        ptr2=ptr2->link;
      }
      ptr2->link = b;
      ptr2 = b;
      while (ptr2->link != b)
      {
        ptr2=ptr2->link;
      }
      ptr2->link = ptr1;

      printf(" Lists Merged ");
      return ptr1;
    }
