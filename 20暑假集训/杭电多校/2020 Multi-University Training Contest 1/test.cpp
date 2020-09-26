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
#include<complex>
 
using namespace std;

#define ft first 
#define sd second
typedef long long ll;
typedef pair<ll, ll>Pii;
typedef pair<double, double> Pdd;
const int inf=0x3f3f3f3f;
const int mod=998244353;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}

int t,n,link[100007];
Pii x[100007];
double pos[100007];
bool chongfu[100007];

const double eps = 0.0001;

int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        map<Pii,int> M;
        vector<Pii> v;
        for(int i=0;i<n;++i){
        	chongfu[i] = 0;
            cin>>x[i].ft>>x[i].sd;
            M[x[i]]++;
        }
        for(int i=0;i<n;++i){
            if(M[x[i]]==1)v.push_back(x[i]);
            else if(M[x[i]]>1&&M[x[i]]!=-1){
				M[x[i]]=-1;
				v.push_back(x[i]);
				chongfu[v.size()-1]=1;
			}
        }
        if(v.size()==0){
            cout<<0<<endl;
            continue;
        }
        sort(v.begin(),v.end(),greater<Pii>());
        int cnt=1,maxa=v[0].sd;
        link[0]=0;
        for(int i=0;i<v.size();++i){
            pos[i]=0;
            link[i]=0;
        }
        for(int i=1;i<v.size();++i){
            /*for(int i=0;i<cnt;++i){
                cout<<link[i]<<' ';
            }
            cout<<endl;
            for(int i=0;i<cnt;++i){
                cout<<pos[i]<<' ';
            }
            cout<<endl;*/
            if(v[i].ft==v[i-1].ft)continue;
            if(v[i].sd<=maxa)continue;
            maxa=v[i].sd;
            int l=0,r=cnt,mid;
            while(r-l>1){
                mid=(l+r)/2;
                double y1=v[link[mid]].ft+v[link[mid]].sd*pos[mid]*pos[mid]/2.0;
                double y2=v[i].ft+v[i].sd*pos[mid]*pos[mid]/2.0;
                if(fabs(y2-y1)<eps){
                	l=mid-1;
                	r=mid;
                	break;
				}
                if(y1<=y2)r=mid;
                else l=mid;
            }
            //cout<<"i"<<i<<' '<<r<<endl;
            pos[r]=sqrt(2.0*double(v[link[l]].ft-v[i].ft)/double(v[i].sd-v[link[l]].sd));
            link[r]=i;
            cnt=r+1;
        }
        int countt = 0;
        for(int i=1;i<=cnt;i++){
        	if(!chongfu[link[i]])countt++;
		}
        /*
        cout<<"show jiaodian"<<endl;
		for(int i=1;i<=cnt;i++){
			cout<<'('<<pos[i]<<','<<v[link[i]].ft+v[link[i]].sd*pos[i]*pos[i]/2.0<<')';
		}	
		cout<<endl;
		*/
        cout<<countt<<endl;
    }
    return 0;
}   
