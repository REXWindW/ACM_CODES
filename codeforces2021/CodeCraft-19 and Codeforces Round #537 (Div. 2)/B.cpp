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
ll avg;
int n,k,m;
const int MAXN = 114514;
int a[MAXN];
ll summ;
void solve(){
    cin>>n>>k>>m;
    avg = 0;
    rep(i,1,n){
        cin>>a[i];
        summ += a[i];
    }
    double tres = (double)(summ+min((ll)m,(ll)k*n))/n;
    sort(a+1,a+1+n,greater<int>());
    int px = 1;
    while(px<=n&&a[px+1]==a[1]) px++;//找到有多少个最大的
    int tmp;
    if(m<n-px){//不够把非px的都去掉
        rep(i,1,n-m)
            avg+=a[i];
        cout<<max(tres,(double)avg/(n-m))<<endl;
        return;
    }
    //足够把非px的都去掉
    m-=n-px;
    if(m>=px){
        tmp = min(k,m-(px-1));
        cout<<max(tres,(double)a[1]+tmp)<<endl;
        return;
    }
    else{
        rep(i,1,px-m){
            avg+=a[i];
        }
        cout<<max(tres,(double)avg/(px-m))<<endl;
    }
}

int main(){
    solve();
}