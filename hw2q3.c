
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int root(int num)
{
    if (num<1)  return -1;
    int i=1;
    while(i*i<=num)
    {
        if (i*i==num)
            return i;
        i++;
    }

    return -1;
}

 int main()
{
    int n=0;
    printf("Please enter the size of your soduko:\n");
    int n_root = -1;
    while (n_root==-1)
    {
        if (scanf("%d", &n)<1)    return 1;
        n_root = root(n);
    }
    int mat[n][n];
    int arr[n];
    for(int i=0; i<n; i++)
        arr[i] = 0;
    int start_i, end_i, start_j, end_j, i, j;

    printf("Please enter your solution:\n");
    for (i = 0; i < n; i++) {
        for(j=0;j < n;j++){
            if(scanf("%d", &mat[i][j])<1)   return 1;
        }
    }
//check rows
    for(i=0; i < n; i++)
    {
        for(int k=0; k < n; k++)
            arr[k] = 0;
        for(j=0; j < n; j++)
        {
            if(++arr[mat[i][j]-1] > 1)
            {
                printf("Bad solution!\n");
                return 1;
            }
        }
    }
//check columns
    for(i=0; i < n; i++)
    {
        for(int k=0; k < n; k++)
            arr[k] = 0;
        for(j=0; j < n; j++)
        {
            if(++arr[mat[j][i]-1] > 1)
            {
                printf("Bad solution!\n");
                return 1;
            }
        }
    }
    start_i = 0, start_j = 0;
    end_i = n_root, end_j = n_root;
//check squares
    for(int l=0; l < n; l++)
    {
        for(int k=0; k < n; k++)
            arr[k] = 0;
        for(i=start_i; i < end_i; i++)
        {
            for(j=start_j; j < end_j; j++)
            {
                if(++arr[mat[i][j]-1] > 1)
                {
                    printf("Bad solution!\n");
                    return 0;
                }
            }
        }
        if (end_i < n)
        {
            start_i+=n_root;
            end_i+=n_root;
        }
        else
        {
            start_j+=n_root;
            end_j+=n_root;
            start_i = 0;
            end_i = n_root;
        }
    }

    printf("Valid solution!\n");


    return 0;
}


