//有效长度是(实际长度+1)/2
//两侧的有效长度=实际长度
//开两个set，一个存没有被占据的马桶组成的连续段，另一个存
//特殊比较函数的第一个关键字是区间的有效长度
//第二个set使用不同的比较函数，存放熊猫的位置，使用2类操作的时候可能导致相邻的两个区间被和并
//用第二个set找到它前面的和后面的熊猫，这样可以得出合并之后的段
//合并后再在set1中删除合并之前的两段
#include<iostream>
#include<set>
#include<cstdio>
#include<algorithm>
using namespace std;
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
struct duan{
    int yx;//有效
    int st,ed;//起点终点
    friend bool operator < (duan a,duan b){//自定义set1排序函数
        if(a.yx>b.yx) return 1;
        else return a.yx==b.yx&&a.st<b.st;
    }
};
const int MAXN = 1e5+5;
set<duan> set1;
set<int> set2;//存位置
int pos[MAXN];//存第x次操作的人的位置
int n,m;
const int INF = 0x3f3f3f3f;
void solve(){
    int typ,hc;
    set2.insert(0);set2.insert(n+1);//插两个假人
    set1.insert(duan{INF,1,n});//这个有效值其实是无所谓的只要够大？
    rep(tim,1,m){//按照时间进人
        cin>>typ;
        duan now;
        int youxiao;//计算有效值
        if(typ==1){
            now = *set1.begin();
            //cout<<now.yx<<' '<<now.st<<' '<<now.ed<<endl;
            set1.erase(now);//出队
            if(now.st==1){//特判开头,也能让最开始的优先插在1
                pos[tim] = 1;
                youxiao = (now.ed-now.st);
                set1.insert(duan{youxiao,2,now.ed});
                set1.insert(duan{0,1,0});//空的也推进去
            }
            else if(now.ed==n){//特判结尾
                pos[tim] = n;
                youxiao = (n-1 - now.st + 1);
                set1.insert(duan{youxiao,now.st,n-1});
                set1.insert(duan{0,n+1,n});
            }
            else{//正常插入
                pos[tim] = (now.st+now.ed)/2;
                youxiao = (pos[tim]-now.st+1)/2;
                set1.insert(duan{youxiao,now.st,pos[tim]-1});
                youxiao = (now.ed-pos[tim]+1)/2;
                set1.insert(duan{youxiao,pos[tim]+1,now.ed});
            }
            set2.insert(pos[tim]);
            cout<<pos[tim]<<endl;//输出答案
        }
        else if(typ==2){
            cin>>hc;
            int tpos = pos[hc];//位置
            int px = *set2.find(tpos);
            set<int>::iterator it;//迭代器
            it = set2.lower_bound(px);
            it--;
            int pre = *(it);//前驱
            it = set2.upper_bound(px);
            int nxt = *(it);//后继
            set2.erase(px);//擦除
            //删除左边
            if(pre==0) youxiao = px-pre-1;
            else youxiao = (px-pre+1)/2;
            set1.erase(duan{youxiao,pre+1,px-1});
            //删除右边
            if(nxt==n+1) youxiao = nxt-px-1;
            else youxiao = (nxt-px+1)/2;
            set1.erase(duan{youxiao,px+1,nxt-1});
            //插入新的
            if(pre==0&&nxt==n+1) youxiao = INF;
            else if(pre==0||nxt==n+1) youxiao = nxt-pre-1;
            else youxiao = (nxt-pre+1)/2;
            set1.insert(duan{youxiao,pre+1,nxt-1});
        }
        //cout<<"check1"<<set1.size()<<endl;
    }
}
int main(){
    while(cin>>n>>m) solve();
}