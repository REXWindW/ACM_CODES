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

typedef pair<int,int> pii;
#define ft first
#define sd second
#define mkp make_pair
int n;
const int MAXN = 114514*50;//和最大到5e6级别
pii mp[MAXN];
int a[MAXN];
bool chongfu(int a,int b,int c,int d){
    if(a==c||b==d) return 1;
    if(a==d||b==c) return 1;
    return 0;
}
void solve(){
    cin>>n;
    rep(i,1,n) cin>>a[i];
    int tmp;
    rep(i,1,n){
        rep(j,i+1,n){
            tmp = a[i]+a[j];
            if(mp[tmp].ft==0){
                mp[tmp].ft = i;
                mp[tmp].sd = j;
            }
            else{
                if(!chongfu(mp[tmp].ft,mp[tmp].sd,i,j)){
                    cout<<"YES"<<endl;
                    cout<<mp[tmp].ft<<' '<<mp[tmp].sd<<' '<<i<<' '<<j<<endl;
                    return;
                }
            }
        }
    }
    cout<<"NO"<<endl;
}

int main(){
    solve();
}