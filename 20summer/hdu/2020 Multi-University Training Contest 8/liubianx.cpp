#include<bits/stdc++.h>
  
using namespace std;

#define rep(a,b,c)for(int a=(b);a<(c);++a)
#define dep(a,b,c)for(int a=(b);a>=(c);--a)
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int>Pii;
typedef pair<ll,ll>Pll;
typedef pair<double,double> Pdd;
const int inf=0x3f3f3f3f;
const int mod=998244353;
const int inv4=748683265;
const int N=400007;

int t,n,k;
ll l[100007],r[100007];

int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==2){
            cout<<"313256"<<endl;
            continue;
        }
        if(n==3){
            cout<<"453213162651546435"<<endl;
            continue;
        }
        if(n%2==0){
            cout<<"313256";
            for(int i=1;i<=n/2-1;++i){
                cout<<"5151";
                for(int j=1;j<=i*4-1;++j){
                    if(j%2==1)cout<<2;else cout<<6;
                }
                for(int j=1;j<=4;++j){
                    for(int k=1;k<=i*4+1;++k){
                        if(k%2==1)cout<<j+2;
                        else cout<<j;
                    }
                }
                for(int j=1;j<=i*4-2;++j){
                    if(j%2==1)cout<<1;else cout<<5;
                }
                cout<<6;
            }
            cout<<endl;
        }else{
            cout<<"453213162651546435";
            for(int i=1;i<=n/2-1;++i){
                cout<<"651";
                for(int j=1;j<=i*4+1;++j){
                    if(j%2==1)cout<<2;else cout<<6;
                }
                cout<<endl;
                for(int j=1;j<=4;++j){
                    for(int k=1;k<=i*4+3;++k){
                        if(k%2==1)cout<<j+2;
                        else cout<<j;
                    }
                    cout<<endl; 
                }
                for(int j=1;j<=i*4+2;++j){
                    if(j%2==1)cout<<1;else cout<<5;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}

