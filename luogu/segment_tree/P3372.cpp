#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
const int MAXN = 114514;
int n,m,p;
#define ls pos<<1
#define rs pos<<1|1
#define int ll
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
struct Node{
    ll sum;
    ll lazy_sum,lazy_tim;//加/乘法的懒惰标记
}tree[MAXN<<2];
void pushup(int pos){
    tree[pos].sum = (tree[ls].sum + tree[rs].sum)%p;
}
void pushdown(int l,int r,int pos){
    if(l==r) return;//单个点就没必要pushdown了
    int mid = (l+r)>>1;
    if(tree[pos].lazy_tim!=1){
        tree[ls].sum *= tree[pos].lazy_tim;
        tree[ls].sum %= p;
        tree[ls].lazy_sum *= tree[pos].lazy_tim;
        tree[ls].lazy_sum %=p;
        
        tree[rs].sum *= tree[pos].lazy_tim;
        tree[rs].sum %= p;
        tree[rs].lazy_sum *= tree[pos].lazy_tim;
        tree[rs].lazy_sum %= p;

        tree[ls].lazy_tim *= tree[pos].lazy_tim;
        tree[ls].lazy_tim %= p;
        tree[rs].lazy_tim *= tree[pos].lazy_tim;
        tree[rs].lazy_tim %= p;
        tree[pos].lazy_tim = 1;
    }
    if(tree[pos].lazy_sum){
        tree[ls].sum += tree[pos].lazy_sum*(mid-l+1);
        tree[ls].sum %= p;
        tree[rs].sum += tree[pos].lazy_sum*(r-mid);
        tree[rs].sum %= p;
        tree[ls].lazy_sum += tree[pos].lazy_sum;
        tree[rs].lazy_sum += tree[pos].lazy_sum;
        tree[pos].lazy_sum = 0;
    }
}
void build(int l,int r,int pos){
    tree[pos].lazy_sum = 0;tree[pos].lazy_tim = 1;
    if(l==r){
        cin>>tree[pos].sum;
        tree[pos].sum %= p;
        return;
    }
    int mid = (l+r)>>1;
    build(l,mid,ls);
    build(mid+1,r,rs);
    pushup(pos);
}
void add(int l,int r,int L,int R,int pos,int x){
    if(r<L||l>R) return;
    pushdown(l,r,pos);
    if(L<=l&&r<=R){
        tree[pos].sum += x*(r-l+1);
        tree[pos].sum %= p;
        tree[pos].lazy_sum = x;
        return;
    }
    int mid = (l+r)>>1;
    add(l,mid,L,R,ls,x);
    add(mid+1,r,L,R,rs,x);
    pushup(pos);
}
void tim(int l,int r,int L,int R,int pos,int x){
    if(r<L||l>R) return;
    pushdown(l,r,pos);
    if(L<=l&&r<=R){
        tree[pos].sum *= x;
        tree[pos].sum %= p;
        tree[pos].lazy_tim = x;
        return;
    }
    int mid = (l+r)>>1;
    tim(l,mid,L,R,ls,x);
    tim(mid+1,r,L,R,rs,x);
    pushup(pos);
}
ll ans;
void query(int l,int r,int L,int R,int pos){
    if(r<L||l>R) return;
    pushdown(l,r,pos);
    if(L<=l&&r<=R){
        ans += tree[pos].sum;
        ans %= p;
        return;
    }
    int mid = (l+r)>>1;
    query(l,mid,L,R,ls);
    query(mid+1,r,L,R,rs);
}
int tquery(int L,int R){
    ans = 0;
    query(1,n,L,R,1);
    return ans%p;
}
signed main(){
    //freopen("outp.txt","w",stdout);
    cin>>n>>m>>p;
    build(1,n,1);
    int typ;
    int l,r,x;
    while(m--){
        cin>>typ;
        if(typ==1){
            cin>>l>>r>>x;
            tim(1,n,l,r,1,x);
        }
        else if(typ==2){
            cin>>l>>r>>x;
            add(1,n,l,r,1,x);
        }
        else if(typ==3){
            cin>>l>>r;
            cout<<tquery(l,r)<<endl;
        }
        else if(typ==4){
            rep(i,1,n) cout<<tquery(i,i)<<' ';
            cout<<endl;
        }
    }
}