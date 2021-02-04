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
const ll med = 1e9+7;
string s;
ll dp[114514];
void init(){
    dp[0]=1;dp[1]=1;
    rep(i,2,100001){
        dp[i] = dp[i-1]+dp[i-2];
        dp[i]%=med;
    }
}
void solve(){
    cin>>s;
    int siz = s.size();
    ll res = 1;
    int cnt;
    rep(i,0,siz-1){
        cnt = 0;
        if(s[i]=='u'){
            while(s[i]=='u'&&i<siz){
                cnt++;
                i++;
            }
            res*=dp[cnt];
            res%=med;
            i--;
        }
        if(s[i]=='n'){
            while(s[i]=='n'&&i<siz){
                cnt++;
                i++;
            }
            res*=dp[cnt];
            res%=med;
            i--;
        }
        if(s[i]=='w'||s[i]=='m'){
            res=0;
        }
    }
    cout<<res<<endl;
}

int main(){
    init();
    solve();
}