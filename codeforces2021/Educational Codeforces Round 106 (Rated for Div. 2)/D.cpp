#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
int c,d,x;
const int MAXN = 2e7;//有可能到达2e7的情况
int zyz[MAXN+5];
void init(){//每个数的质因子数量
    rep(i,2,MAXN){
        if(zyz[i]) continue;
        for(int j=i;j<=MAXN;j+=i){
            zyz[j]++;//标记质因子
        }
    }
}
vector<int> vec;
void solve(){
    cin>>c>>d>>x;
    int sqr = sqrt(x);
    vec.clear();
    rep(i,1,sqr){
        if(x%i==0){
            vec.push_back(i);
            if(i*i!=x) vec.push_back(x/i);
        }
    }
    int siz = vec.size();
    int tmp;
    ll res=0;
    rep(k,0,siz-1){//k的取值
        tmp = x/vec[k]+d;
        if(tmp%c) continue;
        tmp/=c;
        //cout<<"zyz["<<tmp<<"]=="<<zyz[tmp]<<endl;
        res+=1<<zyz[tmp];
    }
    cout<<res<<endl;
}
int main(){
    init();
    int z;
    cin>>z;
    while(z--) solve();
}