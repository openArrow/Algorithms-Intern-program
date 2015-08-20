/*
 *C program to implement Binary search with window
 */
#include <stdio.h>

/*  Function for Binary search  */
void binary_search(int array[], int first, int last, int n)
{
    int i ,middle;
    middle = (first + last) / 2;

    while (first <= last) {
	if (array[middle] < n)
	    first = middle + 1;
	else if (array[middle] == n) {
	    printf("%d found at location %d.\n", n, middle+1);
	    break;
	}
	else
	    last = middle - 1;

	middle = (first + last) / 2;
    }
    if ( first > last )
	printf("Not found! %d is not present in the list.\n", n);
}
/*  End of binary_search()  */

/*  Function to search for the window */
search(int arr[], int size, int data)
{
    int p = (size - 1) / 2, low, high, a1 = 0, a2 = 1, i = 1;
    low = p + a1;
    high = p + a2;
    while(i)
    {
	if(data >= arr[low] && data <= arr[high])
	{
	    binary_search(arr, low, high, data);
	    break;
	}
	else if(data < arr[low])
	{
	    binary_search(arr, 0, low, data);
	    break;
	}
	else
	{
	    a2 = a2 * 2;
	    low = high;
	    high = p + a2;
	}
    }
}
/*  End of search()  */

/*  The main() begins  */
int main()

{
    int a[200], i, j, n, size;
    printf("Enter the size of the list:");
    scanf("%d", &size);
    printf("Enter %d Integers in ascending order\n", size);
    for (i = 0; i < size; i++)
	scanf("%d", &a[i]);
    printf("Enter value to find\n");
    scanf("%d", &n);
    search(a, size, n );
    return 0;
}

