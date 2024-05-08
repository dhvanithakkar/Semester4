#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define N 4

void printSolution(int placed[]);

bool isSafe(int q_no, int col, int placed[])
{
	for (int i = 0; i < q_no; i++)
		if (placed[i] == col || abs(placed[i] - col) == abs(q_no - i))
			return false;
	return true;
}

void nQueensUtil(int placed[], int q_no)
{
	for (int col = 0; col < N; col++) 
	{
		if (isSafe(q_no, col, placed)) 
		{
			placed[q_no] = col;

			if(q_no == N-1)
			    printSolution(placed);
			else
			{
			    nQueensUtil(placed, q_no + 1);
			}
		}
	}
}

int main()
{
	int placed[N];
	for (int i = 0; i < N; i++)
		placed[i] = -1;
	
	nQueensUtil(placed, 0);

	return 0;
}

/* A utility function to print solution */
void printSolution(int placed[])
{
	printf("Solution Exists:"
		" Following are the assigned columns \n");
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(placed[i] == j)
				printf("x");
			else
				printf("o");
			printf(" | ");
		}
		printf("\n");
	}
}
