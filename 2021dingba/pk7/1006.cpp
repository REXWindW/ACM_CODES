#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 114514*10;
int n;
int a[MAXN];
//首先这个数字肯定不超过所有a中最大的
//6 7,7/2*2即可，有没有其他的情况？比如结果既不是2的倍数,也不是其中任何数？
//假设这种情况不存在？即一定是1，或者其中的某个数
//这个数，要么是中位数，要么是1！
void solve(){
    cin>>n;
    rep(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    //检验1的情况
    int tmp,cnt=0;
    int res = 0;
    rep(i,1,n){
        tmp = a[i];
        while(tmp>1){
            tmp>>=1;
            cnt++;
        }
    }
    res = cnt;
    //找中位数
    int to = a[(n+1)/2];//奇数偶数共有的中位数
    cnt = 0;
    rep(i,1,n){
        tmp = a[i];
        if(tmp>to){
            while(tmp>to){
                tmp>>=1;
                cnt++;
            }
        }
        else if(tmp<to){
            while(tmp<to){
                tmp<<=1;
                cnt++;
            }
        }
        if(tmp!=to){
            cnt = INF;break;
        }
    }
    //cout<<"cnt"<<cnt<<endl;
    res = min(res,cnt);
    if(n%2==0){//两个中位数的情况
        to = a[n/2+1];
        cnt = 0;
        rep(i,1,n){
            tmp = a[i];
            if(tmp>to){
                while(tmp>to){
                    tmp>>=1;
                    cnt++;
                }
            }
            else if(tmp<to){
                while(tmp<to){
                    tmp<<=1;
                    cnt++;
                }
            }
            if(tmp!=to){
                cnt = INF;break;
            }
        }
        res = min(res,cnt);
    }
    cout<<res<<endl;
}

int main(){
    solve();
}