#pragma GCC optimize(2)
#include <cstdio>
#include<iostream>
#include <cstring>
#include <algorithm>
#include<vector>
#include<map>
#include <cmath>
#define ll long long
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int MAXN = 5e6+7;
const int maxn = 5e5+5;
int n,m,mm,t,a[maxn],pos[maxn],L[maxn],R[maxn];
int ans[maxn],cnt[maxn],now;
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
struct Node
{
    int l,r,id;
    Node(int lll=0,int rr=0,int idd=0){l=lll,r=rr,id=idd;}
}nodes[MAXN];

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
int q,k;
vector<int> vec[maxn];//每个颜色在哪些位置出现
vector<int> que[maxn];
int mp[514][514];
int main(){
    cin>>n>>mm>>k>>q;
    m=0;//m记录询问总数
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        vec[a[i]].push_back(i);
    }
    init();
    int x,y;
    rep(k,1,q){
        cin>>x>>y;
        int sizx = vec[x].size();
        int sizy = vec[y].size();
        int ss,tt;
        rep(i,0,sizx-1){
            rep(j,0,sizy-1){
                ss = vec[x][i];
                tt = vec[y][j];
                //cout<<"i"<<i<<"j"<<j<<endl;
                if(ss>tt) swap(ss,tt);
                if(mp[ss][tt]){
                    que[k].push_back(mp[ss][tt]);
                    continue;
                }
                m++;
                nodes[m]=Node(ss,tt,m);
                mp[ss][tt] = m;
                //cout<<"ss"<<ss<<"tt"<<tt<<endl;
                //if(nodes[m].l==0) cout<<"error"<<endl;
                que[k].push_back(m);//推入编号
            }
        }
    }
    /*
    rep(i,1,q){
        cout<<"q"<<i<<"size"<<que[i].size()<<':';
        rep(j,0,que[i].size()-1) cout<<que[i][j]<<' ';
        cout<<endl;
    }
    */
    sort(nodes + 1,nodes + 1 + m,cmp);
    int l = 1,r = 0;//l代表1~l-1都没有，r代表r+1~n都没有
    now = 0;
    for(int i = 1;i <= m;i++)
    {
        while(l < nodes[i].l)del(l++);
        while(l > nodes[i].l)add(--l);
        while(r < nodes[i].r)add(++r);
        while(r > nodes[i].r)del(r--);
        ans[nodes[i].id] = now;
    }
    int res;
    /*
    rep(i,1,m){
        cout<<nodes[i].l<<':'<<nodes[i].r<<endl;
        cout<<"ans"<<nodes[i].id<<'='<<ans[nodes[i].id]<<endl;
    }
    */
    rep(i,1,q){
        res = 0;
        int siz = que[i].size();
        rep(j,0,siz-1){if(ans[que[i][j]]>=k)res++;}
        cout<<res<<endl;
    }
}
/*
10 10 4 5
1 2 3 3 3 4 5 4 6 1
1 2
1 3
1 4
1 5
1 6
*/