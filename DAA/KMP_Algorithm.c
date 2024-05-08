#include <stdio.h>
#include <string.h>

int pi[1000];
void print_prefix(int n)
{
    for(int i = 0; i < n; i ++)
        printf("%d ", pi[i]);
        
    printf("\n");

}
void compute_prefix(char p[])
{
    int p_len = strlen(p);
    // printf("%s, %d \n", p, p_len);
    pi[0] = 0;
    int k = 0;
    for(int i = 1; i < p_len; i ++)
    {        
        // print_prefix(p_len);
        // printf("%d, %d\n", k, i);
        // printf("%c, %c \n", p[k], p[i]);
        
        while(k > 0 && p[k] != p[i])
        {
            k = pi[k-1];
            // printf("%c, %c \n", p[k], p[i]);
            // printf("%d %d\n", k, i);

        }
        if(p[k] == p[i])
            k ++;
            
        pi[i] = k;
    }
    
    // print_prefix(p_len);

}

void KMP_Matcher(char t[], char p[])
{
    int t_len = strlen(t);
    int p_len = strlen(p);
    
    printf("%s, %d | %s, %d\n", t, t_len, p, p_len);

    compute_prefix(p);
    
    int q = 0;
    
    for(int i=0; i < t_len; i++)
    {
        while(q > 0 && p[q] != t[i])
            q = pi[q-1];
            
        if (p[q] == t[i])
            q ++;
        
        // printf("%d ", q);
        if (q == p_len)
        {
            printf("\nPattern found at %d.\n", (i-p_len+1));
            q = pi[q-1];
        }
    }
    
}

int main() {
    char text[] = "AABAACAADAABAABA";
    char pattern[] = "AABA";
    // printf("%s %s", text, pattern);
    KMP_Matcher(text, pattern);
    
    return 0;
}
