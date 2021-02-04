#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repb(i,a,b) for(int i=(a);i>=(b);i--)
#define INF 0x3f3f3f3f

string s;
typedef pair<int,int> pii;
#define ft first
#define sd second
#define mkp make_pair
int cnt[66];
void solve(){
    cin>>s;
    rep(i,0,26) cnt[i]=0;
    int siz = s.length();
    rep(i,0,siz-1){
        cnt[s[i]-'a']++;
    }
    vector<pii> p;
    rep(i,0,26){
        if(cnt[i]) p.push_back(mkp(i,cnt[i]));
    }
    sort(p.begin(),p.end());
    if(p.size()==3){
        if(p[0].ft+1==p[1].ft&&p[1].ft+1==p[2].ft){
            cout<<"No answer"<<endl;
            return;
        }
        if(p[0].ft+1==p[1].ft){//(1,2) 1 3 2
            rep(j,1,p[0].sd) cout<<(char)(p[0].ft+'a');
            rep(j,1,p[2].sd) cout<<(char)(p[2].ft+'a');
            rep(j,1,p[1].sd) cout<<(char)(p[1].ft+'a');
        }
        else{//(2,3) 2 1 3
            rep(j,1,p[1].sd) cout<<(char)(p[1].ft+'a');
            rep(j,1,p[0].sd) cout<<(char)(p[0].ft+'a');
            rep(j,1,p[2].sd) cout<<(char)(p[2].ft+'a');
        }
        cout<<endl;
        return;
    }
    if(p.size()==2){
        if(p[0].ft+1==p[1].ft){
            cout<<"No answer"<<endl;
            return;
        }
    }
    siz = p.size();
    int typ;
    if(siz%2)typ=0;
    else typ=1;

    for(int i=typ;i<siz;i+=2){
        rep(j,1,p[i].sd) cout<<(char)(p[i].ft+'a');
    }
    for(int i=typ^1;i<siz;i+=2){
        rep(j,1,p[i].sd) cout<<(char)(p[i].ft+'a');
    }
    cout<<endl;
}

int main(){
    int z;
    cin>>z;
    while(z--) solve();
}