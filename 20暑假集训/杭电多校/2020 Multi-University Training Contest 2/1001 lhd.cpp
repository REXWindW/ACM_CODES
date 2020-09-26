/*
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
*/
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7FFFFFFF;
typedef long long ll;
typedef double db;
typedef long double ld;
template<class T>inline void MAX(T &x,T y){if(y>x)x=y;}
template<class T>inline void MIN(T &x,T y){if(y<x)x=y;}
template<class T>inline void rd(T &x){
    x=0;char o,f=1;
    while(o=getchar(),o<48)if(o==45)f=-f;
    do x=(x<<3)+(x<<1)+(o^48);
    while(o=getchar(),o>47);
    x*=f;
}
#define int long long
#define rep(i, a, n) for (register int i = a; i <= n; ++i)
#define per(i, a, n) for (register int i = n; i >= a; --i)
const ll mod = (0 ? 1000000007 : 998244353);
const ll mod2 = 999998639;
const double eps = 1e-7;
const ll llinf = 4223372036854775807;
int date[110000];
vector<int> mp[110000];
pair<int,int> pnt[110000];
int book[110000];
int find(int x){
    if(date[x]==x)
        return x;
    return date[x] = find(date[x]);
}
void merge(int a,int b){
    int l=find(a);
    int r=find(b);
    date[l] = r;
}
void work()
{
    int n, m;
    rd(n), rd(m);
    for (int i = 1; i <= n;i++){
        book[i] = 0;
        date[i] = i;
        mp[i].clear();
        rd(pnt[i].first);
        pnt[i].second = i;
    }
    int u, v;
    for (int i = 0;i<m;i++){
        rd(u), rd(v);
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    sort(pnt+1,pnt+n+1,greater<pair<int,int>>());
    int ans = pnt[1].first;
    book[pnt[1].second] = 1;
    for (int i = 2; i <= n;i++){
        set<int> tt;
        for (int j = 0; j < mp[pnt[i].second].size();j++){
            if(book[mp[pnt[i].second][j]])
            tt.insert(find(mp[pnt[i].second][j]));
        }
        ans -= ((ll)tt.size() - 1) * pnt[i].first;
        for(auto j=tt.begin();j!=tt.end();j++){
            merge(pnt[i].second, *j);
        }
        book[pnt[i].second] = 1;
    }
    printf("%lld\n", ans);
}
signed main()
{
#ifndef ONLINE_JUDGE
   freopen("1001.in","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    rd(t);
    while (t--)
    {
        work();
    }
    return 0;
}
