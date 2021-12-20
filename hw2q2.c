/*-------------------------------------------------------------------------
  Include files:
--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 1000000000
#define DEFAULT_C 3

void printMessage()
{
    printf("Please enter three integers:\n");
}

int average(int a, int b, int c)
{
    return (a+b+c)/3;
}

int min(int a, int b)
{
    if (a<b)
        return a;
    return b;
}

int absolute(int x)
{
    if (x<0)
        return -x;
    return x;
}

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

long long power(int b, int e)
{
    if (e < 0 || b < 0)  return -1;
    long long pow = 1;
    for(int i=0; i<e; i++)
    {
        pow*=b;
        if (pow > MAX_VAL)
            return -1;
    }
    return pow;
}

long long f(int x, int c)
{
    if (x < 0 || c < 0)    return -1;
    long long sum = 0;
    int res=0;
    for(int i=0; i<=c; i++)
    {
        res = power(x,i);
        if (sum > MAX_VAL || res==-1)
            return -1;
        else
            sum+=res;
    }
    return sum;
}


int main()
{
  int x,y,z;
  printMessage();
  if (scanf("%d %d %d", &x,&y,&z) < 3)    return 1;
  int avr = average(x,y,z);
  int m = absolute(min(min(x,y),z));
  int c = root(m);
  if (c==-1)
    c = DEFAULT_C;
  printf("%d %d %lld %lld\n",avr, root(m), power(avr, m), f(m, c));

  return 0;
}
