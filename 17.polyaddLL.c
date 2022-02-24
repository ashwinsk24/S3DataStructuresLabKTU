#include<stdio.h>
#include<stdlib.h>

struct node
{
  int coef;
  int expo;
  struct node* link;
};

struct node* insert(struct node* head, int cof, int ex)
{
  struct node* temp;
  struct node* nptr = malloc(sizeof(struct node));
  nptr->coef = cof;
  nptr->expo = ex;
  nptr->link = NULL;

  if (head == NULL || ex > head->expo)
  {
    nptr->link = head;
    head = nptr;
  }
  else
  {
    temp = head;
    while (temp->link != NULL && temp->link->expo >= ex)
    {
      temp = temp->link;
    }
    nptr->link = temp->link;
    temp->link = nptr;
  }
  return head;

}

struct node* create(struct node* head)
{
  int n,i;
  int coef;
  int expo;

  printf(" Enter the no. of terms: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++)
  {
    printf(" Enter the coefficients for term %d:",i+1);
    scanf(" %d",&coef);

    printf(" Enter the exponent for term %d:",i+1);
    scanf(" %d",&expo);

    head = insert(head, coef, expo);
  }
  return head;
}

void print(struct node* head)
{
  if (head == NULL)
  {
    printf(" No polynomial data.");
  }
  else
  {
    struct node* temp = head;
    while (temp != NULL)
    {
      printf(" %d ^ %d", temp->coef, temp->expo);
      temp = temp->link;
      if (temp != NULL )
      {
        printf(" + ");
      }
      else
      printf("\n");
    }
  }
}

void polyadd(struct node* head1, struct node* head2)
{
  struct node* ptr1 = head1;
  struct node* ptr2 = head2;

  struct node* head3 = NULL;
  while (ptr1!=NULL && ptr2!= NULL)
  {
    if (ptr1->expo == ptr2->expo)
    {
      head3 = insert(head3, ptr1->coef+ptr2->coef, ptr1->expo);
      ptr1 = ptr1->link;
      ptr2 = ptr2->link;
    }
    else if(ptr1-> expo > ptr2-> expo)
    {
      head3 = insert(head3, ptr1->coef, ptr1->expo);
      ptr1 = ptr1->link;
    }
    else if (ptr2-> expo > ptr1-> expo)
    {
      head3 = insert(head3, ptr2->coef, ptr2->expo);
      ptr2 = ptr2->link;

    }
  }

  while (ptr1!=NULL)
  {
    head3 = insert(head3, ptr1->coef, ptr1->expo);
    ptr1 = ptr1->link;
  }

  while (ptr2!=NULL)
  {
    head3 = insert(head3, ptr2->coef, ptr2->expo);
    ptr2 = ptr2->link;
  }
  printf("\n Resultant Sum of polynomials is: ");
  print(head3);
}


void main()
{
  struct node* head1 = NULL;
  struct node* head2 = NULL;
  printf(" Enter the first polynomial \n ");
  head1 = create(head1);
  printf(" Enter the second polynomial \n ");
  head2 = create(head2);
  polyadd(head1, head2);

}
