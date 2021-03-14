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
const int MAXN = 2077;
int n,k,ress;
int a[MAXN][MAXN];//B0W1
int b[MAXN][MAXN];//差分数组
int c[MAXN][MAXN];
int maxx1[MAXN],minn1[MAXN];//最大最小位置
int maxx2[MAXN],minn2[MAXN];
void add(int x1,int y1,int x2,int y2){
    b[x1][y1]++;
    b[x1][y2+1]--;
    b[x2+1][y1]--;
    b[x2+1][y2+1]++;
}
void solve(){
    cin>>n>>k;    
    char hc;
    rep(i,1,n){
        rep(j,1,n){
            cin>>hc;
            a[i][j] = (hc=='W');
        }
    }
    int x1,x2,y1,y2;
    rep(i,1,n){//hang
        maxx1[i]=-1,minn1[i]=INF;
        rep(j,1,n){
            if(a[i][j]==0){
                maxx1[i] = max(maxx1[i],j);
                minn1[i] = min(minn1[i],j);
            }   
        }
        if(maxx1[i]-minn1[i]>=k){
            continue;
        }
        if(maxx1[i]==-1){
            ress++;
            continue;
        }
        y1 = max(1,i-k+1);
        y2 = i;
        x1 = max(1,maxx1[i]-k+1);
        x2 = minn1[i];
        add(x1,y1,x2,y2);
    }
    rep(j,1,n){//lie
        maxx2[j]=-1,minn2[j]=INF;
        rep(i,1,n){
            if(a[i][j]==0){
                maxx2[j] = max(maxx2[j],i);
                minn2[j] = min(minn2[j],i);
            } 
        }
        if(maxx2[j]-minn2[j]>=k){
            continue;
        }
        if(maxx2[j]==-1){
            ress++;
            continue;
        }
        x1 = max(1,j-k+1);
        x2 = j;
        y1 = max(1,maxx2[j]-k+1);
        y2 = minn2[j];
        add(x1,y1,x2,y2);
    }
    int res = 0;
    //cout<<"checkc"<<endl;
    rep(i,1,n){
        rep(j,1,n){
            c[i][j] = c[i-1][j]+c[i][j-1]-c[i-1][j-1]+b[i][j];
            //cout<<c[i][j];
            res = max(res,c[i][j]);
        }
        //cout<<endl;
    }
    //cout<<"ress"<<ress<<endl;
    //cout<<"res"<<res<<endl;
    cout<<ress+res<<endl;
}

int main(){
    solve();
}