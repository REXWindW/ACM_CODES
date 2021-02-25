#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
const int MAXN = 114514;
ll c[MAXN];
int n,m;
bool fin=0;
ll res;
void deal(ll x){
    int px = 1;
    bool flag = 1;
    ll nbef,bef = c[1];//记录原先的数值
    c[1]+=x;
    while(flag&&px<n){
        flag=0;
        if(c[px]>px){
            flag=1;
            nbef=c[px+1];
            c[px+1]+=c[px]/(px+1);//增加
            c[px]%=(px+1);
            res+=c[px]-bef;
            bef=nbef;
        }
        else{
            res+=c[px]-bef;
        }
        px++;
    }
    if(flag){
        fin = 1;
    }
}
int hc;
void solve(){
    cin>>n>>m;
    ll x;
    fin = 0;
    res = 0;
    rep(i,1,m){
        cin>>x;
        if(fin){
            cout<<res<<endl;
            continue;
        }
        deal(x);
        cout<<res<<endl;
    }
}

int main(){solve();
}