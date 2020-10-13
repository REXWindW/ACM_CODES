#include<bits/stdc++.h>
  
using namespace std;

#define rep(a,b,c) for(int a=(b);a<(c);++a)
#define dep(a,b,c) for(int a=(b);a>=(c);--a)
#define sf scanf
#define pf printf
#define fi first 
#define se second
typedef long long ll;
typedef pair<int, int>Pii;
typedef pair<double, double> Pdd;
const int inf=0x3f3f3f3f;
const int mod=998244353;

int t,n,p,a[100007],pos[100007];

int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>p;
        for(int i=1;i<=n;++i){
            cin>>a[i];
            a[i]=(a[i]+a[i-1])%p;
        }
        /*for(int i=0;i<=n;++i){
            cout<<a[i]<<' ';
        }
        cout<<endl;*/
        vector<Pii> v;
        for(int i=1;i<=p;++i){
            pos[i]=-1;
        }
        for(int i=1;i<=n;++i){
            if(pos[a[i]]!=-1){
                v.push_back(make_pair(i,pos[a[i]]));
            }
            pos[a[i]]=i;
        }
        sort(v.begin(),v.end());
        /*for(int i=0;i<v.size();++i){
            cout<<v[i].se<<' '<<v[i].fi<<endl;
        }*/
        int ans=0,l=-1;
        for(int i=0;i<v.size();++i){
            if(l<=v[i].se){
                ans++;
                l=v[i].fi;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
