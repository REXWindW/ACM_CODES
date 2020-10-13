#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define m(a) memset(a,0,sizeof(a))
int t;
int a[100005];
int b[100005];
int main(){
    scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        int l=INF,r=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            l=min(l,b[i]);
            r=max(r,b[i]);
            a[i]=b[i];
        }
        int mins=r;
        while(r>l){
        	//cout<<l<<' '<<r<<endl;
            int mid=(l+r)/2;
            for(int i=n;i>=2;i--){
                if(a[i]>mid){
                    a[i-1]+=(a[i]-mid);
                    a[i]=mid;
                }
            }
            //test
            for(int i=1;i<=n;i++) cout<<a[i]<<' ';
            cout<<endl;
            //cout<<a[1]<<' '<<mid<<endl;
            if(a[1]>mid){
                l=mid+1;
            }
            else{
            	r=mid;
            	mins = min(r,mins);
            }
            for(int i=1;i<=n;i++){
                a[i]=b[i];
            }
        }
        printf("%d\n",mins);
    }
}
/*
1
9
1 1 1 1 1 1 1 7 6
*/
