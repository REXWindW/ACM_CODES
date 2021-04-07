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
int n;
const int MAXN = 114514*2;
int a[MAXN];

void solve(){
    cin>>n;
    a[0] = 0;
    int maxp = 0;
    rep(i,1,n){
        cin>>a[i];
        if(a[i]>a[maxp]){
            maxp = i;
        }
    }
    //cout<<"MAXP"<<maxp<<endl;
    int l=maxp-1,r=maxp+1;
    int now = a[maxp];
    while(l>=1||r<=n){
        if(l>=1&&r<=n){
            if(a[l]>=a[r]){
                if(a[l]<now){
                    now = a[l];
                    l--;
                }
                else break;
            }
            else{
                if(a[r]<now){
                    now = a[r];
                    r++;
                }
                else break;
            }
        }
        else if(l>=1){
            if(a[l]<now){
                now = a[l];
                l--;
            }
            else break;
        }
        else if(r<=n){
            if(a[r]<now){
                now = a[r];
                r++;
            }
            else break;
        }
    }
    //cout<<l<<' '<<r<<endl;
    if(r==n+1&&l==0){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}

int main(){
    solve();
}