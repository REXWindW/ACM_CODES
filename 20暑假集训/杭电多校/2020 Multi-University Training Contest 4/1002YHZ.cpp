#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define m(a) memset(a,0,sizeof(a))
int t;
int a[1005];
int d[1005];
int f[1005];
int main(){
    cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>d[i];
            if((100-a[i])%a[i]==0){
                f[i]=(100-a[i])/a[i]*d[i];
            }
            else{
                f[i]=(100-a[i])/a[i]*d[i]+d[i];
            }
            //cout<<f[i]<<endl;
        }
        sort(f+1,f+n+1);
        int sum=0;
        for(int i=1;i<=n;i++){
            if(f[i]!=f[1]){
                break;
            }
            else sum++;
        }
        //cout<<sum<<endl;
        double gailv=1.000*sum/n*0.500+(n-sum)*1.000/n;
        printf("%.8lf\n",gailv);
    }
}
