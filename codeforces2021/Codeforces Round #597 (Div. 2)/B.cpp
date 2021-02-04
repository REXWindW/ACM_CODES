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
int a[5];
char alp[5]={'\0','R','P','S'};
int n;
int res;
int ress[114514];
void solve(){
    cin>>n;
    cin>>a[1]>>a[2]>>a[3];
    char hc;
    res=0;
    rep(i,1,n){
        cin>>hc;
        if(hc=='R'){
            if(a[2]){
                a[2]--;
                ress[i]=2;
                res++;
            }
            else{
                ress[i]=0;
            }
        }
        else if(hc=='P'){
            if(a[3]){
                a[3]--;
                ress[i]=3;
                res++;
            }
            else{
                ress[i]=0;
            }
        }
        else if(hc=='S'){
            if(a[1]){
                a[1]--;
                ress[i]=1;
                res++;
            }
            else{
                ress[i]=0;
            }
        }
    }
    if(res>=(n+1)/2){
        cout<<"YES"<<endl;
        rep(i,1,n){
            if(ress[i]==1) cout<<'R';
            if(ress[i]==2) cout<<"P";
            if(ress[i]==3) cout<<"S";
            if(ress[i]==0){
                rep(j,1,3){
                    if(a[j]){
                        cout<<alp[j];
                        a[j]--;
                        break;
                    }
                }
            }
        }
        cout<<endl;
    }
    else cout<<"NO"<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}