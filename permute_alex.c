/*
 *C program to implement Alexander Bogomolyn's unordered permutation algorithm to find all permutations of numbers from 1 to n
 */
#include <stdio.h>

/*  Function to print all the permutations  */
void print(const int *v, const int size)
{
    int i;
    if (v != 0) {
	for (i = 0; i < size; i++) {
	    printf("%4d", v[i] );
	}
	printf("\n");
    }
} 
/*  End of print()  */

/* Function to generate permutations  */
void visit(int *Value, int N, int k)
{
    static level = -1;
    int i;
    level = level+1; Value[k] = level;

    if (level == N)
	print(Value, N);
    else
	for (i = 0; i < N; i++)
	    if (Value[i] == 0)
		visit(Value, N, i);

    level = level-1; Value[k] = 0;
}
/*  End of visit()  */

/*  The main() begins  */
int main()
{
    int Value[20], i, N;
    printf("Enter the value of N: ");
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
	Value[i] = 0;
    }
    visit(Value, N, 0);
}
