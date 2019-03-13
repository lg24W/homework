#include <stdio.h>
#include <stdlib.h>
float add(int n,float x,float a[]);
int main()
{
    float a[100];
    int i,j,n;
    float x;
    float pn;
    scanf("%d%f",&n,&x);
    for(i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
    }
    pn=add(n,x,a);
    printf("pn=%lf",pn);
}
float add(int n,float x,float a[])
{
    int i;
    float pn=a[n-1];
    for(i=n-2;i>=0;i--)
    {
        pn=a[i]+pn*x;
    }
    return pn;
}
