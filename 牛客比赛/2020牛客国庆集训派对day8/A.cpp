#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
using namespace std;

template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=b;i--)
#define log(x) (31-__builtin_clz(x))
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
//#define INF 0x7fffffff
string s[66] = {"a1","a2","a3","a4","a5","a6","a7","a8",
"b8","b7","b6","b5","b4","b3","b2","b1",
"c1","c2","c3","c4","c5","c6","c7","c8",
"d8","d7","d6","d5","d4","d3","d2","d1",
"e1","e2","e3","e4","e5","e6","e7","e8",
"f8","f7","f6","f5","f4","f3","f2","f1",
"g1","g2","g3","g4","g5","g6","g8","g7",
"h7","h6","h5","h4","h3","h2","h1","h8",};
int n;
void solve(){
	cin>>n;
    if(n==56){
       rep(i,0,53){
           cout<<s[i]<<' ';
       }
       cout<<"g7"<<' '<<"g8"<<' '<<"h8"<<endl;
       return;
    }
    int st = n-2;
    rep(i,0,st){
        cout<<s[i]<<' ';
    }
    if(s[st][0]=='h'){
        cout<<"h1"<<' ';
        cout<<"h8"<<endl;
    }
    else if(s[st][1]=='8'){
        cout<<"g8"<<' ';
        cout<<"h8"<<endl;
    }
    else{//不同行不同列的情况
        cout<<'h'<<s[st][1]<<' ';
        cout<<"h8"<<endl;
    }
}

int main(){
	solve();
}