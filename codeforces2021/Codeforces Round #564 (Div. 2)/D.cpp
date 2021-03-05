#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
string s;
int n,mid;
typedef pair<int,int> pii;
#define ft first
#define sd second
#define mkp make_pair
priority_queue<pii,vector<pii>,greater<pii>> q;

void solve(){
    cin>>s;
    n = s.size();
    rep(i,0,n-1){//枚举左端点
        for(int j=i+2;j<n;j+=2){
            mid = (i+j)>>1;
            //cout<<i<<mid<<j<<endl;
            if(s[mid]==s[i]&&s[mid]==s[j]){
                q.push(mkp(j,i));
                break;
            }
        }
    }
    ll res = 0;
    rep(i,0,n-1){
        while(!q.empty()&&q.top().sd<i){
            q.pop();
        }
        if(q.empty()) break;
        res+=n-q.top().ft;
    }
    cout<<res<<endl;
}
int main(){
    solve();
}