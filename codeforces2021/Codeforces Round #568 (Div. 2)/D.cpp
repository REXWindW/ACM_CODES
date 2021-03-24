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
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 114514*2;
typedef pair<ll,ll> pii;
#define ft first
#define sd second
#define mkp make_pair
pii a[MAXN];
void solve(){
    int n;
    cin>>n;
    rep(i,1,n){
        cin>>a[i].ft;
        a[i].sd = i;
    }
    sort(a+1,a+1+n);
    //删a1的情况
    ll d = a[3].ft-a[2].ft;
    bool flag = 1;
    rep(i,4,n){
        if(a[i].ft!=a[i-1].ft+d){
            flag=0;break;
        }
    }
    if(flag){
        cout<<a[1].sd<<endl;
        return;
    }
    //删掉a2的情况
    d = a[3].ft-a[1].ft;
    flag = 1;
    rep(i,4,n){
        if(a[i].ft!=a[i-1].ft+d){
            flag=0;break;
        }
    }
    if(flag){
        cout<<a[2].sd<<endl;
        return;
    }
    //删a3以上
    flag = 1;
    int del = 0;
    d = a[2].ft-a[1].ft;
    ll pre = a[2].ft;
    rep(i,3,n){
        if(a[i].ft!=pre+d){
            if(del){
                flag = 0;break;
            }
            else del = i;
        }
        else{
            pre = a[i].ft;
        }
    }
    if(flag){
        if(del)
            cout<<a[del].sd<<endl;
        else
            cout<<a[n].sd<<endl;//也可能是这样，就删掉最后一个
        return;
    }
    cout<<-1<<endl;
}

int main(){
    solve();
}