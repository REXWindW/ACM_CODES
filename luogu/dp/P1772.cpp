#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define ll long long 
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int MAXN = 105;//day
const int MAXM = 25;//dock
#define INF 0x7fffffff
const ll LINF = 1ll<<62;
#define mkp make_pair
#define ft first
#define sd second
typedef pair<int,int> pii;
int n,m,k,ee,dd;
int s,t;
bool OK[MAXN][MAXM];//can use?
ll co[MAXN][MAXN];
ll dp[MAXN];
vector<pii> e[MAXN];
ll d[MAXN];//min distance
bool vis[MAXN];
ll dijkstra(int l,int r){
	rep(i,1,m){
		d[i] = INF;
		vis[i] = 0;
	}
    rep(i,l,r){//day
        rep(j,1,m)
            if(!OK[i][j])
                vis[j] = 1;//mark cannot use
    }
	d[s] = 0;
	priority_queue< pii,vector<pii>,greater<pii> >q;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int now = q.top().second;
        if(now==t) break;//up speed
		q.pop();
		if(vis[now]) continue;
		vis[now] = 1;
		for(auto x:e[now]){ 
			int v = x.second;
			if(d[v]>d[now]+x.first){
				d[v] = d[now] + x.first;
				q.push(make_pair(d[v],v));//推入优先队列 
			}
		}
	}
    return d[t];
}

void solve(){
    cin>>n>>m>>k>>ee;
    //n day, m dock, k cost, ee cant use
    rep(i,1,n){
        rep(j,1,m) OK[i][j] = 1;//all can use
    }
    s = 1,t = m;
    int u,v,w;
    rep(i,1,ee){
        cin>>u>>v>>w;
        e[u].push_back(mkp(w,v));
        e[v].push_back(mkp(w,u));
    }
    cin>>dd;
    int x,l,r;
    rep(i,1,n){
        rep(j,1,m){
            OK[i][j] = 1; 
        }
    }
    while(dd--){
        cin>>x>>l>>r;
        rep(i,l,r){//mark cannot use
            OK[i][x] = 0;
        }
    }
    dp[0] = 0;//best result
    rep(i,1,n){
        rep(j,i,n){
            co[i][j] = (ll)(j-i+1)*dijkstra(i,j);
        }
    }
    rep(i,1,n){
        dp[i] = co[1][i];
        rep(j,1,i-1){
            dp[i] = min(dp[i],dp[j]+co[j+1][i]+k);
        }
    }
    cout<<dp[n]<<endl;
}
int main(){
    solve();
}