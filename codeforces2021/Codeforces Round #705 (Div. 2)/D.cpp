#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f
ll gcd(ll a,ll b){ while(b^=a^=b^=a%=b); return a; }

const int med = 1e9+7;
const int MAXN = 2e5+5;
bool prim[MAXN];
vector<int> prm;
map<int,int> mp[MAXN];//第i个位置有几个质数j
map<int,int> cp[MAXN];//质数j在几个位置出现了i次？
void ass(){
    rep(i,2,MAXN-5){
        if(prim[i]) continue;
        prm.push_back(i);
        for(int j=i*2;j<=MAXN-5;j+=i)
            prim[j]=1;
    }
    //cout<<primm.size()<<endl;
}
int n,q;
ll gcdd;
int hc;
void solve(){
    gcdd = 1;
    cin>>n>>q;
    rep(i,1,n){
        cin>>hc;
        int sqr = sqrt(hc);
        for(int j=0;prm[j]<=sqr;j++){
            while(hc%prm[j]==0){
                hc/=prm[j];
                mp[i][prm[j]]++;
                cp[prm[j]][ mp[i][prm[j]] ]++;
                if(cp[prm[j]][ mp[i][prm[j]] ]==n)gcdd*=prm[j];
            }
        }
        if(hc!=1){
            mp[i][hc]++;
            cp[hc][mp[i][hc]]++;
            if(cp[hc][mp[i][hc]]==n) gcdd*=hc;
        }
    }
    int pos,x;
    int sqr;
    while(q--){
        cin>>pos>>x;
        sqr = sqrt(x);
        for(int j=0;prm[j]<=sqr;j++){
            while(x%prm[j]==0){
                x/=prm[j];
                mp[pos][prm[j]]++;
                cp[prm[j]][ mp[pos][prm[j]] ]++;
                if(cp[prm[j]][ mp[pos][prm[j]] ]==n)gcdd=gcdd*prm[j]%med;
            }                
            
        }
        if(x!=1){
            mp[pos][x]++;
            cp[x][mp[pos][x]]++;
            if(cp[x][mp[pos][x]]==n)gcdd=gcdd*x%med;
        }
        cout<<gcdd<<endl;
    }
}

int main(){
    ass();
    solve();
}