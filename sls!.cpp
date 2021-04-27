#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
using namespace std;
int T,s,n;
long long m,k,now;
struct 
{
	long long x,v;
}q[110];
void solve()
{
	scanf("%d%d%lld%lld",&s,&n,&m,&k);
	for (int i=1;i<=n;i++) scanf("%lld%lld",&q[i].x,&q[i].v);
	if (m-1ll*50*q[1].x<0) {printf("Impossible"); return;}
	now=m; now-=1ll*50*q[1].x; //m=1000000000000000000;
	q[n+1].x=s; q[n+1].v=1000000000000;
	for (int i=1;i<=n;i++)
	{
        cout<<"oil"<<now<<endl;
		int go=-1;long long ma=q[i].v;
		for (int j=i+1;j<=n;j++) if (m-1ll*50*(q[j].x-q[i].x)>=0 && q[j].v<ma) {
            cout<<"find"<<j<<"cheaper than "<<i<<endl;
            ma=q[j].v; go=j; break;
        }
		if (go==-1) 
		{
			long long t=min(max(1ll*50*(s-q[i].x)-now,0ll),1ll*m-now); 
			now+=t;
			k-=1ll*t*q[i].v;
		}
		else
		{
			long long t=min(1ll*m-now,max(1ll*50*(min(q[go].x,1ll*s)-q[i].x)-now,0ll));
			now+=t;
			k-=1ll*t*q[i].v;
		}
		if (now>=1ll*50*(s-q[i].x)) 
		{
			if (k>=0) printf("%lld\n",k);else printf("No profit\n"); 
			return;
		}
		if (now-1ll*50*(q[i+1].x-q[i].x)<0) {printf("Impossible\n"); return;}
		now-=1ll*50*(q[i+1].x-q[i].x);
	}
	assert(0);
return;
}
int main()
{
    freopen("F_in.txt","r",stdin);
    freopen("sls.txt","w",stdout);
	scanf("%d",&T);
	while (T--) solve();
return 0;
}
/*
1
120 4 2000 20000
20 1
40 2
60 3
80 4
*/