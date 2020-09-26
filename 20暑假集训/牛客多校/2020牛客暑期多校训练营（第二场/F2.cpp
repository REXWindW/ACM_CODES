#include<iostream>
#include<deque>
using namespace std;
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define rep(i,a,b) for(int i=(a);i<=(b);i++) 
#define ll long long
const int MAXN = 5005;
struct node{
	int data;
	int order;
};
//int gcdm[MAXN][MAXN];
int a[MAXN][MAXN];
int res[MAXN][MAXN];//先处理，每行进行单调队列出结果 
//int res2[MAXN][MAXN];//后处理，每个列上的res进行单调队列 
//这里删掉了res2，用覆盖res1来存了 

int main(){
	int m,n,k;
	cin>>m>>n>>k;
	rep(i,1,n){//o(n^2)找gcd 
		rep(j,1,m){
			if(!res[i][j]){
				for(int k=1;k*i<=n&&k*j<=m;k++){
					res[i*k][j*k] = k; 
					a[i*k][j*k] = i*j*k;
				}
			}
		}
	}
	deque<node> dq;//每行进行单调队列
	//本来想建maxn个deque的，但是这里发现可以滚动
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!dq.empty()&&dq.front().order<j-k+1) dq.pop_front();
			while(!dq.empty()&&a[i][j]>=dq.back().data) dq.pop_back();
			dq.push_back(node{a[i][j],j});
			res[i][j] = dq.front().data;
		}
		dq.clear();
	}
	//对k开始的每列进行单调队列 
	for(int j=k;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(!dq.empty()&&dq.front().order<i-k+1) dq.pop_front();
			while(!dq.empty()&&dq.back().data<=res[i][j]) dq.pop_back();
			dq.push_back(node{res[i][j],i});
			res[i][j] = dq.front().data;
		}
		dq.clear();
	}
	ll msum = 0;
	for(int i=k;i<=n;i++){
		for(int j=k;j<=m;j++){
			msum+=res[i][j];
		}
	}
	cout<<msum<<endl;
}
//这题有个小故事，原本有4个5k*5k的数组和两个deque
//内存超限 
//后来删到了一个deque和两个5k*5k的才过了 
//wls说，stl是非常占用内存，而且deque是速度比较慢的 
