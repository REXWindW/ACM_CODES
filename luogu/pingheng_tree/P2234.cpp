#include<iostream>
#include<ctime>
#include<random>
using namespace std;
#define ll long long
const int MAXN = 114514;
#define INF 0x3f3f3f3f
struct Node{
    int l,r;
    int val,key;
    int size;
}fhq[MAXN];
int cnt,root;
ll res = 0;
mt19937 rnd(233);
inline int newnode(int val){
    fhq[++cnt].val = val;
    fhq[cnt].key = rnd();
    fhq[cnt].size = 1;
    return cnt;
}
inline void update(int now){
    fhq[now].size = fhq[fhq[now].l].size+fhq[fhq[now].r].size+1;
}
void split(int now,int val,int &x,int &y){
    if(!now){x=y=0;return;}
    if(fhq[now].val<=val){
        x = now;
        split(fhq[now].r,val,fhq[now].r,y);
    }
    else{
        y = now;
        split(fhq[y].l,val,x,fhq[now].l);
    }
    update(now);
}
int merge(int x,int y){
    if(!x||!y) return x+y;
    if(fhq[x].key>fhq[y].key){
        fhq[x].r = merge(fhq[x].r,y);
        update(x);
        return x;
    }
    else{
        fhq[y].l = merge(x,fhq[y].l);
        update(y);
        return y;
    }
}
int x,y,z;
inline void ins(int val){
    split(root,val,x,y);
    int le=y,rr=x;
    //cout<<"le"<<le<<"ri"<<rr<<endl;
    while(fhq[le].l) le = fhq[le].l;
    while(fhq[rr].r) rr = fhq[rr].r;
    //cout<<"cj"<<min(abs(val-fhq[le].val),abs(val-fhq[rr].val))<<endl;
    res += min(abs(val-fhq[le].val),abs(val-fhq[rr].val));
    root = merge(merge(x,newnode(val)),y);
}
void solve(){
    int t;
    cin>>t;
    int hc;
    int hc1;
    root = newnode(-INF);
    t--;
    cin>>hc;
    hc1=hc;
    root = merge(root,newnode(hc));
    root = merge(root,newnode(INF));
    while(t--){
        cin>>hc;
        ins(hc);
    }
    cout<<hc1+res<<endl;
}
int main(){
    solve();
}