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

void polymultiply(struct node* head1, struct node* head2)
{
  struct node* ptr1 = head1;
  struct node* ptr2 = head2;

  struct node* head3 = NULL;
  if (head1 == NULL || head2 == NULL)
  {
    printf(" No polynomial data \n");
    return;
  }
  while (ptr1 != NULL)
  {
    while (ptr2 != NULL)
    {
      head3 = insert(head3, ptr1->coef * ptr2-> coef, ptr1->expo + ptr2->expo);
      ptr2 = ptr2->link;
    }
    ptr1 = ptr1->link;
    ptr2 = head2;
  }

  struct node* ptr3 = head3;
  struct node* temp = NULL;

  while (ptr3->link != NULL)
  {
    if (ptr3->expo == ptr3->link->expo)
    {
      ptr3->coef = ptr3->coef + ptr3->link->coef;
      temp = ptr3->link;
      ptr3->link = ptr3->link->link;
      free(temp);
    }
    else
    {
      ptr3 = ptr3->link;
    }
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
  polymultiply(head1, head2);

}
