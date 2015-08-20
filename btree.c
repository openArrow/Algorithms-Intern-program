/*
 *C program to Implement external sorting using Btree using inorder traversal
 */
#include <stdio.h>
#include <stdlib.h>

struct btreenode
{
  struct btreenode *leftchild;
  int data;
  struct btreenode *rightchild;
};

void insert(struct btreenode**, int);
void inorder(struct btreenode*);

/*  The main() begins  */
main()
{
  struct btreenode *bt;
  int arr[100], size;
  int i;
  bt = NULL;
  printf("Enter the Number of elements: ");
  scanf("%d", &size);
  for(i = 0; i < size; i++)
    scanf("%d", &arr[i]);
  printf("Binary tree sort.\n");
  for (i = 0; i <= 9; i++)
    insert(&bt, arr[i]);

  printf("\nIn-order traversal of binary tree:\n");
  inorder(bt);
  printf("\n");
  return 0;
}

/*  Function to insert number into a Btree  */
void insert(struct btreenode **sr, int num)
{
  if(*sr == NULL) {
    *sr = malloc (sizeof(struct btreenode));

    (*sr)->leftchild = NULL;
    (*sr)->data = num;
    (*sr)->rightchild = NULL;
  }
  else {
    if(num < (*sr)->data)
      insert(&((*sr)->leftchild), num);
    else
      insert(&((*sr)->rightchild), num);
  }
}
/*  End of inert()  */

/*  Function for Inorder traversal  */
void inorder(struct btreenode *sr)
{
  if(sr != NULL) {
    inorder(sr->leftchild);
    printf("%d ", sr->data);
    inorder(sr->rightchild);
  }
}
/*  End of inorder()  */
