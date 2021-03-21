#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 114514;
int d;
int n;
int ntprim[MAXN];
vector<int> prm;
void init(){
    rep(i,2,MAXN){
        if(ntprim[i]) continue;
        prm.push_back(i);
        for(int j=i+i;j<=MAXN;j+=i) ntprim[j]=1;
    }//筛质数
}
void solve(){
    cin>>d;
    int a[4];
    int cnt = 1;
    int now = 1;
    int siz = prm.size();
    rep(i,0,siz-1){
        if(prm[i]-now>=d){
            a[cnt] = prm[i];
            now = a[cnt];
            cnt++;
            if(cnt==3) break;
        }
    }
    cout<<a[1]*a[2]<<endl;
}

int main(){
    init();
    int z;
    cin>>z;
    while(z--) solve();
}