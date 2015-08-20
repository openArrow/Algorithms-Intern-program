/*
 *C program to print all combination of list of numbers
 */
#include <stdio.h>

/*  Function to generate combination  */
void combinationUtil(int arr[], int data[], int start, int end, int index, int r)
{
    int j, i;
    // Current combination is ready to be printed, print it
    if (index == r) {
        for (j = 0; j < r; j++)
            printf("%d ", data[j]);
        printf("\n");
        return;
    }

    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}
/*  End of combinationutil()  */

/*  Function to print the combination  */ 
void printCombination(int arr[], int n, int r)
{
    int data[r];
    combinationUtil(arr, data, 0, n - 1, 0, r);
}
/*  End of printCombination()  */

/*  The main() begins  */
int main()
{
    int arr[20], r, n, i;
    printf("Enter the number of input : ");
    scanf("%d", &n);
    printf("\nEnter the integers: \n");
    for (  i = 0; i < n; i++)
    {
	scanf("%d", &arr[i]);
    }
    for(r = 1; r <= 5; r++)
	printCombination(arr, n, r);
}
