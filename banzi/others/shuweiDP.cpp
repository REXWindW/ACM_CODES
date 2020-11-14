#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int l,r;
const int MAXN = 25;
int dp[MAXN][2];//第二维记录前面一个是否为2
int a[MAXN];
int n,m;

int dfs(int pos,bool stat,int pre,bool limit){
    //limit记录之前是否都在上界，state记录之前的是不是6(记忆化作第二维)，pre记录上一个数字
	if(pos==-1) return 1;
	if(!limit&&dp[pos][stat]!=-1) return dp[pos][stat];
    int up = limit?a[pos]:9;//如果前面的都在上界则只能到a[pos]
    int ans = 0;
    for(int i=0;i<=up;i++){
        if(pre==6&&i==2) continue;//62的情况
        if(i==4) continue;
		ans += dfs(pos-1,i==6,i,limit&&i==a[pos]);
    }
	if(!limit) dp[pos][stat] = ans;
    return ans;
}

int solve(int x){
	//先按位转化到数组
    int px = 0;
    while(x){
		a[px++] = x%10;
        x/=10;
    }
    memset(dp,-1,sizeof(dp));//清空记忆化数组
    return dfs(px-1,0,-1,1);
}

int main(){
	while(cin>>l>>r){
        if(l==0&&r==0) break;
    	//cout<<solve(r)<<' '<<solve(l-1)<<endl;
        cout<<solve(r)-solve(l-1)<<endl;
    }
}
//HDOJ2089 不要62