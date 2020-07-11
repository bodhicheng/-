//
// Created by ydx on 20-7-11.
// POJ 2777
//

//题目大意：
//长度为L的数组,数组有T种不同的值(颜色),O种不同的操作
//  1.C a b c 操作C将区间[a,b]染成颜色c
//  2.P a b   操作P输出区间[a,b]有多少种不同颜色
//输入：
//第一行：L(1<=L<=100000), T(1<=T<=30), O(1<=O<=100000)
//接下来O行,每行为上述一种操作
//输出：
//所有操作2的值

//样例输入：
//2 2 4
//C 1 1 2
//P 1 2
//C 2 2 2
//P 1 2
//样例输出：
//2
//1

#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,k,m;
int root,cntt;
struct node
{
    int lson,rson;
    int l,r;
    int flag;
    int sum;
    int lazy;
}T[4*maxn];
void pushdown(int x)
{
    T[T[x].lson].lazy=T[x].lazy;
    T[T[x].rson].lazy=T[x].lazy;
    T[T[x].lson].sum=(1<<(T[x].lazy-1));
    T[T[x].rson].sum=(1<<(T[x].lazy-1));
    T[x].lazy=0;
}
void pushup(int x)
{
    T[x].sum=(T[T[x].lson].sum|T[T[x].rson].sum);
}
void build(int &x,int l,int r)
{
    x=cntt++;
    T[x].l=l; T[x].r=r;
    T[x].lazy=0;
    if(l==r)
    {
        T[x].sum=1;
        T[x].flag=1;
        return ;
    }
    T[x].flag=0;
    int mid=(l+r)/2;
    build(T[x].lson,l,mid);
    build(T[x].rson,mid+1,r);
    pushup(x);
}
void update(int x,int l,int r,int value)
{
    if(T[x].l>r||T[x].r<l)
        return ;
    if(T[x].l>=l&&T[x].r<=r)
    {
        T[x].lazy=value;
        T[x].sum=(1<<(value-1));
        return ;
    }
    if(T[x].lazy)
        pushdown(x);
    update(T[x].lson,l,r,value);
    update(T[x].rson,l,r,value);
    pushup(x);
}
int query(int x,int l,int r)
{
    if(T[x].l>r||T[x].r<l)
        return 0;
    if(T[x].l>=l&&T[x].r<=r)
        return T[x].sum;
    if(T[x].lazy)
        pushdown(x);
    int sum=0;
    sum=(sum|query(T[x].lson,l,r));
    sum=(sum|query(T[x].rson,l,r));
    return sum;
}
int cal(int x)
{
    int ans=0;
    while(x)
    {
        if(x&1)
            ans++;
        x>>=1;
    }
    return ans;
}
void print(int x)
{
    if(T[x].flag)
    {
        printf("%d\n",T[x].sum);
        return ;
    }
    print(T[x].lson);
    print(T[x].rson);
}

int main()
{
    while(scanf("%d%d%d",&n,&k,&m)!=EOF)
    {
        cntt=0;
        build(root,1,n);
        //print(root);
        for(int i=1;i<=m;i++)
        {
            char str[5];
            scanf("%s",str);
            if(str[0]=='C')
            {
                int temp1,temp2,temp3;
                scanf("%d%d%d",&temp1,&temp2,&temp3);
                if(temp1>temp2)
                    swap(temp1,temp2);
                update(root,temp1,temp2,temp3);
            }
            else if(str[0]=='P')
            {
                int temp1,temp2;
                scanf("%d%d",&temp1,&temp2);
                if(temp1>temp2)
                    swap(temp1,temp2);
                int ans=query(root,temp1,temp2);
                //printf("%d\n",ans);
                printf("%d\n",cal(ans));
            }
        }
    }
    return 0;
}