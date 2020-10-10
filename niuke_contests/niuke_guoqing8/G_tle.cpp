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

struct Node{
    int data;
    Node* nxt;
};
int n,m;

int main(){
	Node head;
    cin>>n>>m;
    Node*px = &head;
    rep(i,1,n){
        px->nxt = new Node{i,NULL};
        px = px->nxt;
    }
    int l,len;
    while(m--){
        cin>>l>>len;
        px = &head;
        Node* pxb4;
        rep(i,1,l){pxb4 = px;px = px->nxt;}
        Node* px2 = px;
        rep(i,2,len) px2 = px2->nxt;
        pxb4->nxt = px2->nxt;
        px2->nxt = head.nxt;
        head.nxt = px;
    }
    px = &head;
    rep(i,1,n){
        px = px->nxt;
        cout<<px->data;
        if(i!=n) cout<<' ';
    }
    cout<<endl;
}