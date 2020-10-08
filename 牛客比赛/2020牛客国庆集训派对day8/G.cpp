//用的文艺平衡树板子
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=1000007;
const int inf=1e9;

int f[MAXN],cnt[MAXN],ch[MAXN][2],size[MAXN],key[MAXN],tag[MAXN],sz,rt;
int n,m,x,y,data[MAXN];

bool get(int x)
{
	return ch[f[x]][1]==x;
}

void pushup(int x)
{
	size[x]=size[ch[x][0]]+size[ch[x][1]]+1;
}

void pushdown(int x)
{
	if (x && tag[x])
	{
		tag[ch[x][0]]^=1;
		tag[ch[x][1]]^=1;
		swap(ch[x][0],ch[x][1]);
		tag[x]=0;
	}
}

void rotate(int x)
{
	int old=f[x],oldf=f[old],which=get(x);
	pushdown(old); pushdown(x);//不要忘记pushdown 
	ch[old][which]=ch[x][which^1]; f[ch[old][which]]=old;
	ch[x][which^1]=old; f[old]=x;
	f[x]=oldf;
	if (oldf) ch[oldf][ch[oldf][1]==old]=x;
	pushup(old); pushup(x);
}

void splay(int x,int goal)//比上面的goal加了一个目标goal而已 
{
	for (int fa; (fa=f[x])!=goal; rotate(x))
		if (f[fa]!=goal)
			rotate((get(x)==get(fa))?fa:x);
	if (!goal) rt=x;
}

int build_tree(int fa,int l,int r)
{
	if (l>r) return 0;
	int mid=(l+r)>>1;
	int now=++sz;
	key[now]=data[mid]; f[now]=fa; tag[now]=0;
	ch[now][0]=build_tree(now,l,mid-1);
	ch[now][1]=build_tree(now,mid+1,r);
	pushup(now);
	return now;
}

int rnk(int x)//这里的x成了名次 
{
	int now=rt;
	while (1)
	{
		pushdown(now);//次处忘记pushdown 
		if (x<=size[ch[now][0]]) now=ch[now][0];
		else
		{
			x-=size[ch[now][0]]+1;
			if (!x) return now;
			now=ch[now][1];
		}
	}
}

void turn(int l,int r)
{
	l=rnk(l);
	r=rnk(r+2);//查询排名，第几个点 
	splay(l,0);//先让l占下根的位置，然后让r+2把他挤到左子树上去 
	splay(r,l);
	pushdown(rt);
	tag[ch[ch[rt][1]][0]]^=1;//根的右子树的左子树 
}

void write(int now)
{
	pushdown(now);
	if (ch[now][0]) write(ch[now][0]);
	if (key[now]!=-inf && key[now]!=inf) printf("%d ",key[now]);
	if (key[ch[now][1]]) write(ch[now][1]);
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) data[i+1]=i;
	data[1]=-inf; data[n+2]=inf;
	rt=build_tree(0,1,n+2);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d",&x,&y);
		turn(x,x+y-1);
        //write(rt);
        //cout<<endl;
        turn(1,x-1);
        //write(rt);
        //cout<<endl;
        turn(1,x+y-1);
        //write(rt);
        //cout<<endl;
	}
	write(rt);
	return 0;
}