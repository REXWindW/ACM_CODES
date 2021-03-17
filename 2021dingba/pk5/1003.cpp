#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)

ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 3004;
ll LINF = 1ll<<60;
ll dp[MAXN][MAXN][2];
int d[MAXN],t[MAXN];
ll sumf[MAXN];//前缀和
ll sumt[MAXN];
int n,m;
inline ll qzh(int l,int r){return sumf[r]-sumf[l-1];}
inline ll qzt(int l,int r){return sumt[r]-sumt[l-1];}
inline ll cal(int pos,int fam){
    dp[pos][pos][0]=dp[pos][pos][1] = 0;//记录最小时间
    int mi=pos,mj=pos,tmp;
    repb(i,pos,1){
        rep(j,pos,n){
            if(i==j) continue;
            dp[i][j][0]=dp[i][j][1] = LINF;
            if(i<pos&&fam-d[pos]+qzh(i+1,j)>=d[i]){
                tmp = j-1>=pos?t[pos]:0;
                //cout<<"0check"<<dp[i+1][j][1]+qzt(i,j-1)<<' '<<dp[i+1][j][0]+t[i]<<endl;
                dp[i][j][0] = min(dp[i+1][j][1]+qzt(i,j-1)-tmp,dp[i+1][j][0]+t[i]);
            }
            if(j>pos&&fam-d[pos]+qzh(i,j-1)>=d[j]){
                tmp = i+1<=pos?t[pos]:0;
                //cout<<"1check"<<dp[i][j-1][1]+t[j]<<' '<<dp[i][j-1][0]+qzt(i+1,j)-tmp<<endl;
                dp[i][j][1] = min(dp[i][j-1][1]+t[j],dp[i][j-1][0]+qzt(i+1,j)-tmp);
            }
            //cout<<"dp"<<i<<':'<<j<<':'<<dp[i][j][0]<<' '<<dp[i][j][1]<<endl;
            if(dp[i][j][0]<LINF||dp[i][j][1]<LINF){
                if(qzh(i,j)>qzh(mi,mj)){
                    mi = min(mi,i);mj = max(mj,j);
                }
            }
        }
    }
    return min(dp[mi][mj][0],dp[mi][mj][1]);
}
int main(){
    cin>>n>>m;
    sumf[0]=sumt[0]=0;
    rep(i,1,n){
        cin>>d[i];
        sumf[i] = sumf[i-1]+d[i];
    }
    rep(i,1,n){
        cin>>t[i];
        sumt[i] = sumt[i-1]+t[i];
    }
    int ps,fm;
    rep(i,1,m){
        cin>>ps>>fm;
        cout<<cal(ps,fm)<<endl;
    }
}