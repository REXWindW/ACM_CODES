#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int MAXN = 2e5+5;
#define ll long long
int a[MAXN];
int n;
ll sum[MAXN][2];

int main(){
    cin>>n;
    rep(i,1,n) cin>>a[i];
    sum[0][0]=sum[1][1]=0;
    rep(i,1,n){
        sum[i][0]=sum[i-1][0];
        sum[i][1]=sum[i-1][1];
        sum[i][i%2] += a[i];//奇偶前缀和
    }
    ll maxx = 0;
    rep(i,1,n){//枚举哪个地方出现连续2
        maxx = max(maxx,sum[i][i%2]+(sum[n][(i+1)%2]-sum[i][(i+1)%2]));
    }
    cout<<maxx<<endl;
}