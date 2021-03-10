#include<iostream>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define ls pos<<1
#define rs pos<<1|1
const int MAXN = 114514;
ll n,med;
struct Node{
    ll ji;
}tree[MAXN<<2];
void pushup(int pos){
    tree[pos].ji = tree[ls].ji*tree[rs].ji%med;  
}
ll ans;
void query(int l,int r,int L,int R,int pos){
    if(r<L||R<l) return;
    if(L<=l&&r<=R){
        ans = ans*tree[pos].ji%med;
        return;
    }
    int mid = (l+r)>>1;
    query(l,mid,L,R,ls);
    query(mid+1,r,L,R,rs);
}
ll tquery(int l,int r){
    ans = 1;
    query(1,n,l,r,1);
    return ans%med;
}
//只需要单点修改所以不需要lazy
void update(int l,int r,int des,int pos,int x){
    if(r<des||l>des) return;
    if(l==des&&r==des){
        tree[pos].ji = x;
        return;
    }
    int mid = (l+r)>>1;
    update(l,mid,des,ls,x);
    update(mid+1,r,des,rs,x);
    pushup(pos);
}
void build(int l,int r,int pos){
    tree[pos].ji = 1;
    if(l==r) return;
    int mid = (l+r)>>1;
    build(l,mid,ls);
    build(mid+1,r,rs);
    pushup(pos);
}
void solve(){
    cin>>n>>med;
    build(1,n,1);
    int typ;
    ll x;
    rep(i,1,n){
        cin>>typ;
        if(typ==1){
            cin>>x;
            update(1,n,i,1,x);
            cout<<tquery(1,n)<<endl;
        }
        else if(typ==2){
            cin>>x;
            update(1,n,x,1,1);
            cout<<tquery(1,n)<<endl;
        }
    }
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}