#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
#define log(x) (31-__builtin_clz(x))//谢谢hjt
const int MAXN = 2e5+5;
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int LOGN = log(MAXN)/log(2); 
int M[MAXN][LOGN+3]; 
int a[MAXN];
int z,m,n;
int max1[MAXN];
int max2[MAXN];

void init(){//初始化，复杂度O(nlogn) 
	for(int i=1;i<=n;i++) M[i][0]=i;//长度为1的区间最值是自己 
	for(int j=1;j<=LOGN;j++){
		for(int i=1;i<=n-(1<<j)+1;i++){
			if(a[M[i][j-1]]<a[M[i+(1<<(j-1))][j-1]]) M[i][j] = M[i][j-1];//这里以最小值为例 
			else M[i][j] = M[i+(1<<j-1)][j-1];
		}
	} 
}
inline int query(int l,int r){
	int k = log(r-l+1)/log(2);//向下取整
	if(a[M[l][k]]<a[M[r-(1<<k)+1][k]]) return M[l][k];
	else return M[r-(1<<k)+1][k];
}
inline int qry(int l,int r){
    return a[query(l,r)];//直接返回数值
}
bool flag;
void solve(){
    int la,lb,lc;
    flag = 0;
    cin>>n;
    rep(i,1,n) cin>>a[i];
    init();
    max1[0]=max2[n+1] = 0;
    rep(i,1,n) max1[i] = max(max1[i-1],a[i]);//前缀最大值
    repb(i,n,1) max2[i] = max(max2[i+1],a[i]);
    int l,r,mid,tmp;
    rep(i,2,n-1){//枚举中间段的开头
        l = i,r = n-1;//二分
        while(l<r){
            mid = (l+r)>>1;
            tmp = qry(i,mid);
            if(tmp>max1[i-1]||max1[i-1]<max2[mid+1]||tmp<max2[mid+1])
                l = mid+1;
            else if(tmp<max1[i-1]||max1[i-1]>max2[mid+1]||tmp<max2[mid+1])
                r = mid-1;
            else break;
        }
        mid = (l+r)>>1;
        if(mid>=i&&mid<=n-1){
            tmp = qry(i,mid);
            if(tmp==max1[i-1]&&tmp==max2[mid+1]){
                flag = 1;
                la = i-1,lb = mid-i+1,lc = n-mid;
                break;
            }
        }
    }
    if(!flag) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        cout<<la<<' '<<lb<<' '<<lc<<endl;
    }
}
signed main(){
    int z;
    cin>>z;
    while(z--) solve();
}
/*
int main(){
	int q;
	scanf("%d%d",&n,&q); 
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	init();
	int l,r;
	while(q--){
		scanf("%d%d",&l,&r);
		printf("%d\n",a[query(l,r)]);
	}
}
*/