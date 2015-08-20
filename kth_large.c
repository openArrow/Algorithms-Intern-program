#include <stdio.h>
#include <assert.h>
int partition(int* a, int low, int high)
{
    /*Start index for scanning the array*/
    int left = low;
    /*Select middle element of the array as pivot*/
    int pivotIdx = low + (high - low)/2;
    /*Swap pivot with right most element of the array*/
    int pivot = a[pivotIdx];
    a[pivotIdx] = a[high];
    a[high] = pivot;
    pivotIdx = high;
    /*Pivot will be placed at this index such that all elements
    to right of it are greater than pivot and all elements to
    the left of it are smaller than pivot*/
    int partitionIdx = low;
    while (left < high)
    {
        /*Initially our partition index is set to leftmost element
        index in the input array. We keep traversing towards right
        of the input array and if we find an element lesser than
        pivot, we swap it with element at partiotion index and 
        increment partition index else just keep moving right*/
        if (a[left] < pivot) 
        {
            int tmp = a[left];
            a[left] = a[partitionIdx];
            a[partitionIdx] = tmp;
            ++partitionIdx;
        }
        ++left;
    }
    /*Place the pivot value at the partition index*/
    a[pivotIdx] = a[partitionIdx];
    a[partitionIdx] = pivot;
    return partitionIdx;
}

/*K is the kth largest element to find. Initial call
to this function should be called with 0 and size-1 for
low and high respectively.*/

int quickSelect(int* a, int low, int high, int k)
{
    assert(a);
    assert(k <= high+1);
    if (low == high)
        return a[low];
    int pivotIdx = partition(a, low, high);
    int sizeOfLeftSubArray = pivotIdx - low + 1;
    /*If'pivotIdx' is greater than 'k', keep looking towards
    left part*/
    if (sizeOfLeftSubArray > k)
    {
        return quickSelect(a, low, pivotIdx-1, k);
    }
    /*If'pivotIdx' is less than 'k', keep looking towards
    right part*/
    else if (sizeOfLeftSubArray < k)
    {
        return quickSelect(a, pivotIdx+1, high, k-sizeOfLeftSubArray);
    }
    /*We just found our kth index, return it*/
    else
    {
	printf("%d ",a[pivotIdx]);
        return a[pivotIdx];
    }
}
int main()
{
int arr[20], i, n, k, pos;
printf("Enter the size of the array: ");
scanf("%d", &n);
printf("Enter the numbers: ");
for (i = 0; i < n; i++)
scanf("%d", &arr[i]);
printf("Enter the value of k: ");
scanf("%d", &k);
pos=quickSelect(arr, 0, n - 1, k );
printf("The kth largest element is %d\n", pos);
return 0;
}

