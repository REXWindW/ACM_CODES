#include<iostream>
#include<string>
#include<cstring>

using namespace std;

typedef long long ll;
ll a[50005];
int n,t,p,k;
string str;

int lowbit(int x){
    return x&(-x);
}

void insert(int i,int k){
    while(i<=n){
        a[i]+=k;
        i+=lowbit(i);
    }
}

ll getsum(int n){
    ll sum=0;
    while(n){
        sum+=a[n];
        n-=lowbit(n);
    }
    return sum;
} 

int main(){
    cin>>t;
    for(int i=1;i<=t;++i){
        cout<<"Case "<<i<<":"<<endl;
        memset(a,0,sizeof(a));
        cin>>n;
        for(int j=1;j<=n;++j){
            cin>>k;
            insert(j,k);
        }
        while(1){
            cin>>str;
            if(str=="End")break;
            cin>>p>>k;
            if(str=="Add")insert(p,k);
            else if(str=="Sub")insert(p,-k);
            else cout<<getsum(k)-getsum(p-1)<<endl;
        }
    }
    return 0;
}