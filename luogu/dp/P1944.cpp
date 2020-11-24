#include<iostream>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int MAXN = 1e6+5;
int dp[MAXN];
int path[MAXN];
string s;

bool mtch(char a,char b){
    if(a=='('&&b==')') return 1;
    else if(a=='['&&b==']') return 1;
    return 0;
}
void solve(){
    cin>>s;
    int siz = s.size();
    int maxx = 0;
    dp[0] = 0;
    path[0] = 1;
    rep(i,1,siz){
        dp[i] = 0;
        path[i] = -1;
        if(mtch(s[i-dp[i-1]-1],s[i])){
            dp[i] = dp[i-1]+dp[i-dp[i-1]-2]+2;
        }
        maxx = max(maxx,dp[i]);
    }
    rep(i,1,siz){
        if(dp[i]==maxx){
            int st = i-dp[i]+1;
            rep(j,st,i){
                cout<<s[j];
            }
        }
    }  
    cout<<endl;
}  
int main(){
    solve();
}