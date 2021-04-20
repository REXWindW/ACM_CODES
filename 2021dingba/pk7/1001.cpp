#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
const int MAXN = 5*114514;
set<int> st[MAXN];
int n,m;
int typ;

int main(){
    read(n);read(m);
    int a,b,c;
    rep(i,1,n){
        read(typ);
        if(typ==1){
            read(a);read(b);read(c);
            st[a].insert(i);
            st[b].insert(i);
            st[c].insert(i);
        }
        else if(typ==2){
            read(a);read(b);
            vector<int> ans;
            set_intersection(st[a].begin(),st[a].end(),st[b].begin(),st[b].end(),inserter(ans,ans.begin()));
            //cout<<st[a].size()<<':'<<st[b].size()<<':'<<ans.size()<<endl;
            printf("%lld\n",st[a].size()+st[b].size()-(2*(int)ans.size()));
        }
    }
}