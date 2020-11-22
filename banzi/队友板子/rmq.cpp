#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
#include<utility>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<functional>
#include<cctype>
 
using namespace std;

const int N=100007;

int t,n,a[N],q,st[N][17],lg[N];

void init_st(){
    for(int i=1;i<=n;++i){
        st[i][0]=i;
    }
    for(int j=1;j<17;++j){
        for(int i=1;i<=n;++i){
            if(a[st[i][j-1]]>a[st[i+(1<<(j-1))][j-1]])st[i][j]=st[i][j-1];
            else st[i][j]=st[i+(1<<(j-1))][j-1];
        }
    }
}

int rmq(int l,int r){
    int log=lg[r-l+1];
    return max(a[st[l][log]],a[st[r-(1<<log)+1][log]]);
}

int main(){
    ios::sync_with_stdio(false);
    for(int i=2;i<N;++i){
        lg[i]=lg[i>>1]+1;
    }
    cin>>t;
    while(t--){
        cin>>n;
        memset(a,0,sizeof(a));
        memset(st,0,sizeof(st));
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        init_st();
        cin>>q;
        for(int i=0;i<q;++i){
            int l,r;
            cin>>l>>r;
            cout<<rmq(l,r)<<endl;
        }
    }
    return 0;
}
