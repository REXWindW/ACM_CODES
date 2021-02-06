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

string a;
int cnt[30];
void solve(){
    cin>>a;
    int siz = a.size();
    int typ = 0;
    rep(i,0,siz-1){
        cnt[a[i]-'a']++;
    }
    rep(i,0,26){
        if(cnt[i]) typ++;
    }
    if(typ==4){
        cout<<"Yes"<<endl;
    }
    else if(typ==3){
        typ = 0;
        rep(i,0,26){
            if(cnt[i]>=2) typ++;
        }
        if(typ) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }  
    else if(typ==2){
        typ = 0;
        rep(i,0,26){
            if(cnt[i]>=2) typ++;
        }
        if(typ==2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}

int main(){
    solve();
}