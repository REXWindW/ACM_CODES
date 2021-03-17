#pragma GCC optimize(2)
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxn = 1e6 + 7;
int n,m,t,a[maxn],pos[maxn],L[maxn],R[maxn];
int ans[maxn],cnt[maxn],now;

struct Node
{
    int l,r,id;
}nodes[maxn];

int cmp(Node x,Node y)
{
    return pos[x.l] == pos[y.l] ? x.r < y.r : pos[x.l] < pos[y.l];
}

void init()
{
    t = sqrt(n*1.0);
    for(int i = 1;i <= t;i++)
    {
        L[i] = t * (i - 1) + 1;
        R[i] = t * i;
    }
    if(R[t] < n)
    {
        t++;
        L[t] = R[t - 1] + 1;
        R[t] = n;
    }
    for(int i = 1;i <= t;i++)
    {
        for(int j = L[i];j <= R[i];j++)
        {
            pos[j] = i;
        }
    }
}

void add(int x)
{
    if(cnt[a[x]] == 0)++now;
    ++cnt[a[x]];
}

void del(int x)
{
    --cnt[a[x]];
    if(cnt[a[x]] == 0)--now;
    
}

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)scanf("%d",&a[i]);
    init();
    scanf("%d",&m);
    for(int i = 1;i <= m;i++)
    {
        scanf("%d %d",&nodes[i].l,&nodes[i].r);
        nodes[i].id = i;
    }
    sort(nodes + 1,nodes + 1 + m,cmp);
    int l = 1,r = 0;//l代表1~l-1都没有，r代表r+1~n都没有
    for(int i = 1;i <= m;i++)
    {
        while(l < nodes[i].l)del(l++);
        while(l > nodes[i].l)add(--l);
        while(r < nodes[i].r)add(++r);
        while(r > nodes[i].r)del(r--);
        
        ans[nodes[i].id] = now;
    }
    for(int i = 1;i <= m;i++)printf("%d\n",ans[i]);
    return 0;
}

