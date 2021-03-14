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
const int MAXN = 114514;
int n;
string s;
int rm[10];
void solve(){
    cin>>n;
    cin>>s;
    rep(i,0,n-1){
        if(s[i]=='L'){
            rep(j,0,9)
                if(!rm[j]){rm[j] = 1;break;}
        }
        else if(s[i]=='R'){
            repb(j,9,0)
                if(!rm[j]){rm[j] = 1;break;}
        }
        else{
            int num = s[i]-'0';
            rm[num] = 0;
        }
    }    
    rep(i,0,9) cout<<rm[i];
}

int main(){solve();
}