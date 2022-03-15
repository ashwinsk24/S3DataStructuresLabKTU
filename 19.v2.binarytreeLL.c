#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<string.h>
struct node {
  int data;
  struct node* left;
  struct node* right;
};
struct node* root;
struct node* temp;
void inorderTraversal(struct node* root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("%d ->", root->data);
  inorderTraversal(root->right);
}
void preorderTraversal(struct node* root) {
  if (root == NULL) return;
  printf("%d ->", root->data);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}
void postorderTraversal(struct node* root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->data);
}
void insert(int item){
    struct node *ptr, *parentptr , *nodeptr;
    ptr = (struct node *) malloc(sizeof (struct node));
    if(ptr == NULL){
        printf("can't insert");
    }
    else{
    ptr -> data = item;
    ptr -> left = NULL;
    ptr -> right = NULL;
    if(root == NULL){
        root = ptr;
        root -> left = NULL;
        root -> right = NULL;
    }
    else{
        parentptr = NULL;
        nodeptr = root;
        while(nodeptr != NULL){
            parentptr = nodeptr;
            if(item < nodeptr->data){
                nodeptr = nodeptr -> left;
            }
            else{
                nodeptr = nodeptr -> right;
            }
        }
        if(item < parentptr -> data){
            parentptr -> left = ptr;
        }
        else{
            parentptr -> right = ptr;
        }
    }
    printf("Node Inserted");
    }
}
struct node* insuc(struct node *r)
{
 struct node *q=NULL;
 while(r->left!=NULL)
 {
 q=r; r=r->left;
 }
 if(r->right!=NULL) q->left=r->right;else q->left=NULL;
 return(r);
}
void delete()
      {
      printf("Enter key to delete: ");
      int d;
      scanf("%d",&d);
      struct node *cur=root;
      int f=0;
      struct node *pr=NULL;
      while(cur!=NULL)
      {
	  if(cur->data==d) {f=1;break;}

      if(d<cur->data) {pr=cur; cur=cur->left;}
      else if(d>cur->data){pr=cur; cur=cur->right;}

      }
      if(f==0)  printf("key not found..!!!");
      else
       {
       struct node *t=cur;// node to be deleted...
	//leaf nodes....
         if(t->left==NULL&&t->right==NULL)
          {
            if(pr->left==t) pr->left=NULL;
            if(pr->right==t) pr->right=NULL;
	       }
         else if(t->left==NULL)
             {
             if(pr->left==t) pr->left=t->right;
             if(pr->right==t) pr->right=t->right;
             }

         else if(t->right==NULL)
             {
             if(pr->left==t) pr->left=t->left;
             if(pr->right==t) pr->right=t->left;
             }
        else
          {
         struct node *in=t->right;
          if(in->left==NULL) {t->data=in->data;t->right=in->right;}
          else {in=insuc(t->right);t->data=in->data;}
          }
        }
      }
void main() {
  int n,d,ch; char c;
  do{
      printf("\n1.Insertion \n2.Deletion \n3.Traversals \n4.Exit");
      printf("\n Enter your choice: ");
      scanf("%d",&ch);
      switch(ch){
          case 1:
          do{
            printf(" Enter the item which you want to insert: ");
            scanf("%d",&n);
            insert(n);
            printf("\nDo you want to insert more elements (Y/N): ");
            scanf("%s",&c);
          }while(c == 'Y' || c == 'y');
          break;
          case 2:
          delete();
          break;
          case 3:
          printf("\nInorder traversal: \n");
          inorderTraversal(root);
          printf("\nPreorder traversal \n");
          preorderTraversal(root);
          printf("\nPostorder traversal \n");
          postorderTraversal(root);
          break;
          case 4:
          printf("Exited Successfully.");
          return;
          break;
          default:
              printf("Please Enter valid choice ");
      }
   }while(ch<5);
}
