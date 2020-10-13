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

int t,n,nexts[5000007];

char str[5000007],p[5000007],s[5000007];

void kmp_pre(char x[],int m){
    int i,j;
    j=nexts[0]=-1;
    i=0;
    while(i<m){
        while(-1!=j&&x[i]!=x[j])j=nexts[j];
        nexts[++i]=++j;
    }
}

bool kmp(char x[],char y[],int m,int n){
    int i,j;
    kmp_pre(x,m);
    i=j=0;
    while(i<n){
        while(-1!=j&&y[i]!=x[j])j=nexts[j];
        i++;j++;
        if(j>=m){
            return 1;
            j=nexts[j];
        }
    }
    return 0;
}

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",str);
        if(n==1){
            printf("No\n");
            continue;
        }
        vector<int> v;
        for(int i=2;i<=sqrt(n);++i){
            if(n%i==0){
                v.push_back(i);
                v.push_back(n/i);
            }
        }
        v.push_back(1);
        bool flag=0;
        for(int i=0;i<v.size();++i){
            for(int j=0;j<v[i];++j){
                p[j]=str[j];
            }
            p[v[i]]=0;
            bool flag2=1;
            for(int j=v[i];j<n;j+=v[i]){
                int pos=0;
                for(int k=j;k<j+v[i];++k){
                    s[pos++]=str[k];
                }
                for(int k=j;k<j+v[i];++k){
                    s[pos++]=str[k];
                }
                s[pos]=0;
                if(kmp(p,s,v[i],v[i]*2)==0){
                    flag2=0;
                    break;
                }
            }
            if(flag2){
                flag=1;
                break;
            }
        }
        if(flag)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
