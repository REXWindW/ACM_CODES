#include<bits/stdc++.h>
  
using namespace std;

#define ft first 
#define sd second
#define mp make_pair
typedef long long ll;
typedef pair<int, int>Pii;
typedef pair<double, double> Pdd;
const int inf=0x3f3f3f3f;
const int mod=1e9+9;
const int  e  = 1e9;
int n;

ll randd(){
	return (ll)rand()*10000+rand();
}

int main(){
    srand(time(0));
    freopen("data.in","w",stdout);
    map<Pii,bool> vis;
    cin>>n;
    cout<<1<<endl<<n<<endl;
    for(int i=0;i<n;++i){
        int x=randd()% e ,y=randd()% e ;
        while(vis[mp(x,y)]){
            x=randd()% e ,y=randd()% e ;
        }
        vis[mp(x,y)]=1;
        cout<<x<<' '<<y<<endl;
    }
    return 0;
}
