#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }
const int MAXN = 114514;
int a[MAXN];
int b1[MAXN],b2[MAXN];
int c1[MAXN],c2[MAXN];
int n;
char hc;
void solve(){
    cin>>n;
    repb(i,n,1){
        cin>>hc;
        a[i] = hc-'0';
    }
    int mid = n/2;//最好的长度
    //还要让
    int flagb=0,flagc=0;
    repb(i,mid,1){
        if(a[i]!=0){
            flagb=i;break;
        }
    }//左边找
    rep(i,mid+1,n-1){
        if(a[i]!=0){
            flagc=i;break;
        }
    }//右边找
    if(flagb){
        rep(i,1,flagb)
            b1[i]=a[i];
        rep(i,1,n-flagb)
            b2[i]=a[flagb+i];
        rep(i,1,n){//相加
            b1[i]+=b2[i];
            if(b1[i]>9){
                b1[i]%=10;
                b1[i+1]++;
            }
        }
    }
    if(flagc){
        rep(i,1,flagc)
            c1[i]=a[i];
        rep(i,1,n-flagc)
            c2[i]=a[flagc+i];
        rep(i,1,n){//相加
            c1[i]+=c2[i];
            if(c1[i]>9){
                c1[i]%=10;
                c1[i+1]++;
            }
        }
    }
    if(!flagc){
        int px = n;
        while(b1[px]==0) px--;
        repb(i,px,1) cout<<b1[i];
        cout<<endl;
    }
    else if(!flagb){
        int px = n;
        while(c1[px]==0) px--;
        repb(i,px,1) cout<<c1[i];
        cout<<endl;
    }
    else{
        int flag = 0;
        repb(i,n,1){
            if(b1[i]<c1[i]){flag=1;break;}
            if(b1[i]>c1[i]){flag=-1;break;}
        }
        if(flag==1){
            int px = n;
            while(b1[px]==0) px--;
            repb(i,px,1) cout<<b1[i];
            cout<<endl;
        }
        else{
            int px = n;
            while(c1[px]==0) px--;
            repb(i,px,1) cout<<c1[i];
            cout<<endl;
        }
    }
}

int main(){
    solve();
}