/*
 *Program to find element in a linked list and element is moved to the front as soon as it is found.
 *This techinque is based on the locality of reference.
 */
#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
	int data;
	struct Node *next;
}node;

/* Function to insert node in link list */
void insert(node **head, int data){
	node **ptr2 = head;
	if(*ptr2 == NULL){
		(*ptr2) = (node*)malloc(sizeof(node));
		(*ptr2)->data = data;
		(*ptr2)->next = NULL;
	}
	else{
		while(*ptr2 != NULL)
			ptr2 = &(*ptr2)->next;
		(*ptr2) = (node*)malloc(sizeof(node));
		(*ptr2)->data = data;
		(*ptr2)->next = NULL;
		
	}
}
/* End of insert() */

/* Function to search a node and insert it at the begining */
int find(node *p, int key)
{

	node *pointer;
	pointer = p;
	while(pointer != NULL)
	{
		if(pointer->data == key) 
		{
			printf("Element  found\n");
			return(key);


		}
		pointer = pointer->next;
	}
	printf("Element not found\n");


}
/* End of find() */

/* Function to insert node at begining */
void insertStart(node **pointer, int data)
{

	node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->next = *pointer;
	*pointer = temp;

}
/* End of insertStart() */

/* Function to delete a node */
void delete(node **head, int data){
	node **ptr2;
	for (ptr2= head; *ptr2 != NULL; ptr2 = &(*ptr2)->next)
	{
		if((*ptr2)->data == data)
		{
			*ptr2 = (*ptr2)->next;
			break;
		}
	}
}
/* End of delete() */

/* Function to print elements of the list */ 
void print (node *head) {

	node * ptr =head;
	while (ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}
/* End of print() */

/* The main() begins */ 
int main()
{

	int query, data, t;
	char ch = 'y';
	node *start = NULL, *temp;
	printf("1. Insert\n");
	printf("2. Print\n");
	printf("3. Find\n");
	printf("4. Exit\n");


	while(1)
	{	printf("Enter choice:");
		scanf("%d", &query);
		switch(query)
		{
			case 1: printf("Enter Data:");
				scanf("%d", &data);
				insert(&start, data);
				break;
			case 2: printf("The list is ");
				print(start);
				printf("\n");
				break;
			case 3: printf("Enter element to be searched:"); 
				scanf("%d",&data);
				t = find(start, data);
				if(t != -1)
				{
					delete(&start, t);
					insertStart(&start, t);
				}
				break;
			case 4: printf("Exit\n");
				exit(0);
				break;
			default: printf("Wrong choice");
		}
	}
	return 0;
}
