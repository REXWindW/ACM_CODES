#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
typedef pair<int,int> pii;
#define ft first
#define sd second
#define mkp make_pair
priority_queue<pii,vector<pii>,greater<pii>> q;
int n,k,m;
ll sum;
void solve(){
    cin>>n>>k>>m;
    int hc;
    sum = 0;
    rep(i,1,n){
        cin>>hc;
        sum+=hc;
        q.push(mkp(hc,0));//操作了0次
    }
    pii now;
    while(m){
        if(q.size()==1) break;
        now = q.top();
        if(now.sd==k){//已经不能再增加了，要去掉并且返还所有的k
            m+=now.sd;//返还
            sum-=now.ft;
            q.pop();
            continue;
        }
        //接下来判断是删掉好还是加1好
        double de = (double)(sum-now.ft)/(q.size()-1);
        double up = (double)(sum+1)/q.size();
        if(de>=up){//删掉更好
            m--;
            m+=now.sd;//返还
            sum-=now.ft;
            q.pop();
        }
        else{//加一更好
            m--;
            q.pop();
            q.push(mkp(now.ft+1,now.sd+1));
            sum++;
        }
    }
    now = q.top();
    if(q.size()==1){
        int tmp = min(m,k-now.sd);
        cout<<now.ft+tmp<<endl;
        return;
    }
    while(!q.empty()){
        cout<<(double)sum/q.size()<<endl;
    }
}

int main(){
    solve();
}