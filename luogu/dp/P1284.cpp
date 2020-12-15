#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
const int MAXN = 114;
int a[MAXN];
int tot,n;
bool dp[888][888];

inline ll cal(int a,int b,int c){
    double p = (double)(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c))*100;
}

inline bool judge(int a,int b,int c){
    if(a<b) swap(a,b);
    if(a<c) swap(a,c);
    return b+c>a;
}

int main(){
    cin>>n;
    tot = 0;
    rep(i,1,n){
        cin>>a[i];
        tot+=a[i];
    }
    int half = tot>>1;
    dp[0][0] = 1;//表示这个边是可能存在的
    rep(i,1,n){//枚举边
        repb(j,half,0){//这边有点类似背包，所以不能正着rep
            repb(k,j,0){
                if((j>=a[i]&&dp[j-a[i]][k])||(k>=a[i]&&dp[j][k-a[i]])) 
                    dp[j][k]=1;
            }
        }
    }
    ll res = -1;
    repb(i,half,0){
        repb(j,i,0){
            if(dp[i][j]&&judge(i,j,tot-i-j)){//如果可行
                res = max(res,cal(i,j,tot-i-j));
            }
        }
    }
    cout<<res<<endl;
}