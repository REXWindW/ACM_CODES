#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
map<string,int> mp;//身份证-》上次领取日期
map<string,bool> mp2;
int d,p;
const int MAXN = 114514;
int gettime(int mm,int ss){
    return mm*60-ss;
}
struct peo{
    string nam,sfz;
    int num;
    bool cond;
    int tmm,tss;
}a[MAXN];
vector<peo> vec;
bool cmp(peo a,peo b){
    int at = gettime(a.tmm,a.tss);
    int bt = gettime(b.tmm,b.tss);
       if(at<bt) return 1;
    else if(at==bt){
        return a.num<b.num;
    }
    return 0;
}
bool bing[MAXN];
bool OK(string s){
    int siz = s.size();
    if(siz!=18) return 0;
    rep(i,0,siz-1){
        if(!isdigit(s[i])) return 0;
    }
    return 1;
}
void solve(){
    cin>>d>>p;
    int ti,si;
    rep(k,1,d){
        //cout<<"k="<<k<<endl;
        cin>>ti>>si;
        char hc;
        rep(i,1,ti){
            cin>>a[i].nam>>a[i].sfz>>a[i].cond;
            cin>>a[i].tmm>>hc>>a[i].tss;
            a[i].num = i;
            if(si==0) continue;
            sort(a+1,a+1+ti,cmp);
            if(OK(a[i].sfz)){
                //记录病人
                if(a[i].cond==1&&mp2[a[i].sfz]==0){
                    mp2[a[i].sfz] = 1;
                    vec.push_back(
                        peo{a[i].nam,a[i].sfz,a[i].num,a[i].cond,
                            a[i].tmm,a[i].tss}
                        );
                }
                if(mp[a[i].sfz]==0||k-mp[a[i].sfz]>p){
                    mp[a[i].sfz] = k;
                    cout<<a[i].nam<<' '<<a[i].sfz<<endl;
                    si--;
                }
            }
        }
    }
    for(auto pp:vec){
        cout<<pp.nam<<' '<<pp.sfz<<endl;
    }
}
int main(){
    solve();
}