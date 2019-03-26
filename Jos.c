#include <stdio.h>
#include <stdlib.h>

typedef struct Jos
{
    int  password;
    int  num;
    struct  Jos *next;
} Jos, *Pjos;

Pjos init()
{
    Pjos L=(Pjos)malloc(sizeof(Jos));
    L->next=NULL;

    return L;
}

int password[] = {6,1,4,2,6};

void creat(int n,Pjos L)
{
    int i;
    Pjos head,tail,p;
    tail=L;

    for(i=0;i<n;i++)
    {
        p=init();
        tail->next=p;
        p->password = password[i];
        p->num=i+1;
        p->next=NULL;
        tail=p;
    }

    tail->next=L->next;
}
int main()
{
    Pjos  L;
    L=init();

    int n,m,i;
    int a;

    n = 5;
    m = 13;

    creat(n,L);
    Pjos p=L->next, q;

    do
    {
        for(i=0;i<m-2;i++)
        {
            p=p->next;
        }

        q=p->next;
        m=q->password;

        printf("%d  out\n",q->num);

        p->next=q->next;

        if(m==1){}
        else{p=q->next;}

        free(q);

    }while(p->next!=p);

    printf("%d  out",p->num);
}
