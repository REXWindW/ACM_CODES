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

const int MAXN = 1e6+5;
int a[MAXN];
int p1[MAXN],p2[MAXN];//记录两个的位置，如果是一个点那就是p1
int sal;
int n;
typedef pair<int,int> pii;
queue<int> c1;
queue<int> c3;
int main(){
    sal = 1;//天花板
    cin>>n;
    rep(i,1,n){
        cin>>a[i];
        p1[i]=p2[i]=0;//表示没有放置靶子
    }
    bool flag=1;
    repb(i,n,1){
        if(a[i]==3){
            //3优先考虑接3或者2
            if(!c3.empty()){
                p2[c3.front()]=i;
                c3.pop();
                p1[i] = i;
                c3.push(i);//3可以接在3后面
            }
            else if(!c1.empty()){
                p2[c1.front()] = i;
                c1.pop();
                p1[i] = i;
                c3.push(i);
            }
            else{
                flag=0;
                break;
            }
        }
        else if(a[i]==2){
            if(!c1.empty()){
                p1[c1.front()] = i;//把那个点拉下来
                c1.pop();
                p1[i] = i;
                c3.push(i);//2可以给3用
            }
            else{
                flag=0;break;
            }
        }
        else if(a[i]==1){
            p1[i]=i;//在i,i放点
            c1.push(i);//入队
        }
    }
    if(!flag) cout<<-1<<endl;
    else{
        vector<pii> res;
        rep(i,1,n){
            if(p2[i]) res.push_back(make_pair(p2[i],i));
            if(p1[i]) res.push_back(make_pair(p1[i],i));
        }
        cout<<res.size()<<endl;
        int siz = res.size();
        rep(i,0,siz-1){
            cout<<res[i].first<<' '<<res[i].second<<endl;
        }
    }
}