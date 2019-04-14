#include<stdio.h>
#include<stdlib.h>
#define Max_Size  10
#define Add_size  10
typedef  int Elemtype;
typedef  struct stack
{
    Elemtype *top;
    Elemtype *base;
    int size;
}stack,*pstack;
stack init()
{
    stack S;
    S.base=(Elemtype*)malloc(Max_Size*sizeof(Elemtype));
    if(!S.base)exit(0);
    S.top=S.base;
    S.size=Max_Size;
    return S;
}
void push(Elemtype e,pstack S)
{
    if(S->top-S->base>=S->size)
    {
        S->base=(Elemtype*)realloc(S->base,(Add_size+Max_Size)*sizeof(Elemtype));
        S->top=S->base+Max_Size;
        S->size=S->size+Add_size;
    }
     *(S->top)=e;
     S->top++;
}
void pop(pstack S,Elemtype *e)
{
    if(S->base==S->top)exit(0);
    S->top--;
    *e=*(S->top);
}
void print(pstack S)
{
    while(S->top!=S->base)
    {
        printf("%d\t",*(S->top-1));
        S->top--;
    }
    printf("\n");
}
int Empsta(pstack S)
{
    if(S->base==S->top)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void dispatch(pstack S,int cur,Elemtype pos,Elemtype len,Elemtype *a)
{
    Elemtype e,m;

   if(pos<len)
   {
       push(pos+1,S);
       dispatch(S,cur,pos+1,len,a);
       pop(S,&m);
   }

    if(Empsta(S)!=0)
    {
        pop(S,&e);
        a[cur]=e;
        cur++;
        dispatch(S,cur,pos,len,a);
        push(e,S);
    }

    if(Empsta(S)==0&&pos==len)
    {
        for(int i=0;i<len;i++)
        {
            printf("%d\t",a[i]);
        }
        printf("\n");
    }
}
int main()
{
    Elemtype len;
    Elemtype a[100];
    stack S,L;

    S=init(),L=init();
    printf("Please input the number:");
    scanf("%d",&len);

    dispatch(&S,0,0,len,&a);
}
