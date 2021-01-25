#include<iostream>
using namespace std;
#define ll long long
const int MAXN = 114514;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
ll a[MAXN];
ll dp[MAXN][2];
int n;
int main(){
	while(cin>>n){
		dp[0][0]=dp[0][1]=0;
		rep(i,1,n){
			cin>>a[i];
			dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
			dp[i][1] = dp[i-1][0] + a[i];
		}
		cout<<max(dp[n][0],dp[n][1])<<endl;
	}
}