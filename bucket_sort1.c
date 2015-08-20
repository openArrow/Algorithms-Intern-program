#include<stdio.h>
void bucket_sort(int sarray[], int array_size) {
	int x,digit,y,i,dig,idx;
    const int max = array_size;
    // use bucket[x][max] to hold the current count
    int bucket[10][max+1];

    // init bucket counters
    for(x=0;x<10;x++) bucket[x][max] = 0;
    // main loop for each digit position
    for(digit = 1; digit <= 1000000000; digit *= 10) {
        // array to bucket
        for(i = 0; i < max; i++) {
            // get the digit 0-9
            dig = (sarray[i] / digit) % 10;
            // add to bucket and increment count
            bucket[dig][bucket[dig][max]++] = sarray[i];
        }
        // bucket to array
        idx = 0;
        for(x = 0; x < 10; x++) {
            for(y = 0; y < bucket[x][max]; y++) {
                sarray[idx++] = bucket[x][y];
            }
            // reset the internal bucket counters
            bucket[x][max] = 0;
        }
    }
}
int main()
{
 int array[100];  
 int num;  
 int i; 
 printf("Enter How many Numbers : ");   
 scanf("%d",&num);   
 printf("Enter the %d elements to be sorted:\n",num); 
 for(i = 0; i < num; i++ )
 {  
  scanf("%d",&array[i]); 
 }  
 printf("\nThe array of elements before sorting : \n");
 for (i = 0;i < num;i++)
 {   
  printf("%d ", array[i]);  
 }   
 printf("\nThe array of elements after sorting : \n"); 
 bucket_sort(array, num); 
 for (i = 0;i < num;i++)
 {    
  printf("%d ", array[i]); 
 }  
 printf("\n");     
 return 0;
} 
