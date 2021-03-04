#include <bits/stdc++.h>
using namespace std;
 
const int N = 1000005;
 
set<int> g[N];
int n;
int siz[N];
int fib[N],fid[N],fa[N];
vector<int> vec;
 
void dfs(int p,int from)
{
    siz[p]=1;
    vec.push_back(p);
    for(int q:g[p]) if(q!=from)
    {
        dfs(q,p);
        fa[q]=p;
        siz[p]+=siz[q];
    }
}
 
bool check(int p,int size)
{
    if(size<=3) return true;
    vec.clear();
    dfs(p,0);
    int size_id=fid[size];
    int tar_size=fib[size_id-1];
    int res_p=0,res_q=0,psize=0;
    for(int i:vec)
    {
        if(siz[i]==tar_size || size-siz[i]==tar_size)
        {
            res_p=i;
            res_q=fa[i];
            psize=siz[p];
            break;
        }
    }
    if(res_p)
    {
        g[res_p].erase(res_q);
        g[res_q].erase(res_p);
        return check(res_p,psize) && check(res_q,size-psize);
    }
    else 
    {
        return false;
    }
}
 
signed main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    fib[0]=fib[1]=1;
    for(int i=2;i<=30;i++) fib[i]=fib[i-1]+fib[i-2];
    for(int i=1;i<=30;i++) fid[fib[i]]=i;
    for (int i = 1; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        g[t1].insert(t2);
        g[t2].insert(t1);
    }
    if (check(1,n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}