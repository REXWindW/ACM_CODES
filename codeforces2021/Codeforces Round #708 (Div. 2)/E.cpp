#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 114514*2;
vector<int> prim;
bool ntprim[MAXN];
int cnt;
vector<int> fj;
map<vector<int>,int> mp;
int n,k;
int a[MAXN];
void init(){//筛出质因数
    int sqr = sqrt(1e7); 
    rep(i,2,sqr){
        if(ntprim[i]) continue;
        for(int j=i;j<=sqr;j+=i){
            ntprim[j] = 1;
        }
        prim.push_back(i);
    }
    cnt = prim.size();
}
inline bool find(int x){
    //int sqr = sqrt(x);
    fj.clear();
    int tmp = 0;
    rep(i,0,cnt-1){
        //if(prim[i]>sqr) break;
        if(x%prim[i]==0){
            tmp = 0;
            while(x%prim[i]==0) x/=prim[i],tmp++;
            if(tmp%2) fj.push_back(i);//推入这个因子
        }
    }
    if(x!=1) fj.push_back(x);
    if(mp[fj]) return 1;
    return 0;
}
inline void insert(int x){
    //int sqr = sqrt(x);
    fj.clear();
    int tmp = 0;
    rep(i,0,cnt-1){
        //if(prim[i]>sqr) break;
        if(x%prim[i]==0){
            tmp = 0;
            while(x%prim[i]==0) x/=prim[i],tmp++;
            if(tmp%2) fj.push_back(i);//推入这个因子
        }
    }
    if(x!=1) fj.push_back(x);
    mp[fj] = 1;
}
void solve(){
    mp.clear();
    ll res = 1;
    cin>>n>>k;
    rep(i,1,n) cin>>a[i];
    rep(i,1,n){
        if(find(a[i])){
            //cout<<"chongtu in "<<i<<endl;
            res++;
            mp.clear();
        }
        insert(a[i]);
    }
    cout<<res<<endl;
}

int main(){
    init();
    int z;
    cin>>z;
    while(z--) solve();
}