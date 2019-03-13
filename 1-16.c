#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[3];
    int i,j,tem;
    for(i=0;i<3;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<2;i++)
    {
        for(j=i+1;j<3;j++)
        {
            if(a[j]>a[i])
            {
                tem=a[i];
                a[i]=a[j];
                a[j]=tem;
            }
        }
    }
    for(i=0;i<3;i++)
    {
        printf("%-3d",a[i]);
    }
}
