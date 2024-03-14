#include <stdio.h>
int main ()
{
    int n, purchaseAmount, amountPaid, change;
    // printf ("Enter purchase amount:");
    // scanf ("%d", &purchaseAmount);
    // printf ("Enter amount paid:");
    // scanf ("%d", &amountPaid);
    printf ("Enter change:");
    scanf ("%d", &change);
    printf ("Enter number of types coins available:");
    scanf ("%d", &n);
    // change = purchaseAmount- amountPaid;
    int coin[n];
    int coinChange[n][change+1];
    for (int i = 0; i < n; i++)
	{
        printf ("Enter coin denomination %d:", (i + 1));
        scanf ("%d", &coin[i]);
        coinChange[i][0] = 0;
	}

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(coin[j]>coin[j+1])
            {
                int temp = coin[j];
                coin[j] = coin[j + 1];
                coin[j + 1] = temp;
            }
        }
    }
    // works till here. sorts, takes inputs
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j < change + 1; j++)
        {
            
            
            int oldMinCoins = 0;
            
            if(i > 0) 
            {
                oldMinCoins = coinChange[i-1][j];//0
            }
            
            int newCoins = 0;
            
            // works till here
            if(j % coin[i] == 0)
            {
                newCoins = j/coin[i];
            }
            else if(j > coin[i])
            {
                int amt = j-coin[i];//7-5=2
                if (coinChange[i][amt] != 0)
                {
                    newCoins = coinChange[i][amt] + 1; //1+1
                }
                else
                {
                    newCoins = oldMinCoins;
                }
            }
            else
            {
                newCoins = oldMinCoins;
            }
            
            if(oldMinCoins >= newCoins || oldMinCoins == 0) 
            {
                coinChange[i][j] = newCoins;
            }
            else
            {
                coinChange[i][j] = oldMinCoins;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(i==0)
        {
            printf("\n    :  :      ");

            for(int j = 0; j < change + 1; j++)
            {
                printf("%d     ", j);
            }
        }
        printf("\ncoin: %d:      ", coin[i]);
        for(int j = 0; j < change + 1; j++)
        {
            printf("%d     ", coinChange[i][j]);
        }
    }
	printf("\nMinimum number coins needed for change is: %d\n", coinChange[n-1][change]);
	
	if (coinChange[n-1][change] != 0)
	{
	    int amt = change;//12
	    int i = n-1;//3
	    while(amt>0)
	    {
	        if(coinChange[i][amt] == coinChange[i-1][amt])
	        {
	            i--;
	        }
	        else
	        {
	            printf("%d   ", coin[i]);
	            amt -= coin[i];
	        }
	    }
	}
	return 0;
	
}
