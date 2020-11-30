#include<iostream>
#include<ctime>
#include<string>
#include<random>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int MAXN = 2e5+5;
struct Node{
    int l,r;
    double val;
    int key;
    int size;
    string nam;
}fhq[MAXN];
int cnt,root;
mt19937 rnd(233);
inline int newnode(string s,double val){
    fhq[++cnt].val = val;
    fhq[cnt].key = rnd();
    fhq[cnt].size = 1;
    fhq[cnt].nam = s;
    return cnt;
}
inline void update(int now){
    fhq[now].size = fhq[fhq[now].l].size+fhq[fhq[now].r].size+1;
}
void split(int now,int siz,int &x,int &y){
    if(!now){x=y=0;return;}
    if(fhq[fhq[now].l].size<siz){
        x = now;
        split(fhq[now].r,siz-fhq[fhq[now].l].size-1,fhq[now].r,y);
    }
    else{
        y = now;
        split(fhq[now].l,siz,x,fhq[now].l);
    }
    update(now);
}
int merge(int x,int y){
    if(!x||!y) return x+y;
    if(fhq[x].key<fhq[y].key){
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
double hc;
inline void ins(string s,int pos){
    split(root,pos,x,y);
    //system("pause");
    int le=y,ri=x;
    while(fhq[le].l) le = fhq[le].l;
    while(fhq[ri].r) ri = fhq[ri].r;
    hc = (fhq[le].val+fhq[ri].val)/2;
    root = merge(merge(x,newnode(s,hc)),y);
}
void ask(int pos){
    split(root,pos,x,y);
    //编号从0开始
    int le = y;
    while(fhq[le].l) le = fhq[le].l;
    cout<<fhq[le].nam<<endl;
    root = merge(x,y);
}
void ldr(int now){
    if(!now) return;
    ldr(fhq[now].l);
    cout<<fhq[now].nam<<endl;
    ldr(fhq[now].r);
}
int n,m;
int main(){
    cin>>n;
    string str;
    rep(i,1,n){
        cin>>str;
        root = merge(root,newnode(str,i));
    }
    cin>>m;
    int pos;
    while(m--){
        cin>>str>>pos;
        ins(str,pos);
        /*
        cout<<"=========";
        cout<<endl;
        ldr(root);
        cout<<"=========";
        cout<<endl;
        */
    }
    cin>>m;
    while(m--){
        cin>>pos;
        ask(pos);
    }
}