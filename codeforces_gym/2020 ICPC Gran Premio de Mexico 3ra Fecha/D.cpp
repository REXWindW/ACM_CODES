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
string s;
string res;
ll tmp,k;
void solve(){
    cin>>s>>k;
    res.clear();
    bool flag = 1;
    int siz = s.size();
    rep(i,0,siz-1){
        if(!isdigit(s[i])) res+=s[i];
        tmp=0;
        while(isdigit(s[i])){
            tmp*=10;tmp+=(s[i]-'0');
            if(tmp>k){
                flag = 0;break;
            }
            i++;
        }
        if(tmp){
            res+=string(tmp,s[i]);   
        }
        if(res.size()>k){
            flag = 0;break;
        }
    }
    if(!flag){
        cout<<"unfeasible"<<endl;
    }
    else cout<<res<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}
/*
4
5a2bc 8
5a2bc 7
asdf4x 50
asjkdf10000000000kz 1000000
*/