
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n;
    char c;

    //Get input
    printf("Please enter the matrix size:\n");
    if (scanf("%d",&n) < 1)
    {
        printf("Invalid input.\n");
        return 1;
    }
    int A[n][n];
    int B[n][n];
    int C[n][n];
    printf("Please enter the first matrix:\n");
    for(i=0; i < n; i++)
    {
        for(j=0; j < n; j++)
            if(scanf("%d", &A[i][j])<1)
            {
                printf("Invalid input.\n");
                return 1;
            }
    }
    printf("Please enter the second matrix:\n");
    for(i=0; i < n; i++)
    {
        for(j=0; j < n; j++)
            if(scanf("%d", &B[i][j])<1)
            {
                printf("Invalid input.\n");
                return 1;
            }
    }
    printf("Please enter the required operation:\n");
    scanf("   %c", &c);

    //Do calculations
    switch (c){
    case '+':
        for (i=0; i<n; i++)
            for(j=0; j<n; j++)
                C[i][j] = A[i][j]+B[i][j];
        break;
    case '*':
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
            {
                C[i][j] = 0;
                for(int k=0; k<n; k++)
                    C[i][j] += A[i][k]*B[k][j];
            }
        break;
    default: printf("Invalid input.\n"); return 1;
    }

    //Print output
    for(i=0; i<n; i++)
    {
         for(j=0; j < n; j++)
         {
             printf("%d", C[i][j]);
             if (j<n-1)
                printf(" ");
         }

        printf("\n");
    }

  return 0;
}
