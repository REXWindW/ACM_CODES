#include<bits/stdc++.h>
#define IT set<node>::iterator
using namespace std;
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
typedef long long LL;
const int MOD7 = 1e9 + 7;
const int MOD9 = 1e9 + 9;
const int imax_n = 1e5 + 7;
struct node
{
    int l,r;
    mutable LL v;
    node(int L, int R=-1, LL V=0):l(L), r(R), v(V) {}
    bool operator<(const node& o) const
    {
        return l < o.l;
    }
};
LL pown(LL a, LL b, LL mod)
{
    LL res = 1;
    LL ans = a % mod;
    while (b)
    {
        if (b&1) 
            res = res * ans % mod;
        ans = ans * ans % mod;
        b>>=1;
    }
    return res;
}
set<node> s;
IT split(int pos)
{
    IT it = s.lower_bound(node(pos));
    if (it != s.end() && it->l == pos) 
        return it;
    --it;
    int L = it->l, R = it->r;
    LL V = it->v;
    s.erase(it);
    s.insert(node(L, pos-1, V));
    return s.insert(node(pos, R, V)).first;
}
void add(int l, int r, LL val)
{
    IT itr = split(r+1),itl = split(l);
    for (; itl != itr; ++itl) 
        itl->v += val;
}
void assign_val(int l, int r, LL val)//区间修改数值
{
    IT itr = split(r+1),itl = split(l);
    s.erase(itl, itr);
    s.insert(node(l, r, val));
}
LL ranks(int l, int r, int k)
{
    vector<pair<LL, int> > vp;
    IT itr = split(r+1),itl = split(l);
    vp.clear();
    for (; itl != itr; ++itl)
        vp.push_back(pair<LL,int>(itl->v, itl->r - itl->l + 1));
    sort(vp.begin(), vp.end());
    for (vector<pair<LL,int> >::iterator it=vp.begin();it!=vp.end();++it)
    {
        k -= it->second;
        if (k <= 0) 
            return it->first;
    }
}
LL sum(int l, int r, int mod)
{
    IT itr = split(r+1),itl = split(l);
    LL res = 0;
    for (; itl != itr; ++itl)
        res = (res + (LL)(itl->r - itl->l + 1) * itl->v) % mod;
    return res;
}
LL sum_mi(int l, int r, int ex, int mod)
{
    IT itr = split(r+1),itl = split(l);
    LL res = 0;
    for (; itl != itr; ++itl)
        res = (res + (LL)(itl->r - itl->l + 1) * pown(LL(ex), itl->v, LL(mod))) % mod;
    return res;
}
void add_yh(int l, int r, LL val)
{
    IT itr = split(r+1),itl = split(l);
    for (; itl != itr; ++itl) 
        itl->v ^= val;
}
int n, m;
LL a[imax_n];
int main()
{
    cin>>n>>m;
    for (int i=1; i<=n; ++i)
    {
        cin>>a[i];
        s.insert(node(i,i,a[i]));
    }
    s.insert(node(n+1, n+1, 0));
    int lines = 0;
    for (int i =1; i <= m; ++i)
    {
        /*
        int op = int(rd() % 4) + 1;
        int l = int(rd() % n) + 1;
        int r = int(rd() % n) + 1;
        */
        int op,l,r;
        cin>>op;
        cin>>l>>r;
        if(l>r) swap(l,r);
        int x,y;
        if(op==7){
            for(int i=1;i<=n;i++){
                cout<<sum(i,i,MOD7)<<' ';
            }
            cout<<endl;
        }
        if (op == 5){//中位数!!
            if((r-l+1)%2){
                x=(r-l+1 +1)/2;//中位数
                cout<<ranks(l,r,x)<<endl;
            }
            else{
                x=(r-l+1)/2;y=x+1;
                int hcc = ranks(l,r,x)+ranks(l,r,y);
                cout<<hcc/2<<endl;
            }
        }
        else if(op == 4){//区间和
            cout<<sum(l,r,MOD7)<<endl;
        }
        else if(op==6){//幂次和
            cin>>x;
            cout<<sum_mi(l,r,LL(x),MOD7)<<endl;
        }
        else if(op==3){//区间改
            cin>>x;
            assign_val(l,r,LL(x));
        }
        else if(op==2){//区间异或和，不用mod
            cin>>x;
            add_yh(l,r,LL(x));
        }
        else if(op==1){//区间加
            cin>>x;
            add(l,r,LL(x));
        }
    }
    return 0;
}