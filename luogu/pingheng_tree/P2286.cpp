#include<iostream>
#include<ctime>
#include<random>
using namespace std;

#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int MAXN = 1e5+5;
const int med = 1e6;
mt19937 rnd();
int n;
struct Node{
    int l,r;
    int val,key;
    int size;
}fhq[2][MAXN];//0是人,1是宠物
int cnt[2],root[2];//两个树
inline void update(int typ,int now){
    fhq[typ][now].size = fhq[typ][fhq[typ][now].l].size + fhq[typ][fhq[typ][now].r].size + 1; 
}
inline int newnode(int typ,int val){
    cnt[typ]++;
    fhq[typ][cnt[typ]].val = val;
    fhq[typ][cnt[typ]].key = rand();
    return cnt[typ];
}
void split(int typ,int now,int val,int &x,int &y){
    if(!now){x=y=0;return;}
    if(fhq[typ][now].val<=val){
        x = now;
        split(typ,fhq[typ][now].r,val,fhq[typ][now].r,y);
    }
    else{
        y = now;
        split(typ,fhq[typ][now].l,val,x,fhq[typ][now].l);
    }
    update(typ,now);
}
int merge(int typ,int x,int y){
    if(!x||!y) return x+y;
    if(fhq[typ][x].key>fhq[typ][y].key){
        fhq[typ][x].r = merge(typ,fhq[typ][x].r,y);
        update(typ,x);
        return x;
    }
    else{
        fhq[typ][y].l = merge(typ,x,fhq[typ][y].l);
        update(typ,y);
        return y;
    }
}
int x,y,z;
inline void ins(int typ,int val){
    split(typ,root[typ],val,x,z);
    y = newnode(typ,val);
    root[typ] = merge(typ,merge(typ,x,y),z);
}
inline void del(int typ,int val){
    split(typ,root[typ],val,x,z);
    split(typ,x,val-1,x,y);
    y = merge(typ,fhq[typ][y].l,fhq[typ][y].r);
    root[typ] = merge(typ,merge(typ,x,y),z);
}
inline int check(int typ,int val){//这里要注意是反的
    split(typ,root[typ],val,x,y);
    int le,ri;le=y,ri=x;
    while(fhq[typ][le].l) le = fhq[typ][le].l;
    while(fhq[typ][ri].r) ri = fhq[typ][ri].r;
    int ret;
    if(!ri||!le) return ri+le;
    if(val-fhq[typ][ri].val<=fhq[typ][le].val-val) ret = ri;
    else ret = le;
    merge(typ,x,y);
    return ret;
}
int main(){
    cin>>n;
    int res = 0;
    int typ,hc;
    rep(i,1,n){
        cin>>typ>>hc;
        if(root[typ^1]){
            int chs = check(typ^1,hc);
            //cout<<root[typ^1]<<' '<<chs<<endl;
            //cout<<hc<<" : "<<fhq[typ^1][chs].val<<endl;
            res = (res+abs(hc-fhq[typ^1][chs].val))%med;
            del(typ^1,fhq[typ^1][chs].val);//删除最接近的一个
        }
        else
            ins(typ,hc);
        //cout<<"checksize"<<root[0]<<"["<<fhq[0][root[0]].size<<','<<fhq[1][root[1]].size<<endl;
    }
    cout<<res<<endl;
}