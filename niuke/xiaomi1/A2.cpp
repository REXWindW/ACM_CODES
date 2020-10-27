#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
template<class T>inline void read(T &x){x=0;char o,f=1;while(o=getchar(),o<48)if(o==45)f=-f;do x=(x<<3)+(x<<1)+(o^48);while(o=getchar(),o>47);x*=f;}
const int MAXN = 2e5+5;;
const int NUM = 1e7+5;
#define ll long long
int n;
int cnt[NUM]={0};
int lc[NUM]={0};
int a[MAXN];
int main(){
    read(n);
    int maxx = 0;
    int maxnum = 0;
    rep(i,1,n){
        read(a[i]);
        cnt[a[i]]++;
        maxx = max(maxx,cnt[a[i]]);
        maxnum = max(maxnum,a[i]);
    }
    sort(a+1,a+1+n);
    n = unique(a+1,a+1+n)-(a+1);
    lc[1] = cnt[1];//lcm=1的集合最大数量
    rep(i,1,n){
        lc[a[i]] = cnt[a[i]];
        int sqr = sqrt(a[i]);//更正错误
        if(sqr<i){
            rep(j,1,sqr){//更正
                if(j!=a[i]&&a[i]%j==0){
                    lc[a[i]] = max(lc[j]+cnt[a[i]],lc[a[i]]);
                    if(j!=1) lc[a[i]] =max(lc[a[i]/j]+cnt[a[i]],lc[a[i]]);
                    maxx = max(maxx,lc[a[i]]);
                }
            }
        }
        else{
            rep(jj,1,i-1){
                int j = a[jj];
                if(j!=a[i]&&a[i]%j==0){
                    lc[a[i]] = max(lc[j]+cnt[a[i]],lc[a[i]]);
                    maxx = max(maxx,lc[a[i]]);
                }
            }
        }
    }
    cout<<maxx<<endl;
    /*
    rep(i,1,maxnum){
        cout<<cnt[i]<<' ';
    }
    cout<<endl;
    rep(i,1,maxnum){
        cout<<lc[i]<<' ';
    }
    cout<<endl;
    */
}