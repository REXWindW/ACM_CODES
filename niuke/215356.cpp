#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define INF 0x3f3f3f3f
#define fat pos>>1
#define lson pos<<1
#define rson pos<<1|1
typedef pair<int,int> pii;//第一位
#define mkp make_pair
#define ft first
#define sd second
cosnt int MAXN = 2e5+5;

struct Tree{
    set<pii> st;
}tree[MAXN<<2];
inline void ins(Tree& tr,int x){//把x推进来
    pii now = lower_bound()
}
void build(int l,int r,int pos){
    int hc;
    if(l==r){
        cin>>hc;
        t[pos].st.insert(mkp(hc,1));
        while(){

        }
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
}

void solve(){
    
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}