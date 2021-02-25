#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define int ll
const int MAXN=2e5+15;
struct node{
    int f;int t;int d;
    bool operator < (const node &a) const{
        return d>a.d;
    }
};
int n,m;
int vis[MAXN];
vector <node> ei[MAXN];//原始的图
vector<int> w[MAXN];
vector <int> e[MAXN];
vector <node> edges;
priority_queue <node> q;
inline int read()
{
    char ch=getchar();
    int s=0,f=1;
    while (!(ch>='0'&&ch<='9')) {if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9') {s=(s<<3)+(s<<1)+ch-'0';ch=getchar();}
    return s*f;
}
ll prim()
{
    ll ans=0;
    int cnt=0;
    q.push((node){-1,1,0});
    while (!q.empty()&&cnt<=n){
        node k=q.top();q.pop();
        if (vis[k.t]) continue;
        vis[k.t]=1;
		if(k.f!=-1){
			w[k.f].push_back(k.d);
			w[k.t].push_back(k.d);
			e[k.f].push_back(k.t);
			e[k.t].push_back(k.f);
			ans+=k.d;
		}
        cnt++;
        for (int i=0;i<(int)ei[k.t].size();i++)
            if (!vis[ei[k.t][i].t])
                q.push((node){ei[k.t][i].f,ei[k.t][i].t,ei[k.t][i].d});
    }
    return ans;
}
//树剖板子
ll ans;
int da[MAXN];//记录dfn序上的各点数值用来初始化线段树
int rt;//根
struct tree{
	int maxx;
};
struct St{//线段树 
	tree t[MAXN<<2];
	void pushup(int pos){ 
		t[pos].maxx=max(t[pos<<1].maxx,t[pos<<1|1].maxx);
		return;
	}
    void build(int l,int r,int pos){ 
		t[pos].maxx=0;
		if(l==r){
			t[pos].maxx = da[l];
			return;
		}
		int mid = (l+r)>>1;
		build(l,mid,pos<<1);
		build(mid+1,r,pos<<1|1);
		pushup(pos);
	}
	void query(int L,int R,int l,int r,int pos){
		if(L<=l&&r<=R){
			ans = max(ans,t[pos].maxx);
			return;
		}
		if(r<L||R<l) return;
		int mid = (l+r)>>1;
		query(L,R,l,mid,pos<<1);
		query(L,R,mid+1,r,pos<<1|1);
		return;
	}
	//查询和修改，为了简化参数，我又写了两个 
	ll tquery(int L,int R){
		if(L>R) return 0;
		ans = 0;
		query(L,R,1,n,1);
		return ans; 	
	}
};
//树结构 
int a[MAXN];//记录编号对应节点的初始数值

//树剖部分
St segt;
int si[MAXN],dep[MAXN],fa[MAXN],rem[MAXN],dfn[MAXN],top[MAXN];
int dfn_num;

void dfs1(int x,int faa){//预处理出fa,dep,si,rem
	int ma = 0;//用来x的重儿子，记录最大的size
	si[x] = 1;
	for(int i=0;i<e[x].size();i++){
        int v = e[x][i];
		if(v==faa) continue;//跳过父亲节点 
		dep[v] = dep[x]+1;//更新儿子的dep 
        a[v] = w[x][i];//给点权(实际上是边权
		dfs1(v,x);
		si[x] += si[v];//x的size加上当前儿子的size
		fa[v] = x;//标记v的父节点为x 
		if(si[v]>ma){
			ma = si[v];
			rem[x] = v;//记录重儿子 
		} 
	}
} 

void dfs2(int x,int faa){//预处理出dfn，top
	if(rem[faa]==x) top[x] = top[faa];//同一条重链同一个top 
	else top[x] = x;//否则为重链头
	dfn[x] = ++dfn_num;//更新树剖序，同时下标自增
	da[dfn_num] = a[x];
	if(rem[x]) dfs2(rem[x],x);//优先遍历重儿子
	for(auto v:e[x]){
		if(v==faa) continue;
		if(v==rem[x]) continue;//重儿子之前已经遍历过了
		dfs2(v,x); 
	} 
}

inline ll cal(int L,int R){
	return segt.tquery(L,R);
}

void init(){//初始化
	dfn_num=0;
    a[rt]=0;
	dfs1(rt,0);
	dfs2(rt,0);
	segt.build(1,n,1);//这里通过da来初始化线段树 
}

ll query(int x,int y){
	ll res=0;
	while(top[x]!=top[y]){//跳到同一条重链 
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		//重链深度更大的点优先往上跳
		res = max(res,cal(dfn[top[x]],dfn[x]));//算上这条重链的 
		x = fa[top[x]];//跳到重链头的父节点上 
	}
	//跳出这个循环时，xy已经在同一个重链上了
	res = max(res,cal(min(dfn[x],dfn[y])+1,max(dfn[x],dfn[y])));
	//xy不确定顺序对不对，所以取minmax
	return res;
}
//树剖板子
signed main()
{
    n=read();m=read();
    for (int i=1;i<=m;i++){
        int x=read(),y=read(),z=read();
        edges.push_back((node){x,y,z});//记录所有的边
        ei[x].push_back((node){x,y,z});ei[y].push_back((node){y,x,z});
    }
    ll tot = prim();
	//cout<<"tot=="<<tot<<endl;
    //prim跑好之后树剖？
    rt = 1;
    init();
    rep(i,0,m-1){//处理边
        //cout<<edges[i].f<<' '<<edges[i].t<<':'<<query(edges[i].f,edges[i].t)<<endl;
		printf("%lld\n",tot+edges[i].d-query(edges[i].f,edges[i].t));
	}
    return 0;
}