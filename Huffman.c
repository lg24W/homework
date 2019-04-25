#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef char ** HfmCode;
typedef struct HfmTree
{
    char ch;
    int weight;
    int parents;
    int lchild;
    int rchild;
}HfmTree,*pHfmTree;
typedef struct list
{
    char ch;
    int weight;
}list,*plist;
pHfmTree InitHfmTree(pHfmTree Ht,plist c,int n)
{
    Ht=(pHfmTree)malloc((2*n)*sizeof(HfmTree));
    int i,j,k,m,flag=0;
    for(i=0;i<n;i++)
    {
        Ht[i].ch=c[i].ch;
        Ht[i].weight=c[i].weight;
        Ht[i].parents=0;
        Ht[i].lchild=0;
        Ht[i].rchild=0;
    }
    for(i=n;i<2*n-1;i++)
    {
        Ht[i].ch='&';
        Ht[i].weight=0;
        Ht[i].parents=0;
        Ht[i].lchild=0;
        Ht[i].rchild=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+i;j++)
        {
            if(Ht[j].parents==0)
            {
                k=j;
                flag=1;
                break;
            }
        }
        for(j=0;j<n+i;j++)
        {
            if(Ht[j].parents==0)
            {
               if(Ht[j].weight<=Ht[k].weight)
               {
                   k=j;
               }
            }
        }
        Ht[k].parents=n+i;
        for(j=0;j<n+i;j++)
        {
            if(Ht[j].parents==0)
            {
                m=j;
                flag=1;
                break;
            }
        }
        for(j=0;j<n+i;j++)
        {
            if(Ht[j].parents==0)
            {
               if(Ht[j].weight<=Ht[m].weight)
               {
                   m=j;
               }
            }
        }
        Ht[m].parents=n+i;
        Ht[n+i].lchild=k;
        Ht[n+i].rchild=m;
        Ht[n+i].weight=Ht[k].weight+Ht[m].weight;
    }
    return Ht;
}
HfmCode initHfmCode(pHfmTree Ht,int n,HfmCode Hc)
{

    Hc=(HfmCode)malloc(n*sizeof(char*));
    char* tem=(char*)malloc((n+1)*sizeof(char));
    int start,i,j,f;
    tem[n]='\0';
    for(i=0;i<n;i++)
    {
        start=n-1;
        for(f=i,j=Ht[i].parents;j!=0;f=j,j=Ht[j].parents)
        {
            if(Ht[j].lchild==f)
            {
                tem[start]='0';
                start--;
            }
            else
            {
                tem[start]='1';
                start--;
            }
        }
        tem[start--]=Ht[i].ch;
        Hc[i]=(char*)malloc((n-start)*sizeof(char));
        strcpy(Hc[i],tem+start+1);
        puts(Hc[i]);
    }
    free(tem);
    return Hc;
}
char* Encoding(char* ToBeTran,HfmCode Hc,char* code,int n)
{
    int i,j,length;
    length=strlen(ToBeTran);
    code=(char*)malloc(n*length*sizeof(char));
    for(i=0;ToBeTran[i]!='\0';i++)
    {
        for(j=0;j<n;j++)
        {
            if(Hc[j][0]==ToBeTran[i])
            {
                strcat(code,Hc[j]+1);
                break;
            }
        }
    }
    return code;
}
char* Decoding(char* code,pHfmTree Ht,int n,char* ToBeTran,int length)
{
    int i,j,k,m;
    m=0;
    j=2*n-1;
    char ch;
    ToBeTran=(char*)malloc(length*sizeof(char));
    for(i=0;code[i]!='\0';i++)
    {
        if(code[i]=='0')
        {
            k=j;
            j=Ht[j].lchild;
        }
        else
        {
            k=j;
            j=Ht[j].rchild;
        }
        if(Ht[k].lchild==0&&Ht[k].rchild==0)
        {
            ch=Ht[k].ch;
            ToBeTran[m]=ch;
            m++;
            j=2*n-1;
            i--;
        }
    }
    return ToBeTran;
}
int main()
{
    pHfmTree Ht;
    HfmCode Hc;
    char* code;
    char* BeTran;
    char *ToBeTran="THIS PROGRAM IS MY FAVORITE";
    int n=27;
    list c[27]={{' ',186},{'A',64},{'B',13},{'C',22},{'D',32},{'E',103},{'F',21},{'G',15},{'H',47},
    {'I',57},{'J',1},{'K',5},{'L',32},{'M',20},{'N',57},{'O',63},{'P',15},{'Q',1},{'R',48},{'S',51},
    {'T',80},{'U',23},{'V',8},{'W',18},{'X',1},{'Y',16},{'Z',1}};
    Ht=InitHfmTree(Ht,c,n);
    Hc=initHfmCode(Ht,n,Hc);
    code=Encoding(ToBeTran,Hc,code,n);
    puts(code);
    BeTran=Decoding(code,Ht,n,BeTran,strlen(ToBeTran));
    puts(BeTran);
    puts(ToBeTran);
}

